#include <fcntl.h>

unsigned __int64  log_wrapper(FILE *a1, const char *a2, const char *a3)
{
	char dest[264]; // [rsp+20h] [rbp-110h] BYREF
	unsigned __int64 v7; // [rsp+128h] [rbp-8h]

	v7 = __readfsqword(0x28u);
	strcpy(dest, a2);
	snprintf(&dest[strlen(dest)], 254 - strlen(dest), a3);
	dest[strcspn(dest, "\n")] = 0;
	fprintf(a1, "LOG: %s\n", dest);
	return __readfsqword(0x28u) ^ v7;
}

//----- (00000000004009F0) ----------------------------------------------------
int main(int argc, const char **argv, const char **envp)
{
	FILE *v5; // [rsp+28h] [rbp-88h]
	FILE *stream; // [rsp+30h] [rbp-80h]
	int fd; // [rsp+38h] [rbp-78h]
	char buf; // [rsp+3Fh] [rbp-71h] BYREF
	char dest[104]; // [rsp+40h] [rbp-70h] BYREF
	unsigned __int64 v10; // [rsp+A8h] [rbp-8h]

	v10 = __readfsqword(0x28u);
	buf = -1;
	if ( argc != 2 )
		printf("Usage: %s filename\n", *argv);
	v5 = fopen("./backups/.log", "w");
	if ( v5 == nullptr )
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(v5, "Starting back up: ", argv[1]);
	stream = fopen(argv[1], "r");
	if ( stream == nullptr )
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	strcpy(dest, "./backups/");
	strncat(dest, argv[1], 99 - strlen(dest));
	fd = open(dest, 193, 432);
	if ( fd < 0 )
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}
	while ( 1 )
	{
		buf = fgetc(stream);
		if ( buf == -1 )
			break;
		write(fd, &buf, 1u);
	}
	log_wrapper(v5, "Finished back up ", argv[1]);
	fclose(stream);
	close(fd);
	return 0;
}