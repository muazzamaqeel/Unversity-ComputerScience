using ClosedXML.Excel;
using System.Collections.Generic;

namespace TutoringTool.Services
{
    public class QuestionLoader
    {
        public List<Question> LoadQuestions(string filePath)
        {
            var questions = new List<Question>();
            using (var workbook = new XLWorkbook(filePath))
            {
                var worksheet = workbook.Worksheet(1); // First sheet
                foreach (var row in worksheet.RowsUsed())
                {
                    var questionText = row.Cell(1).GetString(); // Column A
                    var correctAnswer = row.Cell(2).GetString(); // Column B
                    questions.Add(new Question { Text = questionText, Answer = correctAnswer });
                }
            }
            return questions;
        }
    }

    public class Question
    {
        public string Text { get; set; } = string.Empty; // Default value
        public string Answer { get; set; } = string.Empty; // Default value
    }
}
