const Question = require('../models/questionModel');

class QuestionService {
  constructor() {
    this.questions = [];
  }

  createQuestion({ text, options }) {
    const question = new Question(text, options);
    this.questions.push(question);
    return question;
  }

  getQuestions() {
    return this.questions;
  }

  addAnswerToQuestion(questionId, answerText) {
    const question = this.questions.find(q => q.id === questionId);
    if (question) {
      question.addAnswer(answerText);
      return answerText;
    }
    return null;
  }
}

module.exports = new QuestionService();
