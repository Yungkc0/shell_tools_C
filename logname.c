#include "all.h"

int main()
{
	char *cp;

	cp = getlogin();
	if (!cp)
		error(EXIT_FAILURE, 0, "no login name");
	puts(cp);
	return EXIT_SUCCESS;
}
