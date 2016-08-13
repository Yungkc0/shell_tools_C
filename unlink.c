#include "all.h"

void usage(int status)
{
	puts("Usage: unlink FILE\n"
			"Call the unlink function to remove the specified FILE.\n");
	exit(status);
}

int main(int argc, char **argv)
{
	if (getopt_long(argc, argv, "", NULL, NULL) != -1)
		usage(EXIT_FAILURE);
	/* now optind is 1 */
	if (argc < optind + 1) {
		error(0, 0, "missing operand");
		usage(EXIT_FAILURE);
	}
	if (optind + 1 < argc) {
		error(0, 0, "extra operand `%s`", argv[optind + 1]);
		usage(EXIT_FAILURE);
	}

	if (unlink(argv[1]) != 0)
		error(EXIT_FAILURE, errno, "cannot unlink '%s'", argv[optind]);

	return EXIT_SUCCESS;
}
