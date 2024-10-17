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

// Disable clipboard events on the entire document
/*
document.addEventListener('copy', function (e) {
    e.preventDefault();
});

document.addEventListener('cut', function (e) {
    e.preventDefault();
});

*/

document.addEventListener('paste', function (e) {
    e.preventDefault();
});


document.querySelectorAll('textarea').forEach((textarea) => {
    textarea.addEventListener('keydown', function (e) {
        if (e.ctrlKey && e.key === 'I') {
            e.preventDefault();
            indentCode(textarea);
        }
    });
});

function indentCode(textarea) {
    const start = textarea.selectionStart;
    const end = textarea.selectionEnd;
    const code = textarea.value;

    // Insert 4 spaces for indentation
    const newCode = code.substring(0, start) + "    " + code.substring(end);

    textarea.value = newCode;
    textarea.selectionStart = textarea.selectionEnd = start + 4; // Move the cursor after indentation
}

