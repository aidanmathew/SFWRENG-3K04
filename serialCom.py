"""For Aidan's computer the port was found to be COM4
frdm_port = serial.Serial('COM4')
print(frdm_port)
print(frdm_port.port)
print()"""

import serial
import serial.tools.list_ports
import struct
import time as t
import json
import string

COMPORT = 'COM4' #change me to the correct COM port
Start = b'\x16'
SYNC = b'\x22'
Fn_set = b'\x55'


def readPatientData(self, username):
     self.patientDataFile = "/"+username+".json"
     self.patientData = {}
     with open(self.userFilepath+self.patientDataFile, "r") as iFile:
        # loading the user file date
        self.patientData = json.load(iFile)

        global mode, lrl,url,msr,aamp,apw,vamp,vpw,vrp,arp,pvarp,hys,rs,at,rt,res,rct

        if (self.patientData["pacingMode"] == "AOO"):
            mode = struct.pack("B",1)
        elif (self.patientData["pacingMode"] == "VOO"):
            mode = struct.pack("B",2)
        elif (self.patientData["pacingMode"] == "AAI"):
            mode = struct.pack("B",3)
        elif (self.patientData["pacingMode"] == "VVI"):
            mode = struct.pack("B",4)
        elif (self.patientData["pacingMode"] == "AOOR"):
            mode = struct.pack("B",5)
        elif (self.patientData["pacingMode"] == "VOOR"):
            mode = struct.pack("B",6)
        elif (self.patientData["pacingMode"] == "AAIR"):
            mode = struct.pack("B",7)
        elif (self.patientData["pacingMode"] == "VVIR"):
            mode = struct.pack("B",8)

        lrl = struct.pack("B",int(self.patientData["value1"]))
        url = struct.pack("B",int(self.patientData["value2"]))
        msr = struct.pack("B",int(self.patientData["value3"]))
        aamp = struct.pack("f",float(self.patientData["value4"]))
        apw = struct.pack("f",float(self.patientData["value5"]))
        vamp = struct.pack("f",float(self.patientData["value6"]))
        vpw = struct.pack("f",float(self.patientData["value7"]))
        vrp = struct.pack("B",int(self.patientData["value8"]))
        arp = struct.pack("B",int(self.patientData["value9"]))
        pvarp = struct.pack("B",int(self.patientData["value10"]))
        hys = struct.pack("B",int(self.patientData["value11"]))
        rs = struct.pack("B",int(self.patientData["value12"]))

        if ((self.patientData["value13"]) == "V-Low"):
            at = struct.pack("B",1) #Very Low activity
        elif (((self.patientData["value13"]) == "Low")):
            at = struct.pack("B",2) #Low Activity
        elif ((self.patientData["value13"]) == "Med-Low"):
            at = struct.pack("B",3) #Med-Low Activity
        elif ((self.patientData["value13"]) == "Med"):
            at = struct.pack("B",4) #Med Activity
        elif ((self.patientData["value13"]) == "Med-High"):
            at = struct.pack("B",5) #Med-High Activity
        elif ((self.patientData["value13"]) == "High"):
            at = struct.pack("B",6) #High Activity
        elif ((self.patientData["value13"]) == "V-High"):
            at = struct.pack("B",7) #Very High Activity

        rt = struct.pack("B",int(self.patientData["value14"]))
        res = struct.pack("B",int(self.patientData["value15"]))
        rct = struct.pack("B",int(self.patientData["value16"]))


Signal_set = Start + Fn_set + lrl + url + vamp + aamp + vpw + apw*26
Signal_echo = Start + SYNC + lrl + url*26

with serial.Serial(COMPORT, 115200) as pacemaker:
    pacemaker.write(Signal_set)
    t.sleep(2)

print("From the board:")
with serial.Serial(COMPORT, 115200) as pacemaker:
    pacemaker.write(Signal_echo)
    t.sleep(2)
    data = pacemaker.read(6)
    test0 = data[0]
    testfloat =  struct.unpack("f", data[1:5])[0]
    test1 = data[5]

    print("first: ",test0)     #69
    print("first: ",testfloat) #4.20
    print("first: ",test1)     #21
