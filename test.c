#include <stdio.h>

int main(void)
{
	int	ret;
	ret = printf("%5.2i", 1);
	printf("\n[%d]\n", ret);
    return (0);
}