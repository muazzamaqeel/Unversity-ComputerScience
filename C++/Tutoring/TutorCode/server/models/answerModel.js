class Answer {
  constructor(text) {
    this.id = Math.random().toString(36).substr(2, 9);
    this.text = text;
  }
}

module.exports = Answer;