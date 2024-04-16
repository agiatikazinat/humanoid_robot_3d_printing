import serial 
import time 
import cv2 
import os 
from parameter import *


def camera():
    while not sleep:
        time.sleep(0.5)
        success, frame = capture.read()
        if not success:
            break
        
        cv2.imshow('Frame', frame)
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break
    capture.release() 
    cv2.destroyAllWindows()
    
    