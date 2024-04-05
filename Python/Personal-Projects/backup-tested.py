from flask import Flask, request, render_template_string, redirect, url_for
from docx import Document

app = Flask(__name__)

# Placeholder for quiz questions
quiz_questions = []

def load_questions_from_docx(filename):
    doc = Document(filename)
    questions = []
    current_question = None  # Use None to indicate no current question at start
    for para in doc.paragraphs:
        text = para.text.strip()
        if text.split('.')[0].isdigit():
            if current_question:  # If there's an existing question, append it before starting a new one
                questions.append(current_question)
            current_question = {'question': ' '.join(text.split('.')[1:]).strip(), 'options': [], 'answer': ''}  # Start a new question
        elif text.startswith('a.') or text.startswith('b.') or text.startswith('c.') or text.startswith('d.'):
            if current_question is not None:  # Ensure there's a question being processed
                current_question['options'].append(text)
        elif text.startswith('Answer:'):
            if current_question is not None:
                current_question['answer'] = text.split(':')[1].strip().lower()
                questions.append(current_question)  # Append the last question when answer is found
                current_question = None  # Reset for the next question
        elif current_question is not None:  # Additional text for the current question
            current_question['question'] += " " + text

    return questions


# Load questions (For simplicity, loading from a hardcoded path)
quiz_questions = load_questions_from_docx('C:\\programming\\Unversity-ComputerScience\\Python\\Personal-Projects\\Classes&Objects.docx')

@app.route('/')
def quiz():
    # Updated to pass question index to template for unique input names
    return render_template_string('''
        <h1>Quiz</h1>
        <form method="post" action="/submit">
            {% for q in questions %}
                <p>{{ loop.index }}. {{ q.question }}</p>
                {% for option in q.options %}
                    <input type="radio" name="question{{loop.index0}}" value="{{ option[:1] }}">{{ option }}<br>
                {% endfor %}
            {% endfor %}
            <input type="submit" value="Submit">
        </form>
    ''', questions=quiz_questions)

@app.route('/submit', methods=['POST'])
def submit_quiz():
    results = []
    score = 0
    for i, q in enumerate(quiz_questions):
        user_answer = request.form.get(f'question{i}')
        correct = user_answer == q['answer']
        if correct:
            score += 1
        results.append((q, user_answer, correct))
    
    # Render results
    return render_template_string('''
        <h1>Results</h1>
        {% for q, user_answer, correct in results %}
            <p>Q: {{ q.question }}</p>
            <p>Your answer: {{ user_answer }} - {{ 'Correct' if correct else 'Incorrect' }}</p>
            <p>Correct answer: {{ q.answer }}</p>
        {% endfor %}
        <h2>Your Score: {{ score }}/{{ total }}</h2>
    ''', results=results, total=len(quiz_questions))

@app.route('/upload', methods=['GET', 'POST'])
def upload_questions():
    # Placeholder for upload functionality, to be implemented
    return '''
        <h1>Upload Questions</h1>
        <form method="post" enctype="multipart/form-data">
            <input type="file" name="question_file"><br>
            <input type="submit" value="Upload">
        </form>
    '''

if __name__ == '__main__':
    app.run(debug=True)
