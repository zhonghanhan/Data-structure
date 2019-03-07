//
//  main.c
//  compare-time
//
//  Created by hanhan on 2019/3/7.
//  Copyright © 2019 hanhan. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAX 1000
void fun1(double x)
{
    int p=1;
    for(int i=1;i<101;i++)
        p += pow(x,i)/i;;
}
void fun2(double x)
{
    double p=x;
    for(int i=100;i>0;i--)
    {
        p = (p+1/i)*x;
    }
}

int main(int argc, const char * argv[])
{

        double x=1.1;
        double time1,time2;
        clock_t start,stop;
        start =clock();
        for(int i =0;i<MAX;i++)
            fun1(x);
        stop = clock();
        time1 = (double)(stop-start)/ CLOCKS_PER_SEC;
        printf("%f\n",time1);
        start = clock();
        for(int i =0;i<MAX;i++)
            fun2(x);
        stop = clock();
        time2=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("%f\n",time2);
    
    return 0;
}
