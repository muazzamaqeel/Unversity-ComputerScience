using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.IO;
using System;
using TutoringTool.Services;

namespace TutoringTool.Controllers
{
    public class HomeController : Controller
    {
        // Loads the index page with optional userName
        public IActionResult Index(string userName)
        {
            var loader = new QuestionLoader();
            string filePath = Path.Combine(Directory.GetCurrentDirectory(), "ExcelData", "CodingQuestions.xlsx");
            var questions = loader.LoadQuestions(filePath);
            ViewBag.UserName = userName;
            return View(questions);
        }

        [HttpGet]
        public IActionResult Start()
        {
            return View(); // Serve the start page for name input
        }

        // Handles C++ code execution on the server
        [HttpPost]
        public IActionResult RunCode([FromBody] string code)
        {
            try
            {
                string tempPath = Path.Combine(Path.GetTempPath(), "code.cpp");
                string exePath = Path.Combine(Path.GetTempPath(), "code.exe");

                // Write the C++ code to a temporary file
                System.IO.File.WriteAllText(tempPath, code);

                // Compile the C++ code using g++
                ProcessStartInfo compileProcessInfo = new ProcessStartInfo("g++", $"{tempPath} -o {exePath}")
                {
                    RedirectStandardError = true,
                    RedirectStandardOutput = true,
                    UseShellExecute = false,
                    CreateNoWindow = true
                };
                var compileProcess = Process.Start(compileProcessInfo);
                string compileErrors = compileProcess.StandardError.ReadToEnd();
                compileProcess.WaitForExit();

                // If there are compilation errors, return them
                if (!string.IsNullOrEmpty(compileErrors))
                {
                    return Json(new { output = compileErrors });
                }

                // Run the compiled executable and capture output
                ProcessStartInfo runProcessInfo = new ProcessStartInfo(exePath)
                {
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                    UseShellExecute = false,
                    CreateNoWindow = true
                };
                var runProcess = Process.Start(runProcessInfo);
                string output = runProcess.StandardOutput.ReadToEnd();
                string runtimeErrors = runProcess.StandardError.ReadToEnd();
                runProcess.WaitForExit();

                // Return runtime errors if present, otherwise return output
                if (!string.IsNullOrEmpty(runtimeErrors))
                {
                    return Json(new { output = runtimeErrors });
                }

                return Json(new { output = output });
            }
            catch (Exception ex)
            {
                return Json(new { output = "Error: " + ex.Message });
            }
        }
    }
}
