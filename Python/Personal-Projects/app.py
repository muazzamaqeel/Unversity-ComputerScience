from flask import Flask, request, render_template_string
from docx import Document

app = Flask(__name__)

# Global variable to keep track of the number of submissions
submission_count = 0

def load_questions_from_docx(filename):
    try:
        doc = Document(filename)
        questions = []
        for para in doc.paragraphs:
            text = para.text.strip()
            if text and text[0].isdigit() and '.' in text:
                question_text = text.split('.', 1)[1].strip()
                questions.append({'question': question_text, 'options': [], 'answer': ''})
            elif text.startswith(('a.', 'b.', 'c.', 'd.')):
                if questions:
                    questions[-1]['options'].append(text)
            elif text.startswith('Answer:'):
                if questions:
                    answer_text = text.split(':', 1)[1].strip().lower()
                    questions[-1]['answer'] = answer_text
        return questions
    except Exception as e:
        print(f"An error occurred: {e}")
        return []

# Load questions directly from the given file path
file_path = 'C:\\programming\\Unversity-ComputerScience\\Python\\Personal-Projects\\Server-Data\\Classes&Objects.docx'
quiz_questions = load_questions_from_docx(file_path)

@app.route('/')
def quiz():
    return render_template_string('''
    <html>
        <head>
            <style>
                body {
                    background-image: url("https://i.ibb.co/kcCBtZ9/37fc8304-65b6-48f5-bb84-ce25bdba58a3.jpg");
                    background-size: cover; /* Cover the entire page */
                    background-position: center; /* Center the background image */
                    background-attachment: fixed; /* Prevent the background from scrolling with the page */
                    color: #333; /* Darker text color for readability */
                }
                .container {
                    max-width: 800px; /* Max width for content */
                    margin: auto; /* Center the content */
                    padding: 20px; /* Add some padding */
                }
                select, input[type="text"], input[type="submit"] {
                    width: 100%; /* Full width */
                    padding: 10px;
                    margin: 10px 0; /* Add some space between form fields */
                }
                h1 {
                    font-size: 5vw; /* Responsive font size */
                }
                p, label {
                    font-size: 1.2rem; /* Larger text for readability */
                }
                @media (max-width: 768px) {
                    h1 {
                        font-size: 6vw; /* Slightly larger font size on smaller screens */
                    }
                    p, label {
                        font-size: 1rem; /* Adjust font size for small devices */
                    }
                }
                @media (max-width: 480px) {
                    h1 {
                        font-size: 7vw; /* Larger font size for very small screens */
                    }
                    p, label {
                        font-size: 0.9rem; /* Smaller font size for very small devices */
                    }
                }
            </style>
            <script>
                function validateForm() {
                    var username = document.getElementById('username').value;
                    if (!username) {
                        alert('Please enter your Name.');
                        return false;
                    }
                    var all_answered = true;
                    {% for q in questions %}
                    var selector = document.getElementById('question{{ loop.index }}');
                    if (selector.value == "") {
                        all_answered = false;
                        break;
                    }
                    {% endfor %}
                    if (!all_answered) {
                        alert('Please answer all questions before submitting.');
                        return false;
                    }
                    return true;
                }
            </script>
        </head>
        <body>
            <div class="container">
                <h1>C++ Short Quiz</h1>
                <form method="post" action="/submit" onsubmit="return validateForm();">
                    <label for="username">Name:</label>
                    <input type="text" id="username" name="username" required>
                    {% for q in questions %}
                    <p>{{ loop.index }}. {{ q.question }}</p>
                    <select id="question{{ loop.index }}" name="question{{ loop.index }}" required>
                        <option value="">Select your answer</option>
                        {% for option in q.options %}
                        <option value="{{ option[:1] }}">{{ option[3:] }}</option>
                        {% endfor %}
                    </select>
                    {% endfor %}
                    <input type="submit" value="Submit">
                </form>
            </div>
        </body>
    </html>
''', questions=quiz_questions)

@app.route('/submit', methods=['POST'])
def submit_quiz():
    global submission_count
    username = request.form.get('username')  # Retrieve the username from form data
    print(f"Form submitted by: {username}")  # Print the username to the terminal

    results = []
    score = 0
    for i, q in enumerate(quiz_questions):
        user_answer = request.form.get('question{}'.format(i+1))
        correct = user_answer.lower() == q['answer'] if user_answer is not None else False
        if correct:
            score += 1
        results.append({'question': q['question'], 'user_answer': user_answer, 'correct': correct, 'correct_answer': q['answer']})

    submission_count += 1

    return render_template_string('''
<html>
    <head>
        <!-- Include the same style block as in the quiz function -->
    </head>
    <body>
        <div class="container">
            <h1>Results</h1>
            {% for result in results %}
                <p>Q: {{ result.question }}</p>
                <p class="{{ 'correct' if result.correct else 'incorrect' }}">
                    Your answer: {{ result.user_answer or 'No answer selected' }} - {{ 'Correct' if result.correct else 'Incorrect' }}
                </p>
                {% if not result.correct %}
                    <p class="correct">Correct answer: {{ result.correct_answer }}</p>
                {% endif %}
            {% endfor %}
            <h2>Your Score: {{ score }}/{{ total }}</h2>
            <p>Total Submissions: {{ submission_count }}</p>
        </div>
    </body>
</html>
''', results=results, total=len(quiz_questions), submission_count=submission_count)

@app.route('/submissions', methods=['GET'])
def show_submissions():
    return f'<h1>Total Submissions: {submission_count}</h1>'

if __name__ == '__main__':
    app.run(debug=True)
