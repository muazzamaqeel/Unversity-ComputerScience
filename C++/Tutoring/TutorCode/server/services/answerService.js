const Answer = require('../models/answerModel');

class AnswerService {
  createAnswer(text) {
    return new Answer(text);
  }
}

module.exports = new AnswerService();