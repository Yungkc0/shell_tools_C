#include "all.h"

void usage(int status)
{
	printf("Usage: unlink FILE\n"
			"Call the unlink function to remove the specified FILE.\n");
	exit(status);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		error(0, 0, "arguments error");
		usage(EXIT_FAILURE);
	}

	if (unlink(argv[1]) != 0)
		error(EXIT_FAILURE, errno, "cannot unlink %s", argv[1]);

	return EXIT_SUCCESS;
}
