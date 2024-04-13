from docx import Document
import re

# Define a function to parse the Q&A from the document
def parse_qa_from_docx(doc_path):
    # Read the document
    doc = Document(doc_path)
    # This will hold all the questions and their respective choices and answers
    qa_list = []
    # Temporary dictionary to store the current question block
    qa_block = {}
    # Regex pattern to identify if the line is a question or an answer
    question_pattern = re.compile(r'^\d+\.\s')
    answer_pattern = re.compile(r'^Answer:\s[a-d]$')

    for para in doc.paragraphs:
        text = para.text.strip()
        # Check if the line is a question
        if question_pattern.match(text):
            # If there's a question in progress, append it to the list
            if qa_block:
                qa_list.append(qa_block)
                qa_block = {}
            # Start a new question block
            qa_block['question'] = text
            qa_block['choices'] = []
        # Check if the line is a choice
        elif re.match(r'^[a-d]\.\s', text):
            if 'choices' in qa_block:
                qa_block['choices'].append(text)
        # Check if the line is an answer
        elif answer_pattern.match(text):
            qa_block['answer'] = text[-1]  # Store only the option letter

    # Append the last question block if it exists
    if qa_block:
        qa_list.append(qa_block)

    return qa_list

# Note: The path provided below is just a placeholder and will need to be replaced with the actual path on your system.
# It is commented out because the Python environment here does not have access to your local file system.
# You would uncomment this line and provide the correct path when running the script on your machine.
doc_path = "C:/programming/Unversity-ComputerScience/Python/Personal-Projects/Server-Data/1.docx"

# Call the function and get the Q&A list (commented out to prevent execution in this environment)
qa_data = parse_qa_from_docx(doc_path)

# For the next steps, the qa_data would be used to create a Google Form via Google Apps Script.
# This would involve structuring the data as JSON or as a Google Sheet that Google Apps Script could read.
# Here we can print the data to the console or write it to a file as required. This is also commented out.
print(qa_data)
