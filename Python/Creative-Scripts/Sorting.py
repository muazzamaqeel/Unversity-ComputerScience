import os
import shutil
from collections import defaultdict
import tkinter as tk
from tkinter import messagebox

def organize_files():
    current_directory = os.getcwd()
    organized_dir = os.path.join(current_directory, "Organized")
    script_name = os.path.basename(__file__)
    
    if not os.path.exists(organized_dir):
        os.makedirs(organized_dir)

    file_types = defaultdict(list)
    files_moved = 0
    files_failed = []
    open_files = []

    def move_files():
        nonlocal files_moved, files_failed, open_files
        files_failed.clear()
        open_files.clear()

        for file_extension, files in file_types.items():
            if file_extension:  # ignore files without extension
                extension_dir = os.path.join(organized_dir, file_extension[1:].upper())
                if not os.path.exists(extension_dir):
                    os.makedirs(extension_dir)
                
                for file_name in files:
                    try:
                        shutil.move(os.path.join(current_directory, file_name), os.path.join(extension_dir, file_name))
                        files_moved += 1
                    except PermissionError:
                        open_files.append(file_name)
                    except Exception as e:
                        files_failed.append((file_name, str(e)))

    def retry_moving_files():
        move_files()
        display_results()

    # All files and their extensions
    for file_name in os.listdir(current_directory):
        if os.path.isfile(file_name) and file_name != script_name:
            file_extension = os.path.splitext(file_name)[1].lower()
            file_types[file_extension].append(file_name)

    # Moving files
    move_files()

    def display_results():
        nonlocal files_moved, files_failed, open_files
        root = tk.Tk()
        root.withdraw()

        success_message = f"Total files moved: {files_moved}\n"
        failure_message = ""
        
        if files_failed:
            failure_message += "Files failed to move:\n" + "\n".join([f"{file}: {error}" for file, error in files_failed]) + "\n"
        
        if open_files:
            open_files_message = "The following files are open and could not be moved:\n" + "\n".join(open_files)
            failure_message += open_files_message + "\nPlease close these files and run the script again."
            retry_window = tk.Toplevel()
            retry_window.title("Open Files Detected")

            tk.Label(retry_window, text=open_files_message + "\nPlease close these files and run the script again.").pack(pady=10)
            tk.Button(retry_window, text="Close", command=retry_window.destroy).pack(pady=5)
        else:
            messagebox.showinfo("File Organization Result", success_message + (failure_message if files_failed else "No files failed to move."))
            root.destroy()

    display_results()

if __name__ == "__main__":
    organize_files()
