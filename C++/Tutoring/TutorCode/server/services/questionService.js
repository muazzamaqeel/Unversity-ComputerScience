// services/questionService.js
const questions = [];

function createQuestion(question) {
    questions.push(question);
}

function getQuestions() {
    return questions;
}

module.exports = {
    createQuestion,
    getQuestions,
};
