import serial 
import time 
import cv2 
import os 

ar1_port = '/dev/ttyACM3' # Arduino Uno
ar2_port = '/dev/ttyACM1' # Arduino Mega
ar3_port = '/dev/ttyUSB0' # Arduino Uno
ar4_port = '/dev/ttyACM0' # Arduino Uno

ar1_ser = serial.Serial(ar1_port, 19200)
ar2_ser = serial.Serial(ar2_port, 38400)
ar3_ser = serial.Serial(ar3_port, 9600)
ar4_ser = serial.Serial(ar4_port, 28800)

ar1_ser.flush()
ar2_ser.flush() 
ar3_ser.flush()
ar4_ser.flush()

Ar1List = ['left_hand', 'right_hand']
Ar1MethodList = ['open', 'close', 'finger_moving', 'servo_wrist']

Ar2List = ['right_shoulder_x', 'right_shoulder_y', 'right_shoulder_z', 'right_bicept', 
           'right_knee', 'right_forward_ankle', 'right_x', 'right_y', 'right_z', 'left_x', 
              'left_y', 'left_z', 'left_knee', 'left_forward_ankle', 'left_side_ankle', 'right_side_ankle']
Ar2MethodList = ['move_motor', 'setDirection', 'set_speed', 'current', 'setMinLimit', 'setMaxLimit', 'stopMotor']

Ar3List = ['left_shoulder_x', 'left_shoulder_y', 'left_shoulder_z', 'left_bicept']
Ar3MethodList = ['current', 'stopMotor', 'setSpeed', 'move']

Ar4List = ['head'] 
Ar4MethodList = ['servo_head', 'servo_mouth', 'servo_side_eye', 'servo_up_eye', 'servo_neck_side', 'servo_neck', 
                 'set_max_limit', 'set_min_limit']


while True:
    command = input("agiat$ ")
    
    if command == 'q':
        break
    
    lst_command = command.strip().split(" ")
    if len(lst_command) < 2 or len(lst_command) > 3 :
        print("You need to enter the correct number of parameters.")
        continue
    
    if lst_command[0] in Ar1List:
        if lst_command[1] in Ar1MethodList:
            ar1_ser.write(command.encode())
            
            while ar1_ser.in_waiting == 0:
                pass 
            
            ar1_ser.flush()
        else: 
            print("You need to enter a valid method for this Ar.")
            for i in Ar1MethodList:
                print(i)
            continue
                
    elif lst_command[0] in Ar2List:
        if lst_command[1] in Ar2MethodList:
            ar2_ser.write(command.encode())
            
            while ar2_ser.in_waiting == 0:
                pass 
            
            ar2_ser.flush()
        else:
            print("You need to enter a valid method for this Ar.")
            for i in Ar2MethodList:
                print(i)
            continue
                
    elif lst_command[0] in Ar3List:
        if lst_command[1] in Ar3MethodList:
            ar3_ser.write(command.encode())
            
            while ar3_ser.in_waiting == 0:
                pass 
            
            ar3_ser.flush()
        else:
            print("You need to enter a valid method for this Ar.")
            for i in Ar3MethodList:
                print(i)
            continue
    
    elif lst_command[0] in Ar4List:
        if lst_command[1] in Ar4MethodList:
            ar4_ser.write(command.encode())
            
            while ar4_ser.in_waiting == 0:
                pass 
            
            ar4_ser.flush()
        else:
            print("You need to enter a valid method for this Ar.")
            for i in Ar4MethodList:
                print(i)
            continue 
        
    else:
        print("UNKNOWN COMMAND FOR THE ROBOT")
        continue 
    
    

