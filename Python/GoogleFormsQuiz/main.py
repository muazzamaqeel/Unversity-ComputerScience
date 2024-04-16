from docx import Document
import re
import json

def parse_qa_from_docx(doc_path):
    doc = Document(doc_path)
    qa_list = []
    qa_block = {}
    question_pattern = re.compile(r'^\d+\.\s')
    choice_pattern = re.compile(r'^[a-d]\.\s')
    answer_pattern = re.compile(r'^Answer:\s([A-D])$')  # Corrected regex to capture answer directly

    for para in doc.paragraphs:
        text = para.text.strip()
        if question_pattern.match(text):
            if qa_block:
                qa_list.append(qa_block)
                qa_block = {}
            qa_block['question'] = text
            qa_block['choices'] = []
        elif choice_pattern.match(text):
            qa_block['choices'].append(text)
        elif answer_match := answer_pattern.match(text):  # Use match object to extract answer
            qa_block['answer'] = answer_match.group(1)  # Correct extraction based on group capture

    if qa_block:
        qa_list.append(qa_block)

    return qa_list

def save_data_to_json(data, filename):
    with open(filename, 'w') as file:
        json.dump(data, file, indent=4)

doc_path = r'C:\programming\University-ComputerScience\Python\Personal-Projects\Server-Data\2.docx'
if os.path.exists(doc_path):
    qa_data = parse_qa_from_docx(doc_path)
    save_data_to_json(qa_data, 'qa_data.json')
    print("File exists and data has been processed. JSON file created:", doc_path)
else:
    print("The document path does not exist:", doc_path)
