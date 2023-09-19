#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
struct node *add_to_empty(int data){
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=temp;
    return temp;
};
struct  node*add_to_beg(struct node*tail,int data){
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=tail->link;
    tail->link=temp;
    return tail;
};
struct node*add_to_end(struct node*tail,int data){
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=tail->link;
    tail->link=temp;
    tail=temp;
    return tail;
};
struct node*add_to_pos(struct node*tail,int data,int pos){
    if (pos==0)
    {
        add_to_beg(tail,data);
    }
    else
    {
        struct node*p=tail->link;
    for (int i = 1; i < pos; i++)
    {
        p=p->link;
    }
    if (p==tail)
    {
        add_to_end(tail,data);
    }
    else
    {
        struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=p->link;
    p->link=temp;
    return tail;
    }
    }    
};
void display(struct node*tail){
    struct node*p=tail->link;
    do
    {
        printf("%d ",p->data);
        p=p->link;
    } while (p!=tail->link);
};
struct node*create_list(){
    int len,data;
    printf("Enter no of elements in list: ");
    scanf("%d",&len);
    struct node *tail=malloc(sizeof(struct node));
    for (int i = 0; i < len; i++)
    {
        printf("Enter element at %d position: ",i+1);
        scanf("%d",&data);
        if (i==0)
        {
            tail->data=data;
            tail->link=tail;
        }
        else
        {
            tail=add_to_end(tail,data);
        }
        
    }
    return tail;

};
void del_first(struct node*tail){
    if (tail->link==tail)
    {
        free(tail);
        tail=NULL;
    }
    else
    {
        struct node*temp=tail->link;
        tail->link=temp->link;
        free(temp);
        temp=NULL;
    }
};
struct node*del_last(struct node*tail){
    struct node*temp=tail->link;
    if (tail->link==tail)
    {
        free(tail);
        tail=NULL;
    }
    else
    {
        while (temp->link!=tail)
    {
        temp=temp->link;
    }
    temp->link=tail->link;
    free(tail);
    tail=temp;
    }   
};
struct node*del_at_pos(struct node*tail,int pos){
    struct node*temp=tail->link;
    for (int i = 1; i < pos; i++)
    {
        temp=temp->link;
    }
    if (temp==tail)
    {
        tail=del_last(tail);
    }
    else
    {
        struct node*ptr=temp->link;
    temp->link=ptr->link;
    free(ptr);
    ptr=NULL;
    }
    return tail;
};


int main()
{
    struct node*tail;
    // tail=add_to_empty(54);
    // tail=add_to_beg(tail,34);
    // tail=add_to_end(tail,99);
    // tail=add_to_pos(tail,85,3);
    tail=create_list();
    tail=del_at_pos(tail,4);
    display(tail);


return 0;
}