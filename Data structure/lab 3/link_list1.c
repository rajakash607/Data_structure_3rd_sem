#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*start;
void create_list(int data){
    struct node* temp=malloc(sizeof(struct node));
    struct node *q;
    temp->data = data;
    temp->link = NULL;
    if (start==NULL)
    {
        start=temp;
    }
    else
    {
        q=start;
        while(q->link!=NULL){
            q=q->link;
        }
        q->link=temp;
    }

};
void display(){
    struct node*q;
    if (start==NULL){
        printf("List is empty\n");
        return;
    }
    q=start;
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->link;
    }

};
int main()
{
    int n,data;
    start=NULL;
    printf("Enter no of nodes to create ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
    {
        printf("Enter data for node %d ", i);
        scanf("%d",&data);
        create_list(data);
    }}
    display();
    free(start);

return 0;
}
