import time
import serial
import os,sys

# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
	port=6,
	baudrate=9600,
	parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
)

ser.close()
ser.open()
ser.isOpen()

#f = open('test_file.txt','r')
#data = f.readlines();
test_string = (1,2,3,4,5,6,7,8,9,0)
capture_char = '\x1A'
playback_char = '\x19' 
number_bytes_char = '\x0e'
out = ''
# get keyboard input
# send the character to the device
ser.write(number_bytes_char)
out = ''
time.sleep(.1)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)
time.sleep(5)

print("Turn capture on")
ser.write(capture_char)
out = ''
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)

ser.write(number_bytes_char)
out = ''
time.sleep(.1)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)


print("Writing data")
for tens_of_bytes in range(0,409):
	for count in range(0,10):
		ser.write(count)
		out = ''
		time.sleep(.01)
		while ser.inWaiting() > 0:
			out += ser.read()
		if out != '':
			print(">>" + out)

for count in range(0,10):
	ser.write(count)
	out = ''
	time.sleep(.01)
	while ser.inWaiting() > 0:
		out += ser.read()
	if out != '':
		print(">>" + out)

print("Playback")
ser.write(playback_char)
out = ''
time.sleep(5)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)
print("Number of chars received: %d" % len(out))

print("Capture off")
ser.write(capture_char)
out = ''
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)

time.sleep(2)
print("Number of bytes")
ser.write(number_bytes_char)
out = ''
time.sleep(.1)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)


