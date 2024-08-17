const answerService = require('../services/answerService');

class AnswerController {
  createAnswer(req, res) {
    const { text } = req.body;
    const answer = answerService.createAnswer(text);
    res.status(201).json(answer);
  }
}

module.exports = new AnswerController();