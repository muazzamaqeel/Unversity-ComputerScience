const fs = require('fs');
const path = require('path');

// Define the structure of your project along with the file content
const structure = {
  'server': {
    'controllers': {
      'questionController.js': `
const questionService = require('../services/questionService');

class QuestionController {
  postQuestion(req, res) {
    const { text } = req.body;
    const question = questionService.createQuestion(text);
    res.status(201).json(question);
  }

  getQuestions(req, res) {
    const questions = questionService.getQuestions();
    res.json(questions);
  }

  postAnswer(req, res) {
    const { questionId, text } = req.body;
    const answer = questionService.addAnswerToQuestion(questionId, text);
    if (answer) {
      res.status(201).json(answer);
    } else {
      res.status(404).json({ message: 'Question not found' });
    }
  }
}

module.exports = new QuestionController();
      `,
      'answerController.js': `
const answerService = require('../services/answerService');

class AnswerController {
  createAnswer(req, res) {
    const { text } = req.body;
    const answer = answerService.createAnswer(text);
    res.status(201).json(answer);
  }
}

module.exports = new AnswerController();
      `
    },
    'models': {
      'questionModel.js': `
class Question {
  constructor(text) {
    this.id = Math.random().toString(36).substr(2, 9);
    this.text = text;
    this.answers = [];
  }

  addAnswer(answer) {
    this.answers.push(answer);
  }
}

module.exports = Question;
      `,
      'answerModel.js': `
class Answer {
  constructor(text) {
    this.id = Math.random().toString(36).substr(2, 9);
    this.text = text;
  }
}

module.exports = Answer;
      `
    },
    'routes': {
      'questionRoutes.js': `
const express = require('express');
const questionController = require('../controllers/questionController');

const router = express.Router();

router.post('/questions', questionController.postQuestion);
router.get('/questions', questionController.getQuestions);
router.post('/questions/:questionId/answers', questionController.postAnswer);

module.exports = router;
      `,
      'answerRoutes.js': `
const express = require('express');
const answerController = require('../controllers/answerController');

const router = express.Router();

router.post('/answers', answerController.createAnswer);

module.exports = router;
      `
    },
    'services': {
      'questionService.js': `
const Question = require('../models/questionModel');
const Answer = require('../models/answerModel');

class QuestionService {
  constructor() {
    this.questions = [];
  }

  createQuestion(text) {
    const question = new Question(text);
    this.questions.push(question);
    return question;
  }

  getQuestions() {
    return this.questions;
  }

  addAnswerToQuestion(questionId, answerText) {
    const question = this.questions.find(q => q.id === questionId);
    if (question) {
      const answer = new Answer(answerText);
      question.addAnswer(answer);
      return answer;
    }
    return null;
  }
}

module.exports = new QuestionService();
      `,
      'answerService.js': `
const Answer = require('../models/answerModel');

class AnswerService {
  createAnswer(text) {
    return new Answer(text);
  }
}

module.exports = new AnswerService();
      `
    },
    'server.js': `
const express = require('express');
const http = require('http');
const socketIo = require('socket.io');
const cors = require('cors');
const questionRoutes = require('./routes/questionRoutes');

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
  console.log(\`Server running on port \${PORT}\`);
});
      `
    }
  }

// Function to create directories and files
function createStructure(base, structure) {
  for (const [key, value] of Object.entries(structure)) {
    const newBase = path.join(base, key);
    if (typeof value === 'object' && !Array.isArray(value)) {
      fs.mkdirSync(newBase, { recursive: true });
      createStructure(newBase, value);
    } else if (typeof value === 'string') {
      fs.writeFileSync(newBase, value.trim());
    }
  }
}

// Create the project structure in the current directory
createStructure(process.cwd(), structure);

console.log('Project structure with code created successfully.');
