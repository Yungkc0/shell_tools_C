#include "all.h"

/* Exit status 0 if stain is a tty, 1 if not, 2 if usage error,
 * 3 if write error */
#define USAGE_ERROR 2
#define WRITE_ERROR 3

static struct option const longopts[] = {
	{"silent", no_argument, NULL, 's'},
	{"quiet", no_argument, NULL, 's'},
	{NULL, 0, NULL, 0}
};

void usage(int status)
{
	puts("Usage: tty [OPTION]...\n"
			"Print the file name of the terminal connected to standard input.\n\n"
			"  -s, --silent, --quiet   print nothing, only return an exit status");
	exit(status);
}

int main(int argc, char **argv)
{
	char *tty;
	int optc;
	bool silent;

	silent = false;
	while ((optc = getopt_long(argc, argv, "s", longopts, NULL)) != -1)
	{
		switch (optc) {
			case 's':
				silent = true;
				break;
			default:
				usage(USAGE_ERROR);
		}
	}

	if (optind < argc)
		error(0, 0, "extra operand `%s`", argv[optind]);

	tty = ttyname(STDIN_FILENO);
	if (!silent) {
		if (tty)
			puts(tty);
		else
			puts("not a tty");
	}

	return isatty(STDIN_FILENO) ? EXIT_SUCCESS : EXIT_FAILURE;
}
