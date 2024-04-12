import serial 

ser = serial.Serial("COM4", 9600)

ser.flush() 

while True:
    command = input("Enter on or off: ")
    ser.write(command.encode('utf-8'))
    while ser.in_waiting == 0:
        pass 
    print(ser.readline().decode().strip())
    ser.flush()