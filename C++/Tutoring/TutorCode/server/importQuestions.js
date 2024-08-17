const path = require('path');
const xlsx = require('xlsx');
const questionService = require('./services/questionService');

function importQuestionsFromExcel(filePath) {
    const workbook = xlsx.readFile(filePath);
    const sheetName = workbook.SheetNames[0];
    const worksheet = workbook.Sheets[sheetName];
    const rows = xlsx.utils.sheet_to_json(worksheet, { header: 1 });

    rows.forEach((row, index) => {
        const questionText = row[0];
        const optionsText = row[1];

        if (typeof questionText === 'string' && typeof optionsText === 'string') {
            const options = optionsText.split(',').map(opt => opt.trim());
            const question = questionService.createQuestion({ text: questionText, options });
            console.log(`Question added: ${question.text}`); // Log each question added
        } else {
            console.log(`Skipping row ${index + 1}: Improper format or insufficient data`);
        }
    });

    console.log("All questions added. Final questions array:", questionService.getQuestions());
}

const filePath = path.join(__dirname, 'backend', 'excel-files', 'C++Questions.xlsx');
importQuestionsFromExcel(filePath);
