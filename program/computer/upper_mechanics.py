import serial 
import time 
import cv2 
import os 

ar1_port = '/dev/ttyACM3' # Arduino Uno
ar2_port = '/dev/ttyACM1' # Arduino Mega
ar3_port = '/dev/ttyUSB0' # Arduino Uno
ar4_port = '/dev/ttyACM0' # Arduino Uno

ser = serial.Serial(ar1_port, 9600)

ser.flush()

Ar1List = ['left_hand', 'right_hand', 'rh', 'lh']
Ar1MethodList = ['open', 'close', 'finger_moving', 'servo_wrist']

Ar2List = ['head', 
           'right_knee', 'right_forward_ankle', 'right_x', 'right_y', 'right_z', 'left_x', 
              'left_y', 'left_z', 'left_knee', 'left_forward_ankle', 'left_side_ankle', 'right_side_ankle']
Ar2MethodList = ['move_motor', 'setDirection', 'set_speed', 'current', 'setMinLimit', 'setMaxLimit', 'stopMotor', 
                 'servo_head', 'servo_mouth', 'servo_side_eye', 'servo_up_eye', 'servo_neck_side', 'servo_neck', 
                 'set_max_limit', 'set_min_limit']

Ar3List = ['left_shoulder_x', 'left_shoulder_y', 'left_shoulder_z', 'left_bicept', 'current_la', 'error_la', 'la']
Ar3MethodList = ['current', 'stopMotor', 'setSpeed', 'move']

Ar4List = ['right_shoulder_x', 'right_shoulder_y', 'right_shoulder_z', 'right_bicept', 'current_ra', 'error_ra', 'ra'] 
Ar4MethodList = ['current', 'stopMotor', 'setSpeed', 'move']


while True:
    command = input("agiat$ ")
    
    if command == 'q':
        break
    
    lst_command = command.strip().split(" ")
    
    if lst_command[0] in Ar1List:
        if (lst_command[1] in Ar1MethodList) or \
            (lst_command[0] == 'rh' and lst_command[1].isnumeric()) or \
            (lst_command[0] == 'lh' and lst_command[1].isnumeric()):
            ser.write(command.encode())
            
            while ser.in_waiting == 0:
                pass 
            
            ser.flush()
        else: 
            print("You need to enter a valid method for this Ar.")
            for i in Ar1MethodList:
                print(i)
            continue
                
    elif lst_command[0] in Ar2List:
        if (lst_command[1] in Ar2MethodList) or \
            (lst_command[0]  == 'head' and lst_command[1].isnumeric()):
            ser.write(command.encode())
            
            while ser.in_waiting == 0:
                pass 
            
            ser.flush()
        else:
            print("You need to enter a valid method for this Ar.")
            for i in Ar2MethodList:
                print(i)
            continue
                
    elif lst_command[0] in Ar3List:
        if lst_command[0] == "current_la" or \
            lst_command[0] == "error_la" or \
            (lst_command[0] == 'la' and lst_command[1].isnumeric()) or \
            (lst_command[1] in Ar4MethodList) :
            ser.write(command.encode())
            
            while ser.in_waiting == 0:
                pass 
            
            ser.flush()
        
        else:
            print("You need to enter a valid method for this Ar.")
            for i in Ar3MethodList:
                print(i)
            continue
    
    elif lst_command[0] in Ar4List:
        if lst_command[0] == "current_ra" or \
            lst_command[0] == "error_ra" or \
            (lst_command[0] == 'ra' and lst_command[1].isnumeric()) or \
            (lst_command[1] in Ar4MethodList) :
                
            ser.write(command.encode())
            
            while ser.in_waiting == 0:
                pass 
            
            ser.flush()
        else:
            print("You need to enter a valid method for this Ar.")
            for i in Ar4MethodList:
                print(i)
            continue 
        
    else:
        print("UNKNOWN COMMAND FOR THE ROBOT")
        continue 
    
    

