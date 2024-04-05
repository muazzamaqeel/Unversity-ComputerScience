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
                    select { display: block; margin-bottom: 10px; }
                    .correct { color: green; }
                    .incorrect { color: red; }
                </style>
                <script>
                    function validateForm() {
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
                <h1>Quiz</h1>
                <form method="post" action="/submit" onsubmit="return validateForm();">
                    {% for q in questions %}
                    <p>{{ loop.index }}. {{ q.question }}</p>
                    <select id="question{{ loop.index }}" name="question{{ loop.index }}">
                        <option value="">Select your answer</option>
                        {% for option in q.options %}
                        <option value="{{ option[:1] }}">{{ option[3:] }}</option>
                        {% endfor %}
                    </select>
                    {% endfor %}
                    <input type="submit" value="Submit">
                </form>
            </body>
        </html>
    ''', questions=quiz_questions)

@app.route('/submit', methods=['POST'])
def submit_quiz():
    global submission_count
    results = []
    score = 0
    for i, q in enumerate(quiz_questions):
        user_answer = request.form.get('question{}'.format(i+1))
        correct = user_answer.lower() == q['answer'] if user_answer is not None else False
        if correct:
            score += 1
        results.append({'question': q['question'], 'user_answer': user_answer, 'correct': correct, 'correct_answer': q['answer']})

    # Increment the submission count
    submission_count += 1

    return render_template_string('''
        <html>
            <head>
                <style>
                    .correct { color: green; }
                    .incorrect { color: red; }
                </style>
            </head>
            <body>
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
                <p>Total Submissions: {{ submission_count }}</p> <!-- Display total submissions -->
            </body>
        </html>
    ''', results=results, total=len(quiz_questions), submission_count=submission_count)

@app.route('/submissions', methods=['GET'])
def show_submissions():
    return f'<h1>Total Submissions: {submission_count}</h1>'

if __name__ == '__main__':
    app.run(debug=True)
