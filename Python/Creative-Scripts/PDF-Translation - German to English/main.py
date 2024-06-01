import os
import pdfplumber
from googletrans import Translator
from fpdf import FPDF

# Get the directory where this script is located
directory = os.path.dirname(os.path.abspath(__file__))
# Create a translator object
translator = Translator()

# Create a new directory for the translated files
translated_directory = os.path.join(directory, "Translation")
os.makedirs(translated_directory, exist_ok=True)

# Function to translate text from German to English
def translate_text(text):
    translation = translator.translate(text, src='de', dest='en')
    return translation.text

# Function to create a translated PDF
def create_translated_pdf(original_file, translated_text):
    pdf = FPDF()
    pdf.add_page()
    pdf.set_auto_page_break(auto=True, margin=15)
    pdf.set_font("Arial", size=12)
    
    for line in translated_text.split('\n'):
        pdf.multi_cell(0, 10, line)
    
    translated_file = os.path.join(translated_directory, f"EN_{os.path.basename(original_file)}")
    pdf.output(translated_file)

# Iterate over all PDF files in the directory
for filename in os.listdir(directory):
    if filename.endswith(".pdf"):
        file_path = os.path.join(directory, filename)
        
        # Extract text from the PDF while preserving formatting
        with pdfplumber.open(file_path) as pdf:
            all_text = ''
            for page in pdf.pages:
                all_text += page.extract_text() + '\n'
        
        # Translate the extracted text
        translated_text = translate_text(all_text)
        
        # Create a new PDF with the translated text
        create_translated_pdf(file_path, translated_text)

print("Translation completed and saved in the 'Translation' directory.")
