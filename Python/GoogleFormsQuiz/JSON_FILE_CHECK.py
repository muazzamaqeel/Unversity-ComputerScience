import json

# Load the JSON file
with open(r'C:\programming\Unversity-ComputerScience\Python\Personal-Projects\Server-Data\qa_data.json') as file:
    qa_data = json.load(file)



# Check each entry for an answer key
missing_answers = [item['question'] for item in qa_data if 'answer' not in item or not isinstance(item['answer'], str)]

if missing_answers:
    print("Missing or invalid answers for questions:")
    for question in missing_answers:
        print(question)
else:
    print("All questions have valid answers.")
