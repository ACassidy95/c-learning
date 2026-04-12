#include "common.h"
#ifdef TEST_HEADERS
#include "str.h"
#elifdef TEST_CASES

static char empty_str[STRMAX] = "";

static char cat1[STRMAX] = "concatenate1";
static char cat2[STRMAX] = "concatenate2";

static char cmp1[STRMAX] = "compare1";
static char cmp2[STRMAX] = "compare2";
static char cmp3[STRMAX] = "compare1";
static char cmp4[STRMAX] = "compare2 longer";

TEST("str_cat: successfully concatenate strings") {
	size_t c1, c2;

	c1 = str_len(cat1);
	c2 = str_len(cat2);

	ASSERT(str_cat(cat1, empty_str) == c1);
	ASSERT(str_cat(cat1, cat2) == c1 + c2);
}

TEST("str_len: accurately return str length") {
	ASSERT(str_len("") == 0);
	ASSERT(str_len("\0") == 0);
	ASSERT(str_len("\n") == 1);
	ASSERT(str_len("foo") == 3);
}

TEST("str_ncmp: accurately compare at most n bytes between strings") {
	ASSERT(str_ncmp(cmp1, empty_str, str_len(cmp1)) == 1);
	ASSERT(str_ncmp(empty_str, cmp1, str_len(cmp1)) == -1);
	ASSERT(str_ncmp(cmp1, empty_str, str_len(empty_str)) == 1);
	ASSERT(str_ncmp(empty_str, cmp1, str_len(empty_str)) == -1);

	ASSERT(str_ncmp(cmp1, cmp1, str_len(cmp1)) == 0);
	ASSERT(str_ncmp(cmp1, cmp3, str_len(cmp1)) == 0);
	ASSERT(str_ncmp(cmp3, cmp1, str_len(cmp3)) == 0);

	ASSERT(str_ncmp(cmp1, cmp2, str_len(cmp1)) == -1);
	ASSERT(str_ncmp(cmp2, cmp1, str_len(cmp2)) == 1);

	ASSERT(str_ncmp(cmp2, cmp4, str_len(cmp2)) == -1);
	ASSERT(str_ncmp(cmp4, cmp2, str_len(cmp2)) == 1);
	ASSERT(str_ncmp(cmp2, cmp4, str_len(cmp4)) == 1);
	ASSERT(str_ncmp(cmp4, cmp2, str_len(cmp4)) == 1);
}

#endif
