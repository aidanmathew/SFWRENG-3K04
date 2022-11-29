
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
        mode = struct.pack("B",1)
    elif (patientData["pacingMode"] == "VOO"):
        mode = struct.pack("B",2)
    elif (patientData["pacingMode"] == "AAI"):
        mode = struct.pack("B",3)
    elif (patientData["pacingMode"] == "VVI"):
        mode = struct.pack("B",4)
    elif (patientData["pacingMode"] == "AOOR"):
        mode = struct.pack("B",5)
    elif (patientData["pacingMode"] == "VOOR"):
        mode = struct.pack("B",6)
    elif (patientData["pacingMode"] == "AAIR"):
        mode = struct.pack("B",7)
    elif (patientData["pacingMode"] == "VVIR"):
        mode = struct.pack("B",8)

    lrl = struct.pack("B",int(patientData["value1"]))
    url = struct.pack("B",int(patientData["value2"]))
    msr = struct.pack("B",int(patientData["value3"]))
    aamp = struct.pack("f",float(patientData["value4"]))
    apw = struct.pack("B",int(float(patientData["value5"])*10))
    vamp = struct.pack("f",float(patientData["value6"]))
    vpw = struct.pack("B",int(float(patientData["value7"])*10))
    vrp = struct.pack("H",int(patientData["value8"]))
    arp = struct.pack("H",int(patientData["value9"]))
    pvarp = struct.pack("B",int(patientData["value10"]))
    hys = struct.pack("B",int(patientData["value11"]))
    rs = struct.pack("B",int(patientData["value12"]))


    if (((patientData["value13"]) == "Low")):
        at = struct.pack("f",2.0) #Low Activity
    elif ((patientData["value13"]) == "Med-Low"):
        at = struct.pack("f",3.0) #Med-Low Activity
    elif ((patientData["value13"]) == "Med"):
        at = struct.pack("f",4.0) #Med Activity
    elif ((patientData["value13"]) == "Med-High"):
        at = struct.pack("f",5.0) #Med-High Activity
    elif ((patientData["value13"]) == "High"):
        at = struct.pack("f",6.0) #High Activity
    elif ((patientData["value13"]) == "V-High"):
        at = struct.pack("f",7.0) #Very High Activity
    else:
        at = struct.pack("f",1.0) #Very Low Activity

    rt = struct.pack("B",int(patientData["value14"]))
    res = struct.pack("B",int(patientData["value15"]))
    rct = struct.pack("B",int(patientData["value16"]))
    asen = struct.pack("f",float(patientData["value17"]))
    vsen = struct.pack("f",float(patientData["value18"]))


print("______________________")


print("Mode = ", mode[0])
print("Low Rate Limit = ", lrl[0])
print("Upper Rate Limit = ", url[0])
vamp1 = struct.unpack("f", vamp)
print("V-Amp = " , round(vamp1[0],1))
aamp1 = struct.unpack("f", aamp)
print("A-Amp = ", round(aamp1[0],1))
print("VPW = ", vpw[0])
print("APW = ", apw[0])
vsen1 = struct.unpack("f",vsen)
print("V-Sen = ", vsen1[0])
asen1 = struct.unpack("f",asen)
print("A-Sen = ", asen1[0])
arp1 = struct.unpack("H",arp)
print("ARP = ", arp1[0])
vrp1 = struct.unpack("H",vrp)
print("VRP = ", vrp1[0])
print("MSR = " , msr[0])
at1 = struct.unpack("f",at)
print("Activty Threshold = ", at1[0])
print("Reaction Time = ", rt[0])
print("Response Time = ", res[0])
print("Recovery Time = ", rct[0])


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
#this block returns the data from Pin A0 and Pin A1 - the board need to be flashed with the corresponding simulink
#file for this block to be excetued.
    for i in range(10):
        pacemaker.write(Signal_echo)

        data = pacemaker.read(16)
        pin1 = struct.unpack("d",data[0:8])[0]
        pin2 = struct.unpack("d",data[8:16])[0]
        print("Pin 1", pin1)
        print("Pin 2",pin2)

    #this block writes the data from Pin A0 and Pin A1 to a txt file, which will be read by the e-gram in dcmFinal.py
        with open('data.txt', 'a') as f:
            f.write(str(pin1) + "\n")
            f.write(str(pin2) + "\n")


#this block reads back the data that is being send from the DCM - Uncommet this block to see it function
#The board needs to be flash with the corresponding simulink for this block to execute
    """
    pacemaker.write(Signal_echo)
    data = pacemaker.read(33)

    mode2 = data[0]
    lrl2 = data[1]
    url2 = data[2]
    vamp2 = struct.unpack("f",data[3:7])[0]
    aamp2 = struct.unpack("f",data[7:11])[0]
    vpw2 = data[11]
    apw2 = data[12]
    vsen2 = struct.unpack("f",data[13:17])[0]
    asen2 = struct.unpack("f",data[17:21])[0]
    arp2 = struct.unpack("H",data[21:23])[0]
    vrp2 = struct.unpack("H",data[23:25])[0]
    msr2 = data[25]
    at2 = struct.unpack("f",data[26:30])[0]
    res2 = data[30]
    rt2 = data[31]
    rct2 = data[32]


print("Mode = ", mode2)
print("Low Rate Limit = ", lrl2)
print("Upper Rate Limit = ", url2)
print("V-Amp = ", vamp2)
print("A-Amp = ", aamp2)
print("VPW = ", vpw2)
print("APW = ", apw2)
print("V-Sen = ", vsen2)
print("A-Sen = ", asen2)
print("ARP = ", arp2)
print("VRP = ", vrp2)
print("MSR = ", msr2)
print("Activty Threshold = ", at2)
print("Reaction Time = ", rt2)
print("Response Time = ", res2)
print("Recovery Time = ", rct2)"""






