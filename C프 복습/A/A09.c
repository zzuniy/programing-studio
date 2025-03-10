#include <stdio.h>
struct bmi_struct{
    char name[20];  // 이름 (공백 없이 영어 알파벳으로 구성)
    int height, weight; // 키(cm), 몸무게(kg)

    float bmi; // 비만도
    int bmi_level; // 비만등급 0~4
};

void bmiResolve(struct bmi_struct* sp); // 함수 선언



int main(){
    struct bmi_struct data; // 구조체 선언

    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"}; //비만등급 str

    scanf("%s %d %d", data.name, &data.height, &data.weight); // 구조체 이름, 키, 무게 입력 

    bmiResolve(&data); //비만도, 비만등급 구하는 함수 선언

    printf("%s, You are %s.\n", data.name, bmi_string[data.bmi_level]); // oo은 ~이다 출력
    return 0;
}

void bmiResolve(struct bmi_struct* sp){
    sp -> bmi =  sp -> weight / ((sp -> height/100.0)*(sp -> height/100.0)); // 포인터 구조체로 실시간 값 구하기


    if(sp -> bmi < 18.5)
    sp -> bmi_level = 0;

    else if(sp -> bmi < 23.0)
    sp -> bmi_level = 1;

    else if(sp -> bmi < 25.0)
    sp -> bmi_level = 2;

    else if(sp -> bmi < 30.0)
    sp -> bmi_level = 3;

    else if(30<= sp -> bmi)
    sp -> bmi_level = 4;

// 비만등급 측정
}