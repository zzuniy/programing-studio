#include <stdio.h>
int main(){

    int height, weight; // 신장(cm), 체중(kg) 
    float bmi; // 비만도 수치  
    int count=0; 
    int n=0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &height);
        scanf("%d", &weight);
        bmi = weight/ ((height/100.0)*(height/100.0));
        if(bmi>=25){
            count++;
        }
    }

   printf("%d", count);
    

    return 0;
}