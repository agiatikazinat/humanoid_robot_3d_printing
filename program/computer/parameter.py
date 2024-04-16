import pyttsx3 
import cv2 

camera_port = "/dev/video0"
wake_word = "scott"
sleep = True 
engine = pyttsx3.init() 
capture = cv2.VideoCapture(camera_port) 