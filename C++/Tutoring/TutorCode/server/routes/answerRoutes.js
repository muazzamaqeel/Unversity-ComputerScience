const express = require('express');
const answerController = require('../controllers/answerController');

const router = express.Router();

router.post('/answers', answerController.createAnswer);

module.exports = router;