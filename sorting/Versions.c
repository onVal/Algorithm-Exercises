#include <stdio.h>
#if defined(__STDC__)
# define C_VERSION 89
# if defined(__STDC_VERSION__)
#  define C_VERSION 90
#  if (__STDC_VERSION__ >= 199409L)
#   define C_VERSION 94
#  endif
#  if (__STDC_VERSION__ >= 199901L)
#   define C_VERSION 99
#  endif
# if (__STDC_VERSION__ >= 201112L)
#	define C_VERSION 2011
# endif
#  if (__STDC_VERSION__ >= 201710L)
#   define C_VERSION 2018
#  endif
# endif
#endif

int main() {
	printf("%d", C_VERSION);
	return 0;
}
