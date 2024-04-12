import serial 

ser = serial.Serial("/dev/ttyACM1", 9600)

ser.flush() 

while True:
    command = input("Enter on or off: ")
    ser.write(command.encode())
    while ser.in_waiting == 0:
        pass 
    print(ser.readline().decode().strip())
    ser.flush()