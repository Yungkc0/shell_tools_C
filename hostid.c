#include "all.h"

int main()
{
	unsigned int id;

	id = gethostid();
	/* gethostid will returns a "32-bit identifier",
	 * if unsigned int is wider than 32 bits. */
	id &= 0xffffffff;
	printf("%08x\n", id);

	return EXIT_SUCCESS;
}
