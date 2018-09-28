#include <stdio.h>
#include <stdlib.h>

int
    maxDivide(  int a,
                int b)
{
    while(a%b == 0)
        a = a/b;
    return a;
}

int
    isUgly(int no)
{
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);

    return (no == 1) ? 1 : 0;
}

static int indicator = 0;
int
    getNthUglyNo(int n)
{
    int i = 1;
    int count = 1;

    while(n > count)
    {
        ++indicator;
        i++;
        if(isUgly(i))
            ++count;
    }

    return i;
}

int
    main()
{
    int i;

    for(i = 1; i <= 150; ++i)
        printf("%dth ugly no. is %d\r\n", i, getNthUglyNo(i));

    printf("indicator = %d\r\n", indicator);
    return 0;
}