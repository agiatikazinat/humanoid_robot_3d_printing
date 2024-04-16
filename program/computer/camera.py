import serial 
import time 
import cv2 
import os 
from parameter import *

def camera(robot_status: RobotStatus):
    while robot_status.get_camera_status():
        time.sleep(0.5)
        success, frame = capture.read()
        if not success:
            break
        
        cv2.imshow('Frame', frame)
        # if cv2.waitKey(25) & 0xFF == ord('q'):
        #     break
    print(robot_status.get_camera_status())
    robot_status.camera_off()
    capture.release() 
    cv2.destroyAllWindows()
    
    