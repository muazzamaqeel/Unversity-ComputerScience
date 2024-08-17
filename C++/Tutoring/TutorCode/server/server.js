const express = require('express');
const http = require('http');
const socketIo = require('socket.io');
const cors = require('cors');
const questionRoutes = require('./routes/questionRoutes');
const path = require('path');
const xlsx = require('xlsx');
const questionService = require('./services/questionService');

const app = express();
const server = http.createServer(app);
const io = socketIo(server, {
  cors: {
    origin: "http://localhost:3000",
    methods: ["GET", "POST"]
  }
});

app.use(cors());
app.use(express.json());

// Import questions on server start
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

    console.log("Questions imported on server start.");
}

const filePath = path.join(__dirname, 'backend', 'excel-files', 'C++Questions.xlsx');
importQuestionsFromExcel(filePath);

// Serve the frontend files from the "frontend" directory
app.use(express.static(path.join(__dirname, 'frontend')));

app.use('/api', questionRoutes);

io.on('connection', (socket) => {
  console.log('New client connected:', socket.id);

  socket.on('submitAnswer', ({ questionId, answer }) => {
    // handle the answer submission
  });

  socket.on('postQuestion', (question) => {
    // handle the question posting
  });

  socket.on('disconnect', () => {
    console.log('Client disconnected:', socket.id);
  });
});

const PORT = process.env.PORT || 5000;
server.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
