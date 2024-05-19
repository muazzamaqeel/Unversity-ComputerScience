#!/usr/bin/env python
# coding: utf-8

import speech_recognition as sr
from googletrans import Translator

# Initialize the recognizer and translator
recognizer = sr.Recognizer()
translator = Translator()

def list_microphones():
    """
    List all microphones with their respective index numbers.
    """
    mic_list = sr.Microphone.list_microphone_names()
    for index, name in enumerate(mic_list):
        print(f"Microphone with index {index} is named: {name}")

def translate_speech_from_microphone(language="de", microphone_index=None):
    """
    Translate speech from a specified microphone.

    :param language: The language code for recognition.
    :param microphone_index: The index of the microphone to use.
    """
    # Use the specified microphone as the audio source
    with sr.Microphone(device_index=microphone_index) as source:
        print("Please start speaking. Press Ctrl+C to stop.")

        # Adjust for ambient noise once at the beginning
        recognizer.adjust_for_ambient_noise(source, duration=1)

        # Continuously listen and translate
        while True:
            try:
                print("Listening...")
                audio = recognizer.listen(source, timeout=5)  # Listen for the first phrase and extract it into audio data

                # Recognize speech using Google Web Speech API
                text = recognizer.recognize_google(audio, language=language)
                print(f"Detected ({language}): {text}")

                # Translate the recognized text to English
                translated = translator.translate(text, dest='en')
                print(f"Translated to English: {translated.text}\n")

            except sr.UnknownValueError:
                print("Could not understand audio. Please try again.\n")
            except sr.RequestError as e:
                print(f"Could not request results from the service; {e}\n")
            except KeyboardInterrupt:
                print("\nTranslation stopped.")
                break

# Display all microphones
list_microphones()

# User selects the microphone by specifying its index
mic_index = int(input("Enter the index of the microphone you want to use: "))

# Specify the language code for German (Germany)
language_code = "de-DE"

# Start continuous translation
translate_speech_from_microphone(language_code, mic_index)
