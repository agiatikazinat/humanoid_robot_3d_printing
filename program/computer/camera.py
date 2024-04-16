import serial 
import time 
import cv2 
import os 
from parameter import *


class Camera:
    def __init__(self):
        self._status = False 
    
    def turn_on(self):
        self._status = True 
    
    def turn_off(self):
        self._status = False

    def get_status(self):
        return self._status 

def camera(camera):
    print(camera.get_status())
    while camera.get_status():
        time.sleep(0.5)
        success, frame = capture.read()
        if not success:
            break
        
        cv2.imshow('Frame', frame)
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break
    print('off camera')
    capture.release() 
    cv2.destroyAllWindows()
    
    