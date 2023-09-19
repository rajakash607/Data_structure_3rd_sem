#include<stdio.h>
int main()
{
    float scale;
    printf("Enter richter scale value\n");
    scanf("%f",&scale);
    if (scale<5){
        printf("Little or no rain");
    }
    else if (scale>=5 && scale <5.5)
    {
        printf("Some damage");
    }
    else if (scale>=5.5 && scale<6.5)
    {
        printf("Serious damage");
    }
    else if (scale>=6.5 && scale<7.5){
        printf("Disaster houses and buildings may collapse");
    }
    else{
        printf("catastrophe most buildings destroyed");
    }
    
    

return 0;
}