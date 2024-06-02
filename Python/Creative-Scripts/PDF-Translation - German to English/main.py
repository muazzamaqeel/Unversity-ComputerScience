import os
import pdfplumber
from googletrans import Translator
from fpdf import FPDF
import tkinter as tk
from tkinter import messagebox
from tkinter import filedialog
from tkinter import ttk

def translate_text(text):
    try:
        translation = translator.translate(text, src='de', dest='en')
        return translation.text
    except Exception as e:
        print(f"Translation error: {e}")
        return None

def create_translated_pdf(original_file, translated_text, translated_directory):
    pdf = FPDF()
    pdf.add_page()
    pdf.set_auto_page_break(auto=True, margin=15)
    pdf.set_font("Arial", size=12)

    for line in translated_text.split('\n'):
        try:
            if line.strip():  # Check if the line is not empty
                pdf.multi_cell(0, 10, line)
        except Exception as e:
            print(f"Error rendering line: {line}")
            print(f"Exception: {e}")
            continue
    
    translated_file = os.path.join(translated_directory, f"EN_{os.path.basename(original_file)}")
    pdf.output(translated_file)

def start_translation():
    directory = entry.get()
    if not directory:
        messagebox.showwarning("Input Error", "No directory entered. Please enter a directory.")
        return
    
    if not os.path.isdir(directory):
        messagebox.showwarning("Input Error", "Invalid directory. Please try again.")
        return

    translated_directory = os.path.join(directory, "Translation")
    os.makedirs(translated_directory, exist_ok=True)

    pdf_files = [f for f in os.listdir(directory) if f.endswith(".pdf")]
    total_files = len(pdf_files)
    
    progress_bar['maximum'] = total_files
    progress_bar['value'] = 0
    
    for index, filename in enumerate(pdf_files):
        try:
            file_path = os.path.join(directory, filename)
            
            with pdfplumber.open(file_path) as pdf:
                all_text = ''
                for page in pdf.pages:
                    text = page.extract_text()
                    if text:
                        all_text += text + '\n'
            
            if all_text.strip() == "":
                raise ValueError(f"No text extracted from {filename}")

            translated_text = translate_text(all_text)
            if translated_text:
                create_translated_pdf(file_path, translated_text, translated_directory)
                progress_bar['value'] = index + 1
                root.update_idletasks()
            else:
                raise ValueError(f"Translation failed for {filename}")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to translate {filename}: {e}")
            continue
    
    messagebox.showinfo("Success", "Translation completed and saved in the 'Translation' directory.")

def browse_directory():
    directory = filedialog.askdirectory()
    if directory:
        entry.delete(0, tk.END)
        entry.insert(0, directory)

def cancel():
    root.destroy()

translator = Translator()

root = tk.Tk()
root.title("PDF Translator")

tk.Label(root, text="Enter the directory path:").pack(padx=10, pady=5)

entry = tk.Entry(root, width=50)
entry.pack(padx=10, pady=5)

browse_button = tk.Button(root, text="Browse", command=browse_directory)
browse_button.pack(padx=10, pady=5)

translate_button = tk.Button(root, text="Translate", command=start_translation)
translate_button.pack(padx=10, pady=5)

cancel_button = tk.Button(root, text="Cancel", command=cancel)
cancel_button.pack(padx=10, pady=5)

progress_bar = ttk.Progressbar(root, orient="horizontal", length=400, mode="determinate")
progress_bar.pack(padx=10, pady=10)

root.mainloop()
