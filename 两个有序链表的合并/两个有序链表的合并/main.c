//
//  main.c
//  两个有序链表的合并
//
//  Created by hanhan on 2019/3/18.
//  Copyright © 2019 hanhan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(void); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
    if(L1==NULL&&L2==NULL)
    {
        return NULL;
    }
    List pa,pb,pc,L;                    //注意类型是结构不是指针
    L=(List)malloc(sizeof(List));       //申请头节点
    pa=L1->Next;
    pb=L2->Next;
    pc=L;
    while(pa&&pb)
    {
        if(pa->Data>=pb->Data)
        {
            pc->Next=pb;
            pc=pc->Next;
            pb=pb->Next;
        }
        else
        {
            pc->Next=pa;
            pc=pc->Next;
            pa=pa->Next;
        }
    }
    if(pa)
    {
        pc->Next=pa;
    }
    else if(pb)
    {
        pc->Next=pb;
    }
    L1->Next=NULL;
    L2->Next=NULL;
    return L;
}

