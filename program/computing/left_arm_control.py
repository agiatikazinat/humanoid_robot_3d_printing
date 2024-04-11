import serial 
import time 
import os 


ar3_port = '/dev/ttyUSB0'
ar3_ser = serial.Serial(ar3_port, 9600)
ar3_ser.flush()

motor_names = ['left_shoulder_x', 'left_shoulder_y', 'left_shoulder_z', 'left_bicept']
methods = ['current', 'stopMotor', 'setSpeed', 'move']

print("Enter the command in the format: 'MotorName Method Parameter'")

while True:
    command = input("Enter a command (q to quit): ")
    
    if command == 'q':
        break
    # check if the command is valid or not
    command_lst = command.split(' ')
    if len(command_lst) < 2 or len(command_lst) > 3:
        print("Invalid Command! Please enter in the correct format.")
        continue
    if command_lst[0] not in motor_names:
        print('You MUST choose one of the following motors')
        for i in motor_names:
            print(i)
    if command_lst[1] not in methods:
        print("You mUST choost one of the methods: ")
        for j in methods:
            print(j)
    ar3_ser.write(command.encode('utf-8'))

    

    ar3_ser.flush()


