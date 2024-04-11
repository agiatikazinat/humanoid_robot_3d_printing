import serial 
import time 
import cv2 
import os 


ar1_port = ''
ar2_port = ''
ar3_port = '/dev/ttyUSB0'

ar1_ser = serial.Serial(ar1_port, 19200)
ar2_ser = serial.Serial(ar2_port, 14400)
ar3_ser = serial.Serial(ar3_port, 9600)

ar1_ser.flush()
ar2_ser.flush() 
ar3_ser.flush()

while True:
    command = input("Enter a command (q to quit): ")

