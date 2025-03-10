#include <stdio.h>
int bmiLevel(int height, int weight);
int main(){
int height, weight;
int bmi_n=0;

scanf("%d", &height);
scanf("%d", &weight);

//파라미터: height: 신장(cm), weight: 체중(kg)
//수행내용: 비만도 계산 후 비만등급을 판정한다.
//리턴값: 비만등급 (0~4): 0 (Underweight), 1 (Normal weight), 2 (Overweight), 3 (Mild obesity), 4 (Severe obesity)
bmi_n = bmiLevel(height, weight);
if(bmi_n==0)
printf("Underweight (0)");

else if(bmi_n==1)
printf("Normal weight (1)");

else if(bmi_n==2)
printf("Overweight (2)");

else if(bmi_n==3)
printf("Mild obesity (3)");

else if(bmi_n==4)
printf("Severe obesity (4)");

    return 0;
}
int bmiLevel(int height, int weight){

    float bmi = weight / ((height/100.0)*(height/100.0));

    if(bmi < 18.5)
    return 0;

    else if(bmi < 23.0)
    return 1;

    else if(bmi < 25.0)
    return 2;

    else if(bmi < 30.0)
    return 3;

    else if(30<= bmi)
    return 4;

    return -1;
}