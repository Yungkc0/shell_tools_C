#include "all.h"

void usage(int status)
{
	puts("Usage: link FILE1 FILE2\n"
			"Call the link function to create a link named FILE2"
			" to an existing FILE1.\n");
	exit(status);
}

int main(int argc, char **argv)
{
	if (getopt_long(argc, argv, "", NULL, NULL) != -1)
		usage(EXIT_FAILURE);
	/* now optind is 1 */
	if (argc < optind + 2) {
		if (argc < optind + 1)
			error(0, 0, "missing operand");
		else
			error(0, 0, "missing operand after `%s`", argv[optind]);
		usage(EXIT_FAILURE);
	}
	if (optind + 2 < argc) {
		error(0, 0, "extra operand `%s`", argv[optind + 2]);
		usage(EXIT_FAILURE);
	}

	if (link(argv[optind], argv[optind + 1]) != 0)
		error(EXIT_FAILURE, errno, "cannot create link '%s' to '%s'",
				argv[optind + 1], argv[optind]);

	return EXIT_SUCCESS;
}
