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

capture_char = '\x1A'
playback_char = '\x19' 
number_bytes_char = '\x0e'
number_of_bytes_pattern='Bytes stored: \d{1,4}'
inter_character_delay=.01
out = ''

# Send control-N to request for number of bytes currently stored in EEPROM
ser.write(number_bytes_char)
out = ''
time.sleep(.1)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)

# Send control-Z to turn capture on
print("Turn capture on")
ser.write(capture_char)
out = ''
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)


# Request the number of bytes in the EEPROM. Should be 0 at this point.
ser.write(number_bytes_char)
out = ''
time.sleep(.1)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)


# Send data to be written to the EEPROM. Each byte is echoed back.
# Only send a single byte at a time so this ends up being multiples
# of 0-9 or some other single character range.
print("Writing data")
for tens_of_bytes in range(0,409):
	for count in range(0,10):
		ser.write(count)
		dataIn = ''
		time.sleep(inter_character_delay)
		while ser.inWaiting() > 0:
			dataIn += ser.read()

# Get the number of bytes store in the EEPROM
print("Number of bytes")
ser.write(number_bytes_char)
out = ''
time.sleep(.1)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)

# Exceed the 4096 EEPROM capacity to test that this is not allowed.
for count in range(0,10):
	ser.write(count)
	time.sleep(inter_character_delay)
	while ser.inWaiting() > 0:
		dataIn += ser.read()

# Get the number of bytes store in the EEPROM
print("Number of bytes")
ser.write(number_bytes_char)
out = ''
time.sleep(.1)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)


# Send control-Y to get the contents of the EEPROM.
ser.flushInput()
print("Playback")
ser.write(playback_char)
out = ''
# Had to set this high to get all of the data. Not sure why.
time.sleep(5)
while ser.inWaiting() > 0:
	out += ser.read()
print("Number of chars received: %d" % len(out))
print out

# Send the control-Z again to turn off capture.
print("Capture off")
ser.write(capture_char)
out = ''
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print("Error: Received unexpected output")

time.sleep(2)
# Get the number of bytes store in the EEPROM
print("Number of bytes")
ser.write(number_bytes_char)
out = ''
time.sleep(2)
while ser.inWaiting() > 0:
	out += ser.read()
if out != '':
	print(">>" + out)


