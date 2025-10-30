from flask import Flask, request, jsonify, send_from_directory
import subprocess
import os

app = Flask(__name__)

@app.route('/')
def serve_index():
    return send_from_directory('.', 'index.html')
@app.route('/<path:path>')
def serve_static(path):
    return send_from_directory('.', path)

@app.route('/run_game', methods=['POST'])
def run_game():
    data = request.get_json()
    game = data.get('game')

    cpp_files = {
        "LostExplorer": "LostExplorer.cpp",
        "ReverseMind": "ReverseMind.cpp",
        "QueueRush": "QueueRush.cpp",
        "TreasureLogic": "TreasureLogic.cpp"
    }

    if game not in cpp_files:
        return jsonify({"output": "Invalid game selected!"})

    file = cpp_files[game]
    exe_name = file.replace('.cpp', '')

    try:
        # Compile the C++ file (if not compiled)
        subprocess.run(["g++", file, "-o", exe_name], check=True)

        # Run the compiled file and capture output
        result = subprocess.run([f"./{exe_name}"], input="", text=True, capture_output=True)
        output = result.stdout + result.stderr
    except subprocess.CalledProcessError as e:
        output = f"Compilation or Execution Error:\n{e}"

    return jsonify({"output": output})

if __name__ == '__main__':
    app.run(debug=True)
