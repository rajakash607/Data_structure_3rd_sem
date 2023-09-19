#include<stdio.h>
void sqcube(int* sq,int*cube){
    int num;
    printf("Enter the number for which we have to calculate aquare and cube");
    scanf("%d",&num);
    *sq=num*num;
    *cube=num*num*num;
}
int main()
{
    int sq,cube;
    sqcube(&sq,&cube);
    printf("%d %d",sq,cube);


return 0;
}