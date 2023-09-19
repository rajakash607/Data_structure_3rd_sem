#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* create_list(){
    int len,data;
    printf("Enter no of elements in list ");
    scanf("%d", &len);
    struct node*head=malloc(sizeof(struct node));
    struct node*ptr=head;
    for (int i = 0; i < len; i++)
    {       
        printf("Enter element at %d position ",i+1);
        scanf("%d",&data);
        
        if (i==0)
        {
            head->data=data;
            head->link=NULL;
        }
        else
        {
            struct node*temp=malloc(sizeof(struct node));
            ptr->link=temp;
            temp->data=data;
            temp->link=NULL;
            ptr=temp;
            
        }
    }
    return head;
};
void display(struct node*head){
    struct node*temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    
};
struct node*reverse(struct node*head){
    struct node*temp=head->link;
    struct node*ptr=head;
    head->link=NULL;
    while(temp!=NULL){
        head=temp;
        temp=temp->link;
        head->link=ptr;
        ptr=head;
    }
    return head;
};

int main()
{
    struct node *head;
    head=create_list();
    
    head=reverse(head);
    display(head);


return 0;
}