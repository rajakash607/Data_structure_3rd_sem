#include<stdio.h>
#include<stdlib.h>
struct time{
    int hour;
    int minute;
};

struct time * fun(int a,int b ){
    struct time *ptr = (struct time*)malloc( sizeof(struct time) );
    ptr->hour=a;ptr->minute=++b;
    return ptr;
}
void print(struct time *ptr){
    printf("%d %d ",ptr->hour,ptr->minute);

}
int main(){
    struct time *t1,*t2;
    t1=fun(2,6);
    t2=fun(9,12);
    print(t1); print(t2);
    free(t1);
    free(t2);
    
    
    return 0;
}