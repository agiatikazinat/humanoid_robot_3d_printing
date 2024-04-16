import threading 
from talking import * 
from parameter import * 
from camera import * 

    
if __name__ == '__main__':
    
    awake()
    
    t1 = threading.Thread(target = camera)
    t2 = threading.Thread(target=talking)
    
    t1.start()
    t2.start()
    
    if sleep:
        t1.join()
        t2.join()
    
    