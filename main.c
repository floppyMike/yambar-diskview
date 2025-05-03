#include <stdlib.h>
#include <stdio.h>
#include <sys/statvfs.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <path> <interval_seconds>\n", argv[0]);
		return EXIT_FAILURE;
	}

	const char *path = argv[1];

	char *endptr = NULL;
	unsigned long interval = strtoul(argv[2], &endptr, 10);
	if (*endptr != '\0') { // Should be just a singular number 
		fprintf(stderr, "Error: invalid interval '%s'\n", argv[2]);
		return EXIT_FAILURE;
	}
	if (interval == 0) { // Should be valid
		fprintf(stderr, "Error: interval must be a number and > 0\n");
		return EXIT_FAILURE;
	}

	struct statvfs fs;
	while (1) {
		if (statvfs(path, &fs) < 0) {
			perror("statvfs");
			return EXIT_FAILURE;
		}

		printf("%lu\n", fs.f_bavail * fs.f_frsize);
		sleep(interval);
	}

	return EXIT_SUCCESS;
}
