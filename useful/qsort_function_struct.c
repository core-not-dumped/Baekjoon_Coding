#include <stdio.h>
#include <stdlib.h>
struct question {
	int a;
	double b;
};

int compare(const void *A, const void  *B)
{
    struct question* ptrA = (struct question*)A;
    struct question* ptrB = (struct question*)B;

    if (ptrA->a < ptrB->a) return -1;
    else if (ptrA->a == ptrB->a) return 0;
    else return 1;
}

int main()
{
     struct question c[5];
     qsort(c,5,sizeof(struct question),compare);

     return 0;
}
