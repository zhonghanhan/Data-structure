//
//  main.c
//  二分查找
//
//  Created by hanhan on 2019/3/18.
//  Copyright © 2019 hanhan. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;
    
    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L,ElementType x)
{
    int p = 0;
    int s=1;
    int l = L -> Last;
    int num = l/2;
    int mid;
    while(num--)
    {
        mid =(s+l)/2;
        if(x==L->Data[mid])
        {
            p=mid;
            break;
        }
        else if(x==L->Data[l])
        {
            p=l;
            break;
        }
        else if(x>L->Data[mid])
        {
            s=mid;
        }
        else if(x<L->Data[mid])
        {
            l=mid;
        }
        
    }
    if(p==0)
    {
        return NotFound;
    }
    else
    {
        return p;
    }
}
