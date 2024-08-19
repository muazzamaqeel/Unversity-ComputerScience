class QuestionService {
  constructor() {
      this.questions = [];
  }

  createQuestion(question) {
      this.questions.push({ ...question, id: Math.random().toString(36).substr(2, 9) });
  }

  getQuestions() {
      return this.questions;
  }
}

module.exports = new QuestionService();
