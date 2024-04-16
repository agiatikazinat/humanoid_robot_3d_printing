import pyttsx3 
import cv2 

camera_port = "/dev/video0"
wake_word = "scott"
engine = pyttsx3.init() 
capture = cv2.VideoCapture(camera_port) 


class RobotStatus():

    def __init__(self):
        self._sleep = True 
        self._camera_status = False
    
    def awake(self) -> None:
        self._sleep = False 
    
    def sleep(self) -> None:
        self._sleep = True 
    
    def get_sleep_status(self) -> bool:
        return self._sleep
    
    def get_camera_status(self) -> bool:
        return self._camera_status
    
    def camera_on(self) -> None:
        self._camera_status = True 
    
    def camera_off(self) -> None: 
        self._camera_status = False
    
