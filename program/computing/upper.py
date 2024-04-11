import serial 
import time 
import cv2 
import os 


ar1_port = ''
ar2_port = ''
ar3_port = ''

ar1_ser = serial.Serial(ar1_port, 19200)
ar2_ser = serial.Serial(ar2_port, 14400)
ar3_ser = serial.Serial(ar3_port, 9600)

ar1_ser.flush()
ar2_ser.flush() 
ar3_ser.flush()

capture = cv2.VideoCapture(0)

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
    
    