import sys
import re
pat =  re.compile(r'(\(.*\)).*')
p = re.compile(r'\W+')
f = open('atmega2560.csv', 'r')
t = ' '

lines = f.readlines()
lines.reverse()

for line in lines:
	bigfield = ''
	line = line.strip('\n')
	m = line.split(',')
	if ( m[1].find('Reserved') < 0):
		for field in m[2:9]:
			if(len(field) > 9):
				bigfield = field
		if ( len(bigfield) > 0 ):
			print('#define %-9s %6s /* %-79s */' % (m[1],m[0],bigfield))
		else:
			print()
			print('#define %-9s %6s /* %-9s|%-9s|%-9s|%-9s|%-9s|%-9s|%-9s|%-9s */' % (m[1],m[0],m[2],m[3],m[4],m[5],m[6],m[7],m[8],m[9]))
			i = 7
			for bit in m[2:10]:
				if len(bit)>1:
					print('#define %-9s (1<<%d)' % (bit,i))
				i-=1
	

