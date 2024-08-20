const express = require('express');
const http = require('http');
const cors = require('cors');
const path = require('path');
const xlsx = require('xlsx');
const { exec } = require('child_process');
const fs = require('fs');
const nodemailer = require('nodemailer');
const docx = require('docx');

const questionService = require('./services/questionService');

const app = express();
const server = http.createServer(app);

app.use(cors());
app.use(express.json());

const quizFilePath = path.join(__dirname, 'backend', 'excel-files', 'C++Questions.xlsx');
importQuestionsFromExcel(quizFilePath);

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
            questionService.createQuestion({ text: questionText, options });
        } else {
            console.log(`Skipping row ${index + 1}: Improper format or insufficient data`);
        }
    });

    console.log("Quiz questions imported.");
}

// Load coding questions from Excel
const codingQuestions = importCodingQuestionsFromExcel(path.join(__dirname, 'backend', 'excel-files', 'CodingQuestions.xlsx'));

function importCodingQuestionsFromExcel(filePath) {
    const workbook = xlsx.readFile(filePath);
    const sheetName = workbook.SheetNames[0];
    const worksheet = workbook.Sheets[sheetName];
    const rows = xlsx.utils.sheet_to_json(worksheet, { header: 1 });

    const codingQuestions = [];

    rows.forEach((row, index) => {
        const questionText = row[0];
        const answerText = row[1];

        if (typeof questionText === 'string' && typeof answerText === 'string') {
            codingQuestions.push({
                text: questionText,
                template: `#include <iostream>\nusing namespace std;\n\n// Your code here\n\nint main() {\n    cout << "Hello, World!";\n    return 0;\n}`,
                answer: answerText
            });
        } else {
            console.log(`Skipping row ${index + 1}: Improper format or insufficient data`);
        }
    });

    return codingQuestions;
}

// API to get quiz questions
app.get('/api/questions', (req, res) => {
    const questions = questionService.getQuestions();
    res.json(questions);
});

// API to get coding questions
app.get('/api/coding-questions', (req, res) => {
    res.json(codingQuestions);
});

// API to compile and run C++ code
app.post('/api/compile', (req, res) => {
    const { code, expectedOutput } = req.body;
    
    const filePath = path.join(__dirname, 'temp', `user_code_${Date.now()}.cpp`);
    fs.writeFileSync(filePath, code);

    exec(`g++ ${filePath} -o ${filePath}.exe`, (compileErr, stdout, stderr) => {
        if (compileErr) {
            return res.status(400).json({ success: false, error: stderr });
        }

        exec(`${filePath}.exe`, (runErr, runStdout, runStderr) => {
            if (runErr) {
                return res.status(400).json({ success: false, error: runStderr });
            }

            const outputCorrect = runStdout.trim() === expectedOutput.trim();
            res.json({ success: true, isCorrect: outputCorrect, output: runStdout.trim() });
        });
    });
});

// Serve the frontend files
app.use(express.static(path.join(__dirname, 'frontend')));

const PORT = process.env.PORT || 5000;
server.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
