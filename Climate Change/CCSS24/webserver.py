from flask import Flask, send_from_directory
import os

app = Flask(__name__)
web_dir = "/home/ubuntu/CCSS24"  # Directory where your website files are located

@app.route('/')
def serve_index():
    return send_from_directory(web_dir, 'index.html')

@app.route('/<path:path>')
def serve_file(path):
    return send_from_directory(web_dir, path)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=80)
