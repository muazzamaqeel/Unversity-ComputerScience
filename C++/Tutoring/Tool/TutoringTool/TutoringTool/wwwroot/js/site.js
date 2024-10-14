function runCode(questionIndex) {
    const code = document.getElementById('codeEditor_' + questionIndex).value;

    fetch('/Home/RunCode', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(code)  // Send code to the server
    })
        .then(response => response.json())
        .then(data => {
            document.getElementById('output_' + questionIndex).innerText = data.output || "No output.";
        })
        .catch(error => {
            document.getElementById('output_' + questionIndex).innerText = "Error: " + error;
        });
}
