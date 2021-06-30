#include<stdio.h>

int f(int N, int r, int c)
{
    if(N==1)
        return 2*r+c;
    
    else
        return 4*f(N-1, r/2, c/2)+f(1, r%2, c%2);
}

int main(void)
{
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d", f(N, r, c));
    
    return 0;
}
