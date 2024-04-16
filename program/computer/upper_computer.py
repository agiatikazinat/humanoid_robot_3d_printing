import threading 
from talking import * 
from parameter import * 
from camera import * 

    
if __name__ == '__main__':
    camera_switch = Camera()
    while sleep:
        r = sr.Recognizer()   # Initialize recognizer class (for
        with sr.Microphone() as source:
            print("Sleeping.z.z.z...")
            r.pause_threshold = 1
            audio = r.listen(source)

        try:
            query = r.recognize_google(audio, language='en-in')
            print(query)
            if wake_word in query.lower():
                starting()
                sleep = False
                camera_switch.turn_on()
        except Exception as e:
            print(e)
    print(sleep)
    t1 = threading.Thread(target=camera, args=(camera_switch,))
    t2 = threading.Thread(target=talking, args = (camera_switch,))
    
    t1.start()
    t2.start()
    
    if sleep:
        t1.join()
        t2.join()
        
    print("DONE")
    speak('second experiment done')
    
    