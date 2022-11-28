import serial

ser = serial.Serial("COM3", 115200)

if ser.isOpen():
    ser.close()

ser.open()
sync = 0x10
aidan = 0x37
mode = 0x01
lrl = 0x3C
url = 0x01
Vent_PW = 0x01
Atr_PW = 0x01
Vent_sens = 0x01
Atr_sens = 0x01
Vent_RP = 0x01
MSR = 0x01
activity_thres = 0x01
resp_fact = 0x01
react_time = 0x01
rec_time = 0x01
Atr_RP = 0x01
Vent_Amp = 0x01
Atr_Amp = 0x01


message = bytearray()

message.append(sync)
message.append(aidan)
message.append(mode)
message.append(lrl)
message.append(url)
message.append(Vent_Amp)
message.append(Atr_Amp)
message.append(Vent_PW)
message.append(Atr_PW)
message.append(Vent_sens)
message.append(Atr_sens)
message.append(Atr_RP)
message.append(Vent_RP)
message.append(MSR)
message.append(activity_thres)
message.append(resp_fact)
message.append(react_time)
message.append(rec_time)

ser.write(message)
ser.close()

"""if (endian_checker == True):
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
vamp = struct.pack("f",float(patientData["value6"]))
vpw = struct.pack("<B",int(float(patientData["value7"])*10))
vrp = struct.pack("<H",int(patientData["value8"]))
arp = struct.pack("<H",int(patientData["value9"]))
pvarp = struct.pack("<B",int(patientData["value10"]))
hys = struct.pack("<B",int(patientData["value11"]))
rs = struct.pack("<B",int(patientData["value12"]))

if ((patientData["value13"]) == "V-Low"):
    at = struct.pack("<f",1.0) #Very Low activity
elif (((patientData["value13"]) == "Low")):
    at = struct.pack("<f",2.0) #Low Activity
elif ((patientData["value13"]) == "Med-Low"):
    at = struct.pack("<f",3.0) #Med-Low Activity
elif ((patientData["value13"]) == "Med"):
    at = struct.pack("<f",4.0) #Med Activity
elif ((patientData["value13"]) == "Med-High"):
    at = struct.pack("<f",5.0) #Med-High Activity
elif ((patientData["value13"]) == "High"):
    at = struct.pack("<f",6.0) #High Activity
elif ((patientData["value13"]) == "V-High"):
    at = struct.pack("<f",7.0) #Very High Activity

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
vamp = struct.pack("f",float(patientData["value6"]))
vpw = struct.pack(">B",int(float(patientData["value7"])*10))
vrp = struct.pack(">H",int(patientData["value8"]))
arp = struct.pack(">H",int(patientData["value9"]))
pvarp = struct.pack(">B",int(patientData["value10"]))
hys = struct.pack(">B",int(patientData["value11"]))
rs = struct.pack(">B",int(patientData["value12"]))

if ((patientData["value13"]) == "V-Low"):
    at = struct.pack(">f",1.0) #Very Low activity
elif (((patientData["value13"]) == "Low")):
    at = struct.pack(">f",2.0) #Low Activity
elif ((patientData["value13"]) == "Med-Low"):
    at = struct.pack(">f",3.0) #Med-Low Activity
elif ((patientData["value13"]) == "Med"):
    at = struct.pack(">f",4.0) #Med Activity
elif ((patientData["value13"]) == "Med-High"):
    at = struct.pack(">f",5.0) #Med-High Activity
elif ((patientData["value13"]) == "High"):
    at = struct.pack(">f",6.0) #High Activity
elif ((patientData["value13"]) == "V-High"):
    at = struct.pack(">f",7.0) #Very High Activity

rt = struct.pack(">B",int(patientData["value14"]))
res = struct.pack(">B",int(patientData["value15"]))
rct = struct.pack(">B",int(patientData["value16"]))
asen = struct.pack(">f",float(patientData["value17"]))
vsen = struct.pack(">f",float(patientData["value18"]))

print (type(Start),type(Fn_set),type(lrl), type(url), type(vamp), type(aamp), type(vpw), type(apw), type(vsen), type(asen), type(arp), type(vrp), type(msr), type(at), type(rt), type(res), type(rct))

print(int(patientData["value1"]))
print(int(patientData["value2"]))
print(int(patientData["value3"]))
print(float(patientData["value4"]))
print(int(float(patientData["value5"])*10))
print(float(patientData["value6"]))
print(int(float(patientData["value7"])*10))
print(int(patientData["value8"]))
print(int(patientData["value9"]))
print(int(patientData["value10"]))
print(int(patientData["value11"]))
print(int(patientData["value12"]))
print(patientData["value13"])
print(int(patientData["value14"]))
print(int(patientData["value15"]))
print(int(patientData["value16"]))
print(float(patientData["value17"]))
print(float(patientData["value18"]))"""