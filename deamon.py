#!/usr/bin/env python
import psutil, serial, time

s = serial.Serial('COM22', 9600)

data = []

while True:
    cpu = psutil.cpu_percent()
    data.append(cpu)
    data = data[-10:]

    now = sum(data)/10
    now = int(now)
    s.write(chr(now))
    print(now, chr(now), s.readline())
    time.sleep(0.1)