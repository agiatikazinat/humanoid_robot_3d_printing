from playsound import playsound 
import os                 
import pyaudio 
import threading
from parameter import * 
import speech_recognition as sr   
from gtts import gTTS
import sys
import datetime 
import webbrowser as wb 
import time



def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def telling_time():
    Time = datetime.datetime.now().strftime("%I:%M:%S")
    speak("the current time is")
    speak(Time)
    print("The current time is: ", Time)

def awake():
    while sleep:
        r = sr.Recognizer()   # Initialize recognizer class (for
        with sr.Microphone() as source:
            print("Sleeping.z.z.z...")
            r.pause_threshold = 1
            audio = r.listen(source)

        try:
            query = r.recognize_google(audio, language='en-in')
            print(query)
            if wake_word in query.lower():
                starting()
                sleep = False
        except Exception as e:
            print(e)

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

def talking(camera):
    query = take_command().lower() 
    
    if "turn off" in query:
        speak("See you later, boss")
        sleep = True
        camera.turn_off()
    
