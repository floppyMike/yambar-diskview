#include <stdlib.h>
#include <stdio.h>
#include <sys/statvfs.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <interval_seconds> <path1> [path2 ... pathN]\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *endptr = NULL;
	unsigned long interval = strtoul(argv[1], &endptr, 10);
	if (*endptr != '\0') { // Should be just a singular number and valid
		fprintf(stderr, "Error: invalid interval '%s'\n", argv[1]);
		return EXIT_FAILURE;
	}
	if (interval == 0) { // Should have a duration
		fprintf(stderr, "Error: interval must be > 0\n");
		return EXIT_FAILURE;
	}

	const int num_paths = argc - 2;
	char **paths = &argv[2];

	struct statvfs fs;

	while (1) {
		for (int i = 0; i < num_paths; ++i) {
			if (statvfs(paths[i], &fs) < 0) {
				fprintf(stderr, "statvfs('%s') failed: ", paths[i]);
				perror("");
				return EXIT_FAILURE;
			}

			printf("%lu\n", fs.f_bavail * fs.f_frsize);
		}

		sleep(interval);
	}

	return EXIT_SUCCESS;
}
