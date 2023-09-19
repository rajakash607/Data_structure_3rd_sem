#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row,col,count=0,k=0;
    printf("Enter row size of the sparse matrix ");
    scanf("%d",&row);
    printf("Enter column size of the sparse matrix ");
    scanf("%d",&col);
    //Dma for 2d array
    int**arr=(int**)malloc(row*sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        arr[i]=(int*)malloc(col*sizeof(int));
    }
    //taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter no for position %d %d\n",i,j);
            scanf("%d",&arr[i][j]);
        }
        
    }
    //printing input array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ",arr[i][j]);
        if (arr[i][j]!=0)
        {
            count++;
        }
        }
        printf("\n");
    }
    //making 3 tuple array
    int **arr_sp=(int**)malloc(sizeof(int*)*count);
    for (int i = 0; i < count; i++)
    {
        arr_sp[i] =(int*)malloc(sizeof(int)*3);
    }
    //entering into 3 tuple array
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (arr[i][j]!=0)
            {
                arr_sp[k][0]=i;
                arr_sp[k][1]=j;
                arr_sp[k][2]=arr[i][j];
                k++;
            
                
            }
            

        }
    }
    //printing the final sparse matrix
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",arr_sp[i][j]);
        }
        printf("\n");
    }
    
return 0;
}
