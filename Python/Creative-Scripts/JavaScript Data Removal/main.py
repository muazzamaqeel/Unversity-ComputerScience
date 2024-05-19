import PyPDF2

def remove_annotations(input_pdf_path, output_pdf_path):
    with open(input_pdf_path, "rb") as input_pdf_file:
        reader = PyPDF2.PdfReader(input_pdf_file)
        writer = PyPDF2.PdfWriter()

        for page_number in range(len(reader.pages)):
            page = reader.pages[page_number]
            page[PyPDF2.generic.NameObject("/Annots")] = PyPDF2.generic.ArrayObject()
            
            writer.add_page(page)

        with open(output_pdf_path, "wb") as output_pdf_file:
            writer.write(output_pdf_file)
input_pdf_path = 'C:\\Users\\muazz\\OneDrive\\Desktop\\\Ruth CV Fix\\Ruth Amosu.pdf'
output_pdf_path = 'C:\\Users\\muazz\\OneDrive\\Desktop\\Ruth Amosu_Cleaned.pdf'
remove_annotations(input_pdf_path, output_pdf_path)
