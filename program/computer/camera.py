import serial 
import time 
import cv2 
import os 



capture = cv2.VideoCapture('/dev/video0')

while True:
    time.sleep(0.5)
    success, frame = capture.read()
    if not success:
        break
    
    cv2.imshow('Frame', frame)
    if cv2.waitKey(25) & 0xFF == ord('q'):
        break
    
    
    
capture.release() 
cv2.destroyAllWindows()
    
    