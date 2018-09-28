#include <iostream>

using namespace std;

static int indicator = 0;

int
    getNthUglyNo(int n)
{
    int ugly[n] = {0};
    
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;
    int nextUglyNo = 1;

    ugly[0] = 1;

    for(int i = 1; i < n; ++i)
    {
        ++indicator;

        nextUglyNo = min(nextMultipleOf2,min(nextMultipleOf3, nextMultipleOf5));

        ugly[i] = nextUglyNo;
        if(nextUglyNo == nextMultipleOf2)
        {
            ++i2;
            nextMultipleOf2 =ugly[i2]*2;
        }
        if(nextUglyNo == nextMultipleOf3)
        {
            ++i3;
            nextMultipleOf3 = ugly[i3]*3;
        }
        if(nextUglyNo == nextMultipleOf5)
        {
            ++i5;
            nextMultipleOf5 = ugly[i5]*5;
        }
    }

    return nextUglyNo;
}

int
    main()
{
    int i;

    for(i = 0; i <= 150; ++i)
    {
        printf("%d ugly number is %d\r\n", i, getNthUglyNo(i));
    }

    printf("indicator = %d\r\n", indicator);
    return 0;
}