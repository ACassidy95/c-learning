#ifdef TEST_HEADERS
#include "str.h"
#elifdef TEST_CASES

TEST("str_len: accurately return str length") {
	ASSERT(str_len("") == 0);
	ASSERT(str_len("\n") == 1);
	ASSERT(str_len("foo") == 3);
}

#endif
