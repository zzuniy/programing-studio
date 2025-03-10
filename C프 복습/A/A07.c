#include <stdio.h>
int bmiLevel(int height, int weight);
int main(){
int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
int bmi_level[10]; // 10명의 비만등급(0~4)
int count=0, all =0; // 비만인 사람의 숫자

scanf("%d", &all);
for(int i=0; i<all; i++){
    scanf("%d", &height[i]);
    scanf("%d", &weight[i]);

    bmi_level[i] = bmiLevel(height[i], weight[i]);
}

for(int i=0; i<all; i++){

    if(bmi_level[i]>=3){
        count++;
    }
}


printf("%d/%d", count,all);

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