#include <stdio.h>

#define TEST_HEADERS
#include "test_suite.c"
#undef TEST_HEADERS

#define TEST(name) test = name;
#define ASSERT(ast)\
	do{\
		assertion = #ast;\
		file = __FILE__;\
		line = __LINE__;\
		if(ast) {\
			putchar('.');\
		} else {\
			goto test_fail;\
		}\
	} while (0)

int main(void)
{
	const char	*test = "";
	const char	*assertion = "";
	const char	*file = "";
	int		line;

#define TEST_CASES
#include "test_suite.c"
#undef TEST_CASES

	putchar('\n');
	return 0;
test_fail:
	printf("!\nTest failure at %s: %d\n\t%s: %s\n",
	       file, line, test, assertion);
	return -1;
}

