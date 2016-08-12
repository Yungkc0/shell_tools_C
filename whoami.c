#include "all.h"

int main()
{
	uid_t uid;
	struct passwd *pw;

	uid = geteuid(); // this function is always successful
	pw = getpwuid(uid);
	if (!pw)
		error(EXIT_FAILURE, errno, "cannot find name for user ID %lu",
				(unsigned long int) uid);
	puts(pw->pw_name);
	return EXIT_SUCCESS;
}
