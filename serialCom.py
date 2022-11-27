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

    if (endian_checker == True):
        if (patientData["pacingMode"] == "AOO"):
            mode = struct.pack("<B",1)
        elif (patientData["pacingMode"] == "VOO"):
            mode = struct.pack("<B",2)
        elif (patientData["pacingMode"] == "AAI"):
            mode = struct.pack("<B",3)
        elif (patientData["pacingMode"] == "VVI"):
            mode = struct.pack("<B",4)
        elif (patientData["pacingMode"] == "AOOR"):
            mode = struct.pack("<B",5)
        elif (patientData["pacingMode"] == "VOOR"):
            mode = struct.pack("<B",6)
        elif (patientData["pacingMode"] == "AAIR"):
            mode = struct.pack("<B",7)
        elif (patientData["pacingMode"] == "VVIR"):
            mode = struct.pack("<B",8)

        lrl = struct.pack("<B",int(patientData["value1"]))
        url = struct.pack("<B",int(patientData["value2"]))
        msr = struct.pack("<B",int(patientData["value3"]))
        aamp = struct.pack("<f",float(patientData["value4"]))
        apw = struct.pack("<B",int(float(patientData["value5"])*10))
        vamp = struct.pack("<f",float(patientData["value6"]))
        vpw = struct.pack("<H",int(float(patientData["value7"])*10))
        vrp = struct.pack("<H",int(patientData["value8"]))
        arp = struct.pack("<B",int(patientData["value9"]))
        pvarp = struct.pack("<B",int(patientData["value10"]))
        hys = struct.pack("<B",int(patientData["value11"]))
        rs = struct.pack("<B",int(patientData["value12"]))

        if ((patientData["value13"]) == "V-Low"):
            at = struct.pack("<f",float(1)) #Very Low activity
        elif (((patientData["value13"]) == "Low")):
            at = struct.pack("<f",float(2)) #Low Activity
        elif ((patientData["value13"]) == "Med-Low"):
            at = struct.pack("<f",float(3)) #Med-Low Activity
        elif ((patientData["value13"]) == "Med"):
            at = struct.pack("<f",float(4)) #Med Activity
        elif ((patientData["value13"]) == "Med-High"):
            at = struct.pack("<f",float(5)) #Med-High Activity
        elif ((patientData["value13"]) == "High"):
            at = struct.pack("<f",float(6)) #High Activity
        elif ((patientData["value13"]) == "V-High"):
            at = struct.pack("<f",float(7)) #Very High Activity

        rt = struct.pack("<B",int(patientData["value14"]))
        res = struct.pack("<B",int(patientData["value15"]))
        rct = struct.pack("<B",int(patientData["value16"]))
        asen = struct.pack("<f",float(patientData["value17"]))
        vsen = struct.pack("<f",float(patientData["value18"]))
    else:
        if (patientData["pacingMode"] == "AOO"):
            mode = struct.pack(">B",1)
        elif (patientData["pacingMode"] == "VOO"):
            mode = struct.pack(">B",2)
        elif (patientData["pacingMode"] == "AAI"):
            mode = struct.pack(">B",3)
        elif (patientData["pacingMode"] == "VVI"):
            mode = struct.pack(">B",4)
        elif (patientData["pacingMode"] == "AOOR"):
            mode = struct.pack(">B",5)
        elif (patientData["pacingMode"] == "VOOR"):
            mode = struct.pack(">B",6)
        elif (patientData["pacingMode"] == "AAIR"):
            mode = struct.pack(">B",7)
        elif (patientData["pacingMode"] == "VVIR"):
            mode = struct.pack(">B",8)
        
        lrl = struct.pack(">B",int(patientData["value1"]))
        url = struct.pack(">B",int(patientData["value2"]))
        msr = struct.pack(">B",int(patientData["value3"]))
        aamp = struct.pack(">f",float(patientData["value4"]))
        apw = struct.pack(">B",int(float(patientData["value5"])*10))
        vamp = struct.pack(">f",float(patientData["value6"]))
        vpw = struct.pack(">B",int(float(patientData["value7"])*10))
        vrp = struct.pack(">H",int(patientData["value8"]))
        arp = struct.pack(">H",int(patientData["value9"]))
        pvarp = struct.pack(">B",int(patientData["value10"]))
        hys = struct.pack(">B",int(patientData["value11"]))
        rs = struct.pack(">B",int(patientData["value12"]))

        if ((patientData["value13"]) == "V-Low"):
            at = struct.pack(">f",float(1)) #Very Low activity
        elif (((patientData["value13"]) == "Low")):
            at = struct.pack(">f",float(2)) #Low Activity
        elif ((patientData["value13"]) == "Med-Low"):
            at = struct.pack(">f",float(3)) #Med-Low Activity
        elif ((patientData["value13"]) == "Med"):
            at = struct.pack(">f",float(4)) #Med Activity
        elif ((patientData["value13"]) == "Med-High"):
            at = struct.pack(">f",float(5)) #Med-High Activity
        elif ((patientData["value13"]) == "High"):
            at = struct.pack(">f",float(6)) #High Activity
        elif ((patientData["value13"]) == "V-High"):
            at = struct.pack(">f",float(7)) #Very High Activity

        rt = struct.pack(">B",int(patientData["value14"]))
        res = struct.pack(">B",int(patientData["value15"]))
        rct = struct.pack(">B",int(patientData["value16"]))
        asen = struct.pack(">f",float(patientData["value17"]))
        vsen = struct.pack(">f",float(patientData["value18"]))

#print (type(Start),type(Fn_set),type(lrl), type(url), type(vamp), type(aamp), type(vpw), type(apw), type(vsen), type(asen), type(arp), type(vrp), type(msr), type(at), type(rt), type(res), type(rct))

"""print("Mode = " + str(struct.unpack("B",mode)[0]))
print("Low Rate Limit = " + str(lrl[0]))
print("Upper Rate Limit = " + str(url[0]))
print("V-Amp = " + str(vamp[0]))
print("A-Amp = " + str(aamp[0]))
print("VPW = " + str(vpw[0]))
print("APW = " + str(apw[0]))
print("V-Sen = " + str(vsen[0]))
print("A-Sen = " + str(asen[0]))
print("ARP = " + str(arp[0]))
print("VRP = " + str(vrp[0]))
print("MSR = " + str(msr[0]))
print("Activty Threshold = " + str(at[0]))
print("Reaction Time = " + str(rt[0]))
print("Response Time = " + str(res[0]))
print("Recovery Time = " + str(rct[0]))"""


Signal_set = Start+Fn_set+mode+lrl+url+vamp+aamp+vpw+apw+vsen+asen+arp+vrp+msr+at+res+rt+rct 
Signal_echo = Start+SYNC+mode+lrl+url+vamp+aamp+vpw+apw+vsen+asen+arp+vrp+msr+at+res+rt+rct

print ("_____________")
print (Signal_set)
print ("_____________")
print (Signal_echo)
print ("_____________")
with serial.Serial(COMPORT, 115200) as pacemaker:
    pacemaker.write(Signal_set)

print("From the board:")
with serial.Serial(COMPORT, 115200) as pacemaker:
    
    pacemaker.write(Signal_echo)

    data = pacemaker.read(33)

    print("HI")

    mode2 = data[0]
    lrl2 = data[1]
    url2 = data[2]
    vamp2 = struct.unpack("f",data[3:7])
    aamp2 = struct.unpack("f",data[7:11])
    vpw2 = data[11]
    apw2 = data[12]
    vsen2 = struct.unpack("f",data[13:17])
    asen2 = struct.unpack("f",data[17:21])
    arp2 = struct.unpack("H",data[21:23])
    vrp2 = struct.unpack("H",data[23:25])
    msr2 = data[25]
    at2 = struct.unpack("f",data[26:30])
    res2 = data[30]
    rt2 = data[31]
    rct2 = data[32]

    #print(mode2[0])





