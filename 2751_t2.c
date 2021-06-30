#pragma GCC optimize("O3")
#pragma GCC target("arch=skylake")
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char IN[10485760] = {0};

char POS[2][1000001] = {0};
int CAT[2][7] = {0};

char _S1[20]  = {"-0-1-2-3-4-5-6-7-8-9"};
char _S2[300] = {"-00-01-02-03-04-05-06-07-08-09"
                  "-10-11-12-13-14-15-16-17-18-19"
                  "-20-21-22-23-24-25-26-27-28-29"
                  "-30-31-32-33-34-35-36-37-38-39"
                  "-40-41-42-43-44-45-46-47-48-49"
                  "-50-51-52-53-54-55-56-57-58-59"
                  "-60-61-62-63-64-65-66-67-68-69"
                  "-70-71-72-73-74-75-76-77-78-79"
                  "-80-81-82-83-84-85-86-87-88-89"
                  "-90-91-92-93-94-95-96-97-98-99"};

char S1[10]  = {"0123456789"};
char S2[200] = {"00010203040506070809"
                "10111213141516171819"
                "20212223242526272829"
                "30313233343536373839"
                "40414243444546474849"
                "50515253545556575859"
                "60616263646566676869"
                "70717273747576777879"
                "80818283848586878889"
                "90919293949596979899"};

#define OUT_1(p,num) {\
    memcpy(p,&S1[num],1);\
    p += 1;\
}

#define OUT_2(p,num) {\
    memcpy(p,&S2[num*2],2);\
    p += 2;\
}

#define OUT_3(p,num) {\
    OUT_1(p,num/100);\
    OUT_2(p,num%100);\
};

#define OUT_4(p,num) {\
    OUT_2(p,num/100);\
    OUT_2(p,num%100);\
}

#define OUT_5(p,num) {\
    OUT_1(p,num/10000);\
    OUT_4(p,num%10000);\
}

#define OUT_6(p,num) {\
    OUT_2(p,num/10000);\
    OUT_4(p,num%10000);\
}

#define _OUT_1(p,num) {\
    memcpy(p,&_S1[num*2],2);\
    p += 2;\
}

#define _OUT_2(p,num) {\
    memcpy(p,&_S2[num*3],3);\
    p += 3;\
}

#define _OUT_3(p,num) {\
    _OUT_1(p,num/100);\
    OUT_2(p,num%100);\
}

#define _OUT_4(p,num) {\
    _OUT_2(p,num/100);\
    OUT_2(p,num%100);\
}

#define _OUT_5(p,num) {\
    _OUT_1(p,num/10000);\
    OUT_4(p,num%10000);\
}

#define _OUT_6(p,num) {\
    _OUT_2(p,num/10000);\
    OUT_4(p,num%10000);\
}

#define _LOOP_ROUTINE(spt,cat,out) {\
    k = spt;\
    while (CAT[0][cat]) {\
        while (!POS[0][k]) {\
            k--;\
        }\
        _OUT_##out(p,k);\
        *p++ = '\n';\
        CAT[0][cat]--;\
        k--;\
    }\
}

#define LOOP_ROUTINE(spt,cat,out) {\
    k = spt;\
    while (CAT[1][cat]) {\
        while (!POS[1][k]) {\
            k++;\
        }\
        OUT_##out(p,k);\
        *p++ = '\n';\
        CAT[1][cat]--;\
        k++;\
    }\
}

int main(void)
{
    char *p;
    int cn;
    int i,j,k,l,m;
    int num;

#if 0
    {
        FILE *fp;

        fp = fopen("test_data.txt","r");

        fread(IN,sizeof(IN),1,fp);
    }
#else
    read(0,IN,sizeof(IN));
#endif

    p = IN;

    for (cn = 0; *p++ >= 48; ) {
        cn = cn * 10 + (*(p-1) - 48); 
    }

    while (cn--) {
        for(i = 1; (*p < 48); p++) {
            i &= ~(*p == '-');
        }

        for (num = 0; *p++ >= 48; ) {
            num = num * 10 + (*(p-1) - 48);
        }

        j = 0;
        j += num > 9;
        j += num > 99;
        j += num > 999;
        j += num > 9999;
        j += num > 99999;
        j += num > 999999;

        CAT[i][j]++;
        POS[i][num]++;
    }

    p = IN;

    if (POS[0][1000000]) {
        memcpy(p,"-1000000\n",9);
        p += 9;
    }

    _LOOP_ROUTINE(999999,5,6);
    _LOOP_ROUTINE(99999,4,5);
    _LOOP_ROUTINE(9999,3,4);
    _LOOP_ROUTINE(999,2,3);
    _LOOP_ROUTINE(99,1,2);
    _LOOP_ROUTINE(9,0,1);

    LOOP_ROUTINE(0,0,1);
    LOOP_ROUTINE(10,1,2);
    LOOP_ROUTINE(100,2,3);
    LOOP_ROUTINE(1000,3,4);
    LOOP_ROUTINE(10000,4,5);
    LOOP_ROUTINE(100000,5,6);

    if (POS[1][1000000]) {
        memcpy(p,"1000000\n",8);
        p += 8;
    }

    write(1,IN,p - IN);

    return 0;
}

