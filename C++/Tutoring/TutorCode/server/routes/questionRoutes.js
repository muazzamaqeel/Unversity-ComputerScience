const express = require('express');
const questionController = require('../controllers/questionController');

const router = express.Router();

// Route to get all questions
router.get('/questions', questionController.getQuestions);

// Route to post a new question (not typically used in the frontend for this example)
router.post('/questions', questionController.postQuestion);

// Route to post an answer to a specific question
router.post('/questions/:questionId/answers', questionController.postAnswer);

// Route to handle submission of all answers
router.post('/submit', (req, res) => {
    const submittedAnswers = req.body;
    console.log('Received answers:', submittedAnswers);

    // Example logic: Checking answers or storing them
    // You could add more detailed processing here
    // For now, just sending a success response back to the frontend
    res.status(200).json({ message: 'Answers submitted successfully!' });
});

module.exports = router;
