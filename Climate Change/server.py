from flask import Flask, send_from_directory, abort

app = Flask(__name__)

# Set the directory where your website files are located
web_dir = "/home/ec2-user/CCSS24"

@app.route('/')
def serve_index():
    # Serve the main index.html file
    return send_from_directory(web_dir, 'index.html')

@app.route('/<path:path>')
def serve_file(path):
    try:
        # Serve other files from the directory
        return send_from_directory(web_dir, path)
    except:
        # If the file is not found, return a 404 error
        abort(404)

if __name__ == "__main__":
    app.run(debug=True)

