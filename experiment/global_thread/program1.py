import threading 
from program1 import *

global internet
internet = 1


def test2():
    global internet
    internet+= 1
def test1():
    global internet 
    internet = 2*3


if __name__ ==  "__main__":
    t1 = threading.Thread(target=test1)
    t2  = threading.Thread(target=test2)
    
    print("Before: ", internet)
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print("After : ", internet)