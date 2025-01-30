import pyautogui
import random
import time

def move_mouse_randomly():
    screen_width, screen_height = pyautogui.size()
    print(f"Screen dimensions: {screen_width}x{screen_height}")

    while True:
        try:
            random_x = random.randint(0, screen_width - 1)
            random_y = random.randint(0, screen_height - 1)
            print(f"Moving to: ({random_x}, {random_y})")
            pyautogui.moveTo(random_x, random_y, duration=0.5)
            time.sleep(random.uniform(1, 3))
        except KeyboardInterrupt:
            print("Mouse mover stopped by user.")
            break

if __name__ == "__main__":
    print("Starting. Ctrl+C to stop.")
    move_mouse_randomly()
