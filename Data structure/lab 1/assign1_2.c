#include<stdio.h>
#include<stdbool.h>
int main()
{
    int array[5][4]={
        {192,48,206,37},
        {147,90,312,21},
        {186,12,121,38},
        {114,21,408,37},
        {267,13,382,29}
    };
    printf("Precinct \t A \t B \t C \t D\n");
    printf("-------------------------------------------\n");
    for (int i=0; i<5; i++){
        printf("Precinct %d\t",i+1);
        for (int j=0; j<4; j++){
            printf("%d \t",array[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    int total_votes[4],temp=0;
    for (int i=0; i<5; i++) {
        for(int j=0; j<4; j++){
            temp += array[i][j]; 
        }
    }
   
int each_total[4],percent[4],alphabet=0;
int winner=false;
;
    
    for(int i=0;i<4;i++){
        int count=0;
        for(int j=0; j<5; j++){
            count += array[j][i];
            }
        each_total[i]=count;
        percent[i]=(count*100)/temp;
        if (percent[i]>50)
        {
            winner = true;
            alphabet =i;
        }
        
        
    }


    printf("Total vote for each candidate\n");
    printf("A\tB\tC\tD\n");
    printf("----------------------------\n");
    for(int k =0;k<4;k++){
        printf("%d\t",each_total[k]);
    }


printf("\n\n\nPercentage of total votes for each candidate\n");
printf("A\tB\tC\tD\n");
 printf("--------------------------\n");
for(int k=0;k<4;k++){
    printf("%d\t",percent[k]);
}
if (winner)
{
    printf("\n\n\nWinner is %c as this candidate has got more than 50 percent vote.",alphabet+65);
}
else{
    printf("There is a face off between this candidate and that candidate.");
}



return 0;
}