#########################################
# ProgramAB.py
# more info @: http://myrobotlab.org/service/ProgramAB
#########################################

import time 

# create a ProgramAB service and start a session
alice = Runtime.start("alice", "ProgramAB")
# supported language list : https://github.com/MyRobotLab/aiml/tree/master/bots
alice.startSession("username","Alice")

print(alice.getResponse("How are you?"))

# create a Speech service
mouth = Runtime.start("mouth", "MarySpeech")
# create a route which sends published Responses to the
# mouth.speak(String) method
alice.attach(mouth)

alice.getResponse(u"What is new?")
time.sleep(3)
alice.getResponse(u"Tell me a joke?")
time.sleep(3)
alice.getResponse(u"What time is it?")
time.sleep(3)
# UTF8 test
alice.getResponse(u"こんにちは")
