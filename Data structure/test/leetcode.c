#include<stdio.h>
int main()
{
    int arr[12]={
        1,1,1,0,1,1,1,1,1,1,0,1
    };
int p_count=0,a_count=0;
for(int i=0;i<12;i++){
    if (arr[i]==1)
    {
        p_count++;
        if (p_count>a_count)
        {
            a_count=p_count;
        }
    }
    else
    {
        p_count=0;
    }
    
    
}
printf("%d\n",a_count);
return 0;
}