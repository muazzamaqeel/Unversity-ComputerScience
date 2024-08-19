document.addEventListener('DOMContentLoaded', function() {
    const questionsTabButton = document.querySelector('.tab-button:first-child');
    const codingTabButton = document.querySelector('.tab-button:last-child');

    const questionsTab = document.getElementById('questions-tab');
    const codingTab = document.getElementById('coding-tab');

    // Set the default tab to "Quiz Questions"
    showTab('questions-tab');

    // Event listeners for tab buttons
    questionsTabButton.addEventListener('click', function() {
        showTab('questions-tab');
    });

    codingTabButton.addEventListener('click', function() {
        showTab('coding-tab');
    });

    function showTab(tabName) {
        // Hide both tabs initially
        questionsTab.style.display = 'none';
        codingTab.style.display = 'none';

        // Show the selected tab
        document.getElementById(tabName).style.display = 'block';
    }

    // Fetch and display quiz questions
    fetch('http://localhost:5000/api/questions')
        .then(response => response.json())
        .then(questions => {
            const questionsContainer = document.getElementById('questions-container');
            if (questions.length === 0) {
                questionsContainer.innerHTML = '<p>No questions available.</p>';
                return;
            }

            questions.forEach(question => {
                const questionDiv = document.createElement('div');
                questionDiv.className = 'question';

                const questionTitle = document.createElement('h3');
                questionTitle.textContent = question.text;
                questionDiv.appendChild(questionTitle);

                const optionsList = document.createElement('ul');

                question.options.forEach((option, index) => {
                    const optionItem = document.createElement('li');

                    const optionInput = document.createElement('input');
                    optionInput.type = 'radio';
                    optionInput.name = `question-${question.id}`;
                    optionInput.value = option;
                    optionInput.id = `question-${question.id}-option-${index}`;

                    const optionLabel = document.createElement('label');
                    optionLabel.setAttribute('for', optionInput.id);
                    optionLabel.textContent = option;

                    optionItem.appendChild(optionInput);
                    optionItem.appendChild(optionLabel);
                    optionsList.appendChild(optionItem);
                });

                questionDiv.appendChild(optionsList);
                questionsContainer.appendChild(questionDiv);
            });
        })
        .catch(error => {
            console.error('Error fetching questions:', error);
            const questionsContainer = document.getElementById('questions-container');
            questionsContainer.innerHTML = '<p>Error loading questions.</p>';
        });

    // Fetch and display coding questions
    fetch('http://localhost:5000/api/coding-questions')
        .then(response => response.json())
        .then(codingQuestions => {
            const codingQuestionsContainer = document.getElementById('coding-questions-container');
            if (codingQuestions.length === 0) {
                codingQuestionsContainer.innerHTML = '<p>No coding questions available.</p>';
                return;
            }

            codingQuestions.forEach(question => {
                const codingQuestionDiv = document.createElement('div');
                codingQuestionDiv.className = 'coding-question';

                const questionTitle = document.createElement('h3');
                questionTitle.textContent = question.text;
                codingQuestionDiv.appendChild(questionTitle);

                const defaultCode = `#include <iostream>\nusing namespace std;\n\nint main() {\n    cout << "Hello, World!";\n    return 0;\n}`;
                
                const codeEditor = document.createElement('textarea');
                codeEditor.value = defaultCode; // Set default code
                codingQuestionDiv.appendChild(codeEditor);

                const compileBtn = document.createElement('button');
                compileBtn.id = 'compile-btn';
                compileBtn.textContent = 'Compile and Run';
                compileBtn.className = 'action-button';
                compileBtn.addEventListener('click', function() {
                    const userCode = codeEditor.value.trim();
                    fetch('http://localhost:5000/api/compile', {
                        method: 'POST',
                        headers: {
                            'Content-Type': 'application/json'
                        },
                        body: JSON.stringify({ code: userCode, expectedOutput: question.answer })
                    })
                    .then(response => response.json())
                    .then(data => {
                        if (data.success) {
                            if (data.correct) {
                                alert('Correct Answer!');
                            } else {
                                alert('Incorrect Answer. Your output was: ' + data.output);
                            }
                        } else {
                            alert('Compilation Error: ' + data.error);
                        }
                    })
                    .catch(error => {
                        console.error('Error:', error);
                        alert('An error occurred during compilation.');
                    });
                });
                codingQuestionDiv.appendChild(compileBtn);

                codingQuestionsContainer.appendChild(codingQuestionDiv);
            });
        })
        .catch(error => {
            console.error('Error fetching coding questions:', error);
            const codingQuestionsContainer = document.getElementById('coding-questions-container');
            codingQuestionsContainer.innerHTML = '<p>Error loading coding questions.</p>';
        });
});
