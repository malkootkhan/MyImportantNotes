#include <stdio.h>
#include <stdlib.h>

#define		ALIGNED_ATTR	 __attribute__((aligned(16)))

struct ALIGNED_ATTR my_struct {
    int x;
    int y;
    char test;
};

int main()
{
	struct my_struct var1,var2,var3;
	struct my_struct var;
	printf("%ld\n",sizeof(var));
	

	return 0;
}
