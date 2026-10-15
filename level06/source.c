#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/ptrace.h>

bool	auth(char *login, int serial)
{
	int i; // [esp+14h] [ebp-14h]
	int calculated_serial; // [esp+18h] [ebp-10h]
	int len_login; // [esp+1Ch] [ebp-Ch]

	login[strcspn(login, "\n")] = 0;
	len_login = strnlen(login, 32);
	if (len_login <= 5 )
		return true;
	if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
	{
		puts("\x1B[32m.---------------------------.");
		puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
		puts("\x1B[32m'---------------------------'");
		return true;
	}
	else
	{
		calculated_serial = (login[3] ^ 4919) + 6221293;
		for ( i = 0; i < len_login; ++i )
		{
			if ( login[i] <= 31 )
				return true;
			calculated_serial += (calculated_serial ^ (unsigned int)login[i]) % 1337;
		}
		printf("cal: %d\n", calculated_serial);
		return serial != calculated_serial;
	}
}

int main(int argc, const char **argv, const char **envp)
{
	int serial; // [esp+2Ch] [ebp-24h] BYREF
	char login[32]; // [esp+30h] [ebp-20h] BYREF

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(login, 32, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	if (scanf("%d", &serial) != 1)
		return 1;
	if (auth(login, serial))
		return 1;

	puts("Authenticated!");
	system("/bin/sh");

	return 0;
}