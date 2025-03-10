#include <stdio.h>
#include <stdlib.h>

struct bmi_struct{
	char name[20];  // 이름 (공백 없이 영어 알파벳으로 구성)
	int height, weight; // 키(cm), 몸무게(kg)
	float bmi; // 비만도
	int bmi_level; // 비만등급 0~4
};

int loadData(struct bmi_struct* list[]);
void bmiResolve(struct bmi_struct* sp);
void printBmiData(struct bmi_struct* list[], int size);

char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};


int main(void) {
	struct bmi_struct* data[20];    // 최대 20명까지 관리
	int count;
	count = loadData(data);     // 여러 명의 이름, 신장, 체중 데이터 입력받기
	printf("Loaded %d\n", count);
	for(int i=0; i<count; i++)
		bmiResolve(data[i]);        // 비만도 관리 데이터 완성하기
	printBmiData(data, count);      // 비만도 관리 데이터 출력하기
	return 0;
}

int loadData(struct bmi_struct* list[]){
    int n=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        list[i]= malloc(sizeof(struct bmi_struct));
        
        if (list[i] == NULL){
            printf("%d is NULL\n", i);
            return -1;
        }
    }
    for(int i=0; i<n; i++){
        scanf("%s", list[i] -> name);
        scanf("%d", &list[i]-> height);
        scanf("%d", &list[i]-> weight);
         
    }
    return n;
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
}

void printBmiData(struct bmi_struct* list[], int size){
    for(int i=0; i<size; i++){
        printf("%s %dcm %dkg %.1f %s\n",list[i] -> name,list[i] -> height,list[i] -> weight,list[i] -> bmi, bmi_string[list[i] -> bmi_level]);
    }  
}
// James 176cm 80kg 25.8 Mild obesity