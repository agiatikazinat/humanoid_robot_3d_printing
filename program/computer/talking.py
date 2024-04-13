from playsound import playsound 
import os                 
import pyaudio 
import threading
import pyttsx3
from parameter import * 
from command import *
import speech_recognition as sr   
from gtts import gTTS
import sys
import datetime 
import webbrowser as wb 
import time
import cv2 

sleep = True 

engine = pyttsx3.init() 
capture = cv2.VideoCapture(camera_port) 

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def telling_time():
    Time = datetime.datetime.now().strftime("%I:%M:%S")
    speak("the current time is")
    speak(Time)
    print("The current time is: ", Time)



def starting():
    playsound("playsounds/future-high-tech-logo.mp3")
    
    hour = datetime.datetime.now().hour 

    if hour >= 4 and hour < 12:
        speak("good morning boss")
    elif hour >= 12 and hour < 16:
        speak('good afternoon boss')
    elif hour >= 16 and hour < 24:
        speak('good evening boss')
    else:
        speak('good night boss')
    
    time.sleep(1)
    
    speak('I am ready to serve you')

while sleep:
    r = sr.Recognizer()   # Initialize recognizer class (for
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)
        print("Over here")

    try:
        query = r.recognize_google(audio, language='en-in')
        print(query)
        if wake_word in query.lower():
            starting()
            sleep = False
    except Exception as e:
        print(e)

def take_command():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.pause_threshold = 1
        audio = r.listen(source)
    
    try: 
        query = r.recognize_google(audio, language='en-in')
        print(query)
    except Exception as e:
        print(e)
        speak("Please say that again")
        return "Try Again"
    return query

while not sleep:

    # Start the camera ========================================
    # time.sleep(0.5)
    # success, frame = capture.read() 
    # if not success:
    #     break
    # cv2.imshow('Frame', frame)
    # =========================================================
    query = take_command().lower()

    if "turn off" in query:
        speak("See you later, boss")
        sleep = True


print('first experiment complete')
speak('first experiment complete')