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
import sys


COMPORT = 'COM3' #change me to the correct COM port
Start = b'\x16'
SYNC = b'\x22'
Fn_set = b'\x55'

    
global mode,lrl,url,msr,aamp,apw,vamp,vpw,vrp,arp,pvarp,hys,rs,at,rt,res,rct,asen,vsen,signal_set,Signal_echo
username = "jibin"
userFilepath = "./user"
patientDatabase = "/database.json"
patientDataFile = "/"+username+".json"

patientData = {}

def endian_checker():
    if sys.byteorder == "little":
        return True
    else:
        return False

with open(userFilepath+patientDataFile, "r") as iFile:
    # loading the user file date
    patientData = json.load(iFile)
    if (patientData["pacingMode"] == "AOO"):
        mode = 1
    elif (patientData["pacingMode"] == "VOO"):
        mode = 2
    elif (patientData["pacingMode"] == "AAI"):
        mode = 3
    elif (patientData["pacingMode"] == "VVI"):
        mode = 4
    elif (patientData["pacingMode"] == "AOOR"):
        mode = 5
    elif (patientData["pacingMode"] == "VOOR"):
        mode = 6
    elif (patientData["pacingMode"] == "AAIR"):
        mode = 7
    elif (patientData["pacingMode"] == "VVIR"):
        mode = 8

    lrl = int(patientData["value1"])
    url = int(patientData["value2"])
    msr = int(patientData["value3"])
    aamp = float(patientData["value4"])
    apw = float(patientData["value5"])
    vamp = float(patientData["value6"])
    vpw = float(patientData["value7"])
    vrp = int(patientData["value8"])
    arp = int(patientData["value9"])
    pvarp = int(patientData["value10"])
    hys = int(patientData["value11"])
    rs = int(patientData["value12"])

    if ((patientData["value13"]) == "V-Low"):
        at = 1 #Very Low activity
    elif (((patientData["value13"]) == "Low")):
        at = 2 #Low Activity
    elif ((patientData["value13"]) == "Med-Low"):
        at = 3 #Med-Low Activity
    elif ((patientData["value13"]) == "Med"):
        at = 4 #Med Activity
    elif ((patientData["value13"]) == "Med-High"):
        at = 5 #Med-High Activity
    elif ((patientData["value13"]) == "High"):
        at = 6 #High Activity
    elif ((patientData["value13"]) == "V-High"):
        at = 7 #Very High Activity

    rt = int(patientData["value14"])
    res = int(patientData["value15"])
    rct = int(patientData["value16"])
    asen = float(patientData["value17"])
    vsen = float(patientData["value18"])
    #print (type(Start),type(Fn_set),type(lrl), type(url), type(vamp), type(aamp), type(vpw), type(apw), type(vsen), type(asen), type(arp), type(vrp), type(msr), type(at), type(rt), type(res), type(rct))

if (endian_checker() == True):
    Signal_set = struct.pack("<ccBBffffffHHBBBBB",Start, Fn_set, lrl, url, vamp, aamp, vpw, apw, vsen, asen, arp, vrp, msr, at, rt, res, rct) 
    Signal_echo = struct.pack("<ccBBffffffHHBBBBB",Start, SYNC, lrl, url, vamp, aamp, vpw, apw, vsen, asen, arp, vrp, msr, at, rt, res, rct)
else:
    Signal_set = struct.pack(">ccBBffffffHHBBBBB",Start, Fn_set, lrl, url, vamp, aamp, vpw, apw, vsen, asen, arp, vrp, msr, at, rt, res, rct) 
    Signal_echo = struct.pack(">ccBBffffffHHBBBBB",Start, SYNC, lrl, url, vamp, aamp, vpw, apw, vsen, asen, arp, vrp, msr, at, rt, res, rct)


print (Signal_set)
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
