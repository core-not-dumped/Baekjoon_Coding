#include <stdio.h>

int main(void)
{
    int N;
    int buffer;
    _Bool arr[2000001] = {0, };
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &buffer);
        arr[buffer + 1000000] = 1;
    }
    
    for(int i = 0; i < 2000001; i++)
    {
        if(arr[i]) printf("%d\n", i - 1000000);
    }
    
    return 0;
}
