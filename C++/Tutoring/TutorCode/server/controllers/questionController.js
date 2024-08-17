const questionService = require('../services/questionService');

class QuestionController {
  getQuestions = (req, res) => {
    const questions = questionService.getQuestions();
    console.log("Retrieved questions:", questions); // Add this line for debugging
    res.json(questions);
  }

  postQuestion = (req, res) => {
    const { text, options } = req.body;
    const question = questionService.createQuestion({ text, options });
    res.status(201).json(question);
  }

  postAnswer = (req, res) => {
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
