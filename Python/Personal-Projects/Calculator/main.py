import tkinter as tk
from tkinter import messagebox
import time

# Create the main window
root = tk.Tk()
root.title("Advanced Calculator")

# Create the entry widget
entry = tk.Entry(root, width=30, font=('Arial', 18), borderwidth=5)
entry.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

# Function to evaluate the expression in the entry widget
def evaluate_expression():
    try:
        result = eval(entry.get())
        entry.delete(0, tk.END)
        entry.insert(tk.END, str(result))
    except Exception as e:
        messagebox.showerror("Error", "Invalid Expression")

# Function to update the entry widget when buttons are pressed
def on_button_click(value):
    entry.insert(tk.END, value)

# Function to clear the entry widget
def clear_entry():
    entry.delete(0, tk.END)

# Function to delete the last character
def delete_last():
    current_text = entry.get()
    entry.delete(0, tk.END)
    entry.insert(tk.END, current_text[:-1])

# Button layout
buttons = [
    ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
    ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
    ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
    ('0', 4, 0), ('.', 4, 1), ('+', 4, 2), ('=', 4, 3)
]

# Add buttons to the window
button_widgets = {}
for (text, row, col) in buttons:
    if text == '=':
        button = tk.Button(root, text=text, padx=40, pady=20, font=('Arial', 18), command=evaluate_expression)
    else:
        button = tk.Button(root, text=text, padx=40, pady=20, font=('Arial', 18), command=lambda t=text: on_button_click(t))
    
    # Store each button for later automated interaction
    button_widgets[text] = button
    button.grid(row=row, column=col)

# Add clear, delete, and exit buttons
clear_button = tk.Button(root, text='C', padx=40, pady=20, font=('Arial', 18), command=clear_entry)
clear_button.grid(row=5, column=0)
button_widgets['C'] = clear_button

delete_button = tk.Button(root, text='Del', padx=30, pady=20, font=('Arial', 18), command=delete_last)
delete_button.grid(row=5, column=1)
button_widgets['Del'] = delete_button

exit_button = tk.Button(root, text='Exit', padx=30, pady=20, font=('Arial', 18), command=root.quit)
exit_button.grid(row=5, column=2)
button_widgets['Exit'] = exit_button

# Simulate button press in live and add a delay
def press_button(button_key):
    button_widgets[button_key].invoke()  # Simulate button press
    root.update()  # Update the UI to reflect the button press
    time.sleep(0.5)  # Delay to simulate real-time movement

# Function to perform automated tests
def test_calculator_operations():
    # Test 1: 1 + 2 = 3
    clear_entry()
    press_button('1')
    press_button('+')
    press_button('2')
    press_button('=')
    result = entry.get()
    if result == '3':
        messagebox.showinfo("Test Result", "Test 1 + 2 = 3 Passed!")
    else:
        messagebox.showerror("Test Result", f"Test 1 + 2 = 3 Failed! Got {result}")

    # Test 2: 4 - 2 = 2
    clear_entry()
    press_button('4')
    press_button('-')
    press_button('2')
    press_button('=')
    result = entry.get()
    if result == '2':
        messagebox.showinfo("Test Result", "Test 4 - 2 = 2 Passed!")
    else:
        messagebox.showerror("Test Result", f"Test 4 - 2 = 2 Failed! Got {result}")

    # Test 3: 5 * 3 = 15
    clear_entry()
    press_button('5')
    press_button('*')
    press_button('3')
    press_button('=')
    result = entry.get()
    if result == '15':
        messagebox.showinfo("Test Result", "Test 5 * 3 = 15 Passed!")
    else:
        messagebox.showerror("Test Result", f"Test 5 * 3 = 15 Failed! Got {result}")

    # Test 4: 9 / 3 = 3
    clear_entry()
    press_button('9')
    press_button('/')
    press_button('3')
    press_button('=')
    result = entry.get()
    if result == '3':
        messagebox.showinfo("Test Result", "Test 9 / 3 = 3 Passed!")
    else:
        messagebox.showerror("Test Result", f"Test 9 / 3 = 3 Failed! Got {result}")

    # Test 5: 7 + 8 = 15
    clear_entry()
    press_button('7')
    press_button('+')
    press_button('8')
    press_button('=')
    result = entry.get()
    if result == '15':
        messagebox.showinfo("Test Result", "Test 7 + 8 = 15 Passed!")
    else:
        messagebox.showerror("Test Result", f"Test 7 + 8 = 15 Failed! Got {result}")

# Add the test button, placed in a new row below the existing buttons
test_button = tk.Button(root, text='Test', padx=30, pady=20, font=('Arial', 18), command=test_calculator_operations)
test_button.grid(row=6, column=0, columnspan=4)
button_widgets['Test'] = test_button

# Start the main loop
root.mainloop()
