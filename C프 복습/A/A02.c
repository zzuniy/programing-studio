#include <stdio.h>
int main(){

    int height, weight; // 신장(cm), 체중(kg) 
    float bmi; // 비만도 수치  

    scanf("%d", &height);
    scanf("%d", &weight);

    bmi = weight/ ((height/100.0)*(height/100.0));

    printf("%.1f ",bmi );

    if(bmi>=25){
        printf("Overweight");
    }else{
        printf("Normal");
    }
    

    return 0;
}