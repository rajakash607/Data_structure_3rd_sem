#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
struct node* create_list(struct node* ptr,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
};
void create_node(struct node* start,int data){
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
}
void count_node(struct node* head){
    int count = 0;
    struct node* ptr=NULL;
    ptr = head;
    while(ptr!=NULL){
        count++;
    }
    printf("\n%d",count);
};
void traverse_print(struct node* head){
    struct node* ptr=NULL;
    ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }

};
void search(struct node* head,int item){
    struct node* ptr=NULL;
    ptr = head;
    int pos=0;
    while(ptr!=NULL){
        pos++;
        if (ptr->data==item)
        {
            printf("%d is found at position &d",ptr->data,pos);
        }
        
        
        ptr = ptr->link;
    }


};

int main()
{
    int size,data;
    printf("Enter no of nodes ");
    scanf("%d", &size);
    printf("Enter data at index 0 ");
    scanf("%d", &data);
    struct node* head=malloc(sizeof(struct node));
    head->data=data;
    head->link=NULL;
    struct node* ptr=head;
    for(int i = 1; i < size;i++)
    {
        printf("Enter data at index %d ",i);
        scanf("%d", &data);
        ptr=create_list(ptr,data);
    }
    count_node(ptr);
    
    

return 0;
}