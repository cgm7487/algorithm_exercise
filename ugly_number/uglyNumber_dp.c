#include <stdio.h>
#include <stdlib.h>

static int indicator = 0;

int
    maxDivide(  int a,
                int b)
{
    while(a%b == 0)
    {
        a = a/b;
        ++indicator;
    }
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

static int uglyTable[1024]={1};
static size_t currentIndex = 0;

int
    getNthUglyNo(int n)
{
    int count = currentIndex;
    int i = 1;
    while(n-1 > count)
    {
        ++indicator;
        ++i;
        if(isUgly(i))
        {
            ++count;
            ++currentIndex;
            uglyTable[count] = i;
        }
    }

    return uglyTable[n-1];
}

int
    main()
{
    printf("test = %d\r\n", getNthUglyNo(150));
    int i;

    for(i = 1; i <= 150; ++i)
    {
        printf("%d ugly number is %d\r\n", i, getNthUglyNo(i));
    }

    printf("indicator = %d\r\n", indicator);
    return 0;
}