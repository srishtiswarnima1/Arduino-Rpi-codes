import smbus
import time

bus = smbus.SMBus(1)

add_ar = 0x04

def sendSignal(value):
    bus.write_byte_data(add_ar,0,value)
    return -1

def read_Signal():
    flag = bus.read_byte(add_ar)
    return flag

while True:
    var = input("Enter 1/0:")
    sendSignal(var)

    time.sleep(0.5)

    flag = read_Signal()
    print(flag)
