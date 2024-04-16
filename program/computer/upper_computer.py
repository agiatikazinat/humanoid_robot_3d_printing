import threading 
from talking import * 
from parameter import * 
from camera import * 

    
if __name__ == '__main__':
    robot_status = RobotStatus()
    wake_up(robot_status) #waking up the robot

    t1 = threading.Thread(target=camera, args=(robot_status,))
    t2 = threading.Thread(target=talking, args = (robot_status,))
    
    t1.start()
    t2.start()
    
    if robot_status.get_sleep_status():
        t1.join()
        t2.join()
        
    print("DONE")
    speak('second experiment done')
    
    