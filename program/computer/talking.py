from playsound import playsound 
import os                 
import pyaudio 
import pyttsx3 
import speech_recognition as sr   
from gtts import gTTS
import sys
import json 
import datetime 
import webbrowser as wb 
import random 
import wikipedia 

sleep = True 

engine = pyttsx3.init() 

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def time():
    Time = datetime.datetime.now().strftime("%I:%M:%S")
    speak("the current time is")
    speak(Time)
    print("The current time is: ", Time)


def starting():
    playsound("playsounds/robotic-creature-powering-on.mp3")
    
    hour = datetime.datetime.now().hour 

    if hour >= 4 and hour < 12:
        speak("good morning boss")
    elif hour >= 12 and hour < 16:
        speak('good afternoon boss')
    elif hour >= 16 and hour < 24:
        speak('good evening boss')
    else:
        speak('good night boss')
    
    speak('I am ready to serve you')



while sleep:
    r = sr.Recognizer()   # Initialize recognizer class (for
    with sr.Microphone() as source:
        r.pause_threshold = 1
        audio = r.listen(source)
    
    try:
        query = r.recognize_google(audio, language='en-in')
        print(query)
    except Exception as e:
        print(e)

    if query.lower() == "scott":
        starting()
        sleep = False


print('first experiment complete')
speak('first experiment complete')