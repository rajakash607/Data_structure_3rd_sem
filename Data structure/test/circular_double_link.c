#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node* next;
};
struct node*add_to_empty(int data){
    struct node*tail=malloc(sizeof(struct node));
    tail->prev=tail;
    tail->data=data;
    tail->next=tail;
    return tail;
};
struct node*add_to_end(struct node* tail,int data){
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=tail;
    temp->next=tail->next;
    tail->next=temp;
    return temp;
};
struct node*create_list(){
    int len,data;
    printf("Enter no of element in list: ");
    scanf("%d",&len);
    struct node*tail;
    for (int i = 0; i < len; i++)
    {
        printf("Enter element on %d position: ",i+1);
    scanf("%d",&data);
        if (i==0)
        {
            tail=add_to_empty(data);
        }
        else
        {
            tail=add_to_end(tail,data);
        }
    }
    return tail;
};
void display(struct node*tail){
    struct node*ptr=tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=tail->next);
};

int main(){
    struct node*tail;
    tail=create_list();
    display(tail);
}