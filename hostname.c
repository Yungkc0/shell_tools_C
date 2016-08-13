#include "all.h"

#define PROGRAM_NAME "hostname"
/* according to man page, POSIX.1 guarantees that "Host names (not
 * including the terminating null byte) are limited to HOST_NAME_MAX
 * bytes". On Linux, HOST_NAME_MAX is defined with the value 64. */
#define HOST_NAME_MAX 65

void usage(int status)
{
	printf("Usage: %s [NAME]\n"
			"Print or set the hostname of the current system.\n\n",
			PROGRAM_NAME);
	exit(status);
}

int main(int argc, char **argv)
{
	char hostname[HOST_NAME_MAX];

	if (getopt_long(argc, argv, "", NULL, NULL) != -1)
		usage(EXIT_FAILURE);

	if (argc == optind + 1) {
		char const *name = argv[optind];
		if (sethostname(name, strlen(name)) != 0)
			error(EXIT_FAILURE, errno, "cannot set name to `%s`", name);
	}
	if (argc <= optind) {
		if (gethostname(hostname, HOST_NAME_MAX) != 0)
			error(EXIT_FAILURE, errno, "cannot determine hostname");
		printf("%s\n", hostname);
	}
	if (optind + 1 < argc) {
		error(0, 0, "extra operand `%s`", argv[optind + 1]);
		usage(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
