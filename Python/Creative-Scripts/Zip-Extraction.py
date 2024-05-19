import os
import zipfile

def unzip_all_files_in_directory(directory):
    # Get a list of all files in the directory
    files = os.listdir(directory)
    
    # Loop through each file in the directory
    for file in files:
        # Check if the file is a ZIP file
        if file.endswith('.zip'):
            # Create a path to the ZIP file
            zip_path = os.path.join(directory, file)
            
            # Create a directory to extract the ZIP file contents
            extract_dir = os.path.join(directory, os.path.splitext(file)[0])
            os.makedirs(extract_dir, exist_ok=True)
            
            # Extract the contents of the ZIP file
            with zipfile.ZipFile(zip_path, 'r') as zip_ref:
                zip_ref.extractall(extract_dir)
            
            print(f"Extracted {file} to {extract_dir}")

if __name__ == "__main__":
    # Define the directory containing the ZIP files
    current_directory = os.getcwd()  # Gets the current working directory
    
    # Call the function to unzip all ZIP files in the directory
    unzip_all_files_in_directory(current_directory)
