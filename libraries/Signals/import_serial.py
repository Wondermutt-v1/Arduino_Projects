import serial
import os


ser = serial.Serial('COM6', 115200, timeout=10)
ser.flushInput()
ser.flushOutput()


text_file = open("./position4.txt", 'a')

while True:
    dataString = ser.readline()
    print (dataString)
    data = int(dataString.split(" ")[4])
    print (str(data))
	#text_file.write(str(dataString) + '\n')
	text_file.flush()