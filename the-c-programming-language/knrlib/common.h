#ifndef __CONST_H
#define __CONST_H

#define STRMAX	4096
#define LINEMAX	4096

/* Swap two values a, b of type t */
#define swap(t, a, b)\
	do {\
		t tmp;\
		tmp = a;\
		a = b;\
		b = tmp;\
	} while(0)

#endif
