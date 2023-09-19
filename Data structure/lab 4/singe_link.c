#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void add_at_end(struct node *head,int data){
    struct node*ptr=head;
    struct node*temp=malloc(sizeof(struct node));
    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    temp->data=data;
    temp->link=NULL;
}
struct node * create_list(struct node*head)
{
    int len,data;
    printf("Enter no of node in list ");
    scanf("%d", &len);
    printf("Enter data for node at 1 position ");
    scanf("%d", &head->data);
    head->link=NULL;
    for (int i = 1; i < len; i++)
    {
        printf("Enter data for node at %d position ",i+1);
        scanf("%d", &data);
        add_at_end(head,data);
    }
    return head;
    
};
struct node* del_at_pos(struct node* head,int pos){
    struct node* current=head;
    struct node* previous=current;
    if (pos==1)
    {
        head=head->link;
        free(current);
        current=NULL;
        free(previous);
        previous=NULL;
        return head;
    }
    else
    {
        while (pos!=1)
        {
            previous=current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
        return head;
    }
};
struct node* add_at_pos(struct node*head,int pos){
    int data;
    struct node*ptr=head;
    struct node*temp=malloc(sizeof(struct node));
    printf("Enter data for node at %d position ",pos);
    scanf("%d",&data);
    temp->data=data;
    temp->link=NULL;
    if (pos==1)
    {
        temp->link=head;
        head=temp;
        return head;
    }
    else
    {
        for (int i = 1; i < pos-1; i++)
    {
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    return head;
    }
}
void display(struct node* head){
    struct node* temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    
}
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head=create_list(head);
    head=del_at_pos(head,2);
    head=add_at_pos(head,1);
    display(head);

return 0;
}