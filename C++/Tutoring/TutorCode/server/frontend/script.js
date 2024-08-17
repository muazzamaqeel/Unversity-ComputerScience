document.addEventListener('DOMContentLoaded', function() {
    const questionsContainer = document.getElementById('questions-container');
    const submitBtn = document.getElementById('submit-btn');

    // Fetch questions from the backend
    fetch('http://localhost:5000/api/questions')
        .then(response => response.json())
        .then(questions => {
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
            questionsContainer.innerHTML = '<p>Error loading questions.</p>';
        });

    // Handle form submission
    submitBtn.addEventListener('click', function() {
        const answers = [];

        const questions = document.querySelectorAll('.question');
        questions.forEach(questionDiv => {
            const selectedOption = questionDiv.querySelector('input[type="radio"]:checked');
            if (selectedOption) {
                answers.push({
                    questionId: selectedOption.name.split('-')[1],
                    answer: selectedOption.value
                });
            }
        });

        console.log('Submitted answers:', answers);

        // Here you could send the answers to the backend if needed
        fetch('http://localhost:5000/api/submit', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(answers)
        }).then(response => response.json())
        .then(data => {
            console.log('Submission successful:', data);
            alert('Your answers have been submitted successfully!');
        }).catch(error => {
            console.error('Error submitting answers:', error);
            alert('There was an error submitting your answers. Please try again.');
        });
    });
});
