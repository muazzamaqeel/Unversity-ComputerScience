class Question {
  constructor(text, options) {
    this.id = Math.random().toString(36).substr(2, 9);
    this.text = text;
    this.options = options || [];
    this.answers = [];
  }

  addAnswer(answer) {
    this.answers.push(answer);
  }
}

module.exports = Question;
