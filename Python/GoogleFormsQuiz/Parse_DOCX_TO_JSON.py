from docx import Document
import re
import json
import os

# Define a function to parse the Q&A from the document
def parse_qa_from_docx(doc_path):
    doc = Document(doc_path)
    qa_list = []
    qa_block = {}
    question_pattern = re.compile(r'^\d+\.\s')  # Detects question numbers
    choice_pattern = re.compile(r'^[a-d]\.\s')  # Detects choices labeled a., b., c., or d.
    answer_pattern = re.compile(r'^Answer:\s[A-D]$')  # Detects answer lines

    for para in doc.paragraphs:
        text = para.text.strip()
        if question_pattern.match(text):
            # Save the previous question block if it exists
            if qa_block:
                qa_list.append(qa_block)
                qa_block = {}
            # Start a new question block
            qa_block['question'] = text
            qa_block['choices'] = []
        elif choice_pattern.match(text):
            # Append choice to the current question block
            if 'choices' in qa_block:
                qa_block['choices'].append(text)
        elif answer_pattern.match(text):
            # Extract the answer character and save it in the current question block
            qa_block['answer'] = text.split(': ')[1].strip()

    # Append the last question block if it exists
    if qa_block:
        qa_list.append(qa_block)

    return qa_list

# Function to save data to a JSON file
def save_data_to_json(data, filename):
    with open(filename, 'w') as file:
        json.dump(data, file, indent=4)  # Use indent for better readability

# Example usage
doc_path = r'C:\programming\Unversity-ComputerScience\Python\Personal-Projects\Server-Data\2.docx'


# Check if the path exists
if os.path.exists(doc_path):
    qa_data = parse_qa_from_docx(doc_path)
    save_data_to_json(qa_data, 'qa_data.json')
    print("File exists and data has been processed. JSON file created:", doc_path)
else:
    print("The document path does not exist:", doc_path)


