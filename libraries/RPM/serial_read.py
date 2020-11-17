import serial
import os


ser = serial.Serial('COM6', 115200, timeout=10)
ser.flushInput()
ser.flushOutput()


text_file = open("./position4.txt", 'a')

while True:
    dataString = str(ser.readline())
    print(dataString)
    data = int(dataString.split(" ")[3],16)
    print (str(data))
    text_file.write(str(data) + '\n')
    text_file.flush()