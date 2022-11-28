import serial

ser = serial.Serial("COM4", 115200)

if ser.isOpen():
    ser.close()

ser.open()
sync = 0x10
aidan = 0x37
mode = 0x02
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