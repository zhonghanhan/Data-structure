//
//  main.c
//  biggest-array
//
//  Created by hanhan on 2019/3/7.
//  Copyright © 2019 hanhan. All rights reserved.
//

#include <stdio.h>
#define MAX 100001
int main(int argc, const char * argv[]) {
    // insert code here...

        // insert code here...
        int k;
        scanf("%d",&k);
        int num[MAX];
        int thissum=0,maxsum=0;
        int first=0,last=0;
        for(int i=0;i<k;i++)
        {
            scanf("%d",&num[i]);
        }
        for(int i=0;i<k;i++)
        {
            if(thissum==0)
            {
                first=num[i];
            }
            thissum +=num[i];
            if(thissum>maxsum)
            {
                maxsum = thissum;
                last=num[i];
            }
            else if(thissum<0)
            {
                thissum = 0;
            }
        }
        first = first<0?0:first;
        last = last<0?0:last;
        printf("%d %d %d",maxsum,first,last);
        
        return 0;
        
}
