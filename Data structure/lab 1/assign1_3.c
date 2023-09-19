#include<stdio.h>
int main()
{
    float table[12][2],current_year_total=0,previous_year_total=0;
    printf("Enter current and previous year rainfall\n");
    for (int i = 0; i < 12; i++)
    {
        for(int j = 0; j <2;j++){
            scanf("%f", &table[i][j]);
        }
    }



    printf("\t\t\t\t\t Table of monthly rainfall\n");
    printf("Year\tJan \t Feb \t March\t April\t May\t June\t July\t Aug \tSept \t Oct\t Nov\t Dec\n"1);
    printf("Current  ");
    for (int i = 0; i < 12; i++)
    {
        printf("%.1f\t",table[i][0]);
    }
    printf("\nPrevoius ");
    for (int i = 0; i < 12; i++)
    {
        printf("%.1f\t",table[i][1]);
    }

    

   for (int i = 0; i < 12; i++)
    {
        current_year_total+=table[i][0];
        previous_year_total+=table[i][1];
        
    }
    printf("\n\n\n");
    printf("Total rainfall this year is %f \nTotal rainfall last year is %f\n", current_year_total, previous_year_total);
    printf("Average monthly rainfall for this year is %.1f \nAverage monthly rainfall for last year is %.1f\n", current_year_total/12,previous_year_total/12);
return 0;
}