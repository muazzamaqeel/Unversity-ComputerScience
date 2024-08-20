// Event listener for the Proceed button
document.getElementById('proceed-btn').addEventListener('click', function() {
    const userName = document.getElementById('full-name').value.trim();
    const userEmail = document.getElementById('university-email').value.trim();

    if (!userName || !userEmail) {
        alert("Please enter both your full name and university email.");
        return;
    }

    document.getElementById('user-info-form').style.display = 'none';
    document.getElementById('quiz-options').style.display = 'block';
});

// Event listener for Quiz Questions button
document.getElementById('quiz-btn').addEventListener('click', function() {
    document.getElementById('quiz-questions').style.display = 'block';
    document.getElementById('coding-questions').style.display = 'none';
    loadQuizQuestions();
});

// Event listener for Coding Questions button
document.getElementById('coding-btn').addEventListener('click', function() {
    document.getElementById('quiz-questions').style.display = 'none';
    document.getElementById('coding-questions').style.display = 'block';
    loadCodingQuestions();
});

// Fetch and display Quiz Questions
function loadQuizQuestions() {
    fetch('/api/questions')
        .then(response => response.json())
        .then(questions => {
            const container = document.getElementById('quiz-questions-container');
            container.innerHTML = '';
            questions.forEach((question, index) => {
                const questionElement = document.createElement('div');
                questionElement.className = 'question-block';
                questionElement.innerHTML = `
                    <p>${index + 1}. ${question.text}</p>
                    ${question.options.map(option => `
                        <label>
                            <input type="radio" name="question-${index}" value="${option}"> ${option}
                        </label>
                    `).join('<br>')}
                `;
                container.appendChild(questionElement);
            });
        })
        .catch(error => console.error('Error loading quiz questions:', error));
}

// Fetch and display Coding Questions
function loadCodingQuestions() {
    fetch('/api/coding-questions')
        .then(response => response.json())
        .then(questions => {
            const container = document.getElementById('coding-questions-container');
            container.innerHTML = '';
            questions.forEach((question, index) => {
                const questionElement = document.createElement('div');
                questionElement.className = 'question-block';
                questionElement.innerHTML = `
                    <p>${index + 1}. ${question.text}</p>
                    <textarea id="code-${index}" class="code-editor">// Your code here\n\n${question.template}</textarea>
                    <button class="btn compile-btn" data-index="${index}" data-answer="${question.answer}">Compile and Run</button>
                    <div id="result-${index}" class="result-container"></div>
                `;
                container.appendChild(questionElement);
            });

            // Attach event listeners for compile buttons
            document.querySelectorAll('.compile-btn').forEach(button => {
                button.addEventListener('click', function() {
                    const index = this.getAttribute('data-index');
                    const userCode = document.getElementById(`code-${index}`).value;
                    const expectedOutput = this.getAttribute('data-answer');
                    compileCode(userCode, expectedOutput, index);
                });
            });
        })
        .catch(error => console.error('Error loading coding questions:', error));
}

// Function to compile code and show the result
function compileCode(code, expectedOutput, index) {
    fetch('/api/compile', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ code, expectedOutput }),
    })
    .then(response => response.json())
    .then(result => {
        const resultContainer = document.getElementById(`result-${index}`);
        if (result.success) {
            if (result.isCorrect) {
                resultContainer.textContent = 'Correct Answer!';
                resultContainer.style.color = 'green';
            } else {
                resultContainer.textContent = `Incorrect Answer. Your output was: ${result.output}`;
                resultContainer.style.color = 'red';
            }
        } else {
            resultContainer.textContent = `Error: ${result.error}`;
            resultContainer.style.color = 'red';
        }
    })
    .catch(error => console.error('Error compiling code:', error));
}

// Function to handle quiz submission
document.getElementById('submit-quiz-btn').addEventListener('click', function() {
    const answers = [];
    const userName = document.getElementById('full-name').value;
    const userEmail = document.getElementById('university-email').value;

    document.querySelectorAll('[name^="question-"]').forEach((input, index) => {
        if (input.checked) {
            answers.push(input.value);
        } else if (!answers[index]) {
            answers.push(null);
        }
    });

    fetch('/api/submit-quiz', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ userName, userEmail, answers }),
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            alert(data.message);
        } else {
            alert('Error submitting quiz: ' + data.message);
        }
    })
    .catch(error => console.error('Error submitting quiz:', error));
});
