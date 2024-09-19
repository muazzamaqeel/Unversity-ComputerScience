import pyautogui
import time

# Function to simulate clicking a calculator button
def click_button(image):
    button = pyautogui.locateCenterOnScreen(image)
    if button:
        pyautogui.click(button)
    else:
        print(f"Could not find button {image} on the screen. Ensure the calculator is open and the button image is correct.")

# Function to automate the addition of two numbers
def add_numbers(num1, num2):
    click_button(f'{num1}.png')9
    click_button('plus.png')
    click_button(f'{num2}.png')
    click_button('equals.png')

# Function to automate subtraction
def subtract_numbers(num1, num2):
    click_button(f'{num1}.png')
    click_button('minus.png')
    click_button(f'{num2}.png')
    click_button('equals.png')

# Function to automate multiplication
def multiply_numbers(num1, num2):
    click_button(f'{num1}.png')
    click_button('multiply.png')
    click_button(f'{num2}.png')
    click_button('equals.png')

# Function to automate division
def divide_numbers(num1, num2):
    click_button(f'{num1}.png')
    click_button('divide.png')
    click_button(f'{num2}.png')
    click_button('equals.png')

# Main automation sequence
def main():
    time.sleep(2)  # Give you time to open the calculator on the screen

    # Example calculations
    add_numbers(1, 2)  # Performs 1 + 2
    time.sleep(1)

    subtract_numbers(5, 3)  # Performs 5 - 3
    time.sleep(1)

    multiply_numbers(4, 2)  # Performs 4 * 2
    time.sleep(1)

    divide_numbers(8, 4)  # Performs 8 / 4
    time.sleep(1)

if __name__ == "__main__":
    main()
