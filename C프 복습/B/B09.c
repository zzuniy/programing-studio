#include <stdio.h>
#include <stdlib.h>
struct st_jumsu{
        char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
        int jumsu[3]; // 3과목 점수 (국, 영, 수)
        int sum;	// 총점
        float avg;	// 평균
        char grade;	// 평균에 대한 등급
    };


char getGrade(float score);

void makeJumsu(struct st_jumsu* p);
//파라미터: 점수 데이터의 포인터(p) 
//리턴값: 없음
//수행내용: 해당 학생의 점수 데이터 구조체 내의 과목 점수로 총점, 평균, 등급을 넣는다.
void printJumsu(struct st_jumsu* p);
//파라미터: 점수 데이터의 포인터(p) 
//리턴값: 없음
//수행내용: 해당 학생의 점수 데이터 구조체 내의 값을 출력한다.
int getClassSum(struct st_jumsu* data[], int size, int index);
//파라미터: 점수 데이터의 포인터 배열(data), 점수 데이터 개수, 과목번호(0~2) 
//리턴값: 과목번호에 해당하는 점수의 총 합계
//수행내용: 모든 점수 데이터의 특정 과목번호의 점수 합계를 구한다.


int main(){
    struct st_jumsu* jdata[20]; // 최대 20명의 점수 데이터
    int sum_class[3]; // 과목별 총점
    float average_class[3]; // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};
    int num =0; 

    scanf("%d", &num);
    for(int i=0; i<num; i++){
        jdata[i]= malloc(sizeof(struct st_jumsu));
        
        if (jdata[i] == NULL){
            printf("%d is NULL\n", i);
            return -1;
        }
    }
    for(int i=0; i<num; i++){
        scanf("%s", jdata[i] -> name);
        scanf("%d", &jdata[i] -> jumsu[0]);
        scanf("%d", &jdata[i] -> jumsu[1]);
        scanf("%d", &jdata[i] -> jumsu[2]);
        makeJumsu(jdata[i]);
    }

    for(int i= 0; i<3; i++){
        sum_class[i]= getClassSum(jdata, num, i);
    }
    for(int i= 0; i<3; i++){
        average_class[i]= sum_class[i]/(float)num;
    }
    for(int i=0; i<num; i++){
        printJumsu(jdata[i]);
    }
    for(int i=0; i<3; i++){
        printf("%s %d %.1f\n", class_name[i], sum_class[i], average_class[i]);
    }
    

    return 0;
}

char getGrade(float score){
         if(score <60)
    return  'F';

    else if (score< 70)
    return  'D';

    else if (score< 80)
    return  'C';
  
    else if (score< 90)
    return 'B';
  
  else{
    return 'A';
  }
}

void makeJumsu(struct st_jumsu* p){
    p -> sum = p -> jumsu[0] + p -> jumsu[1] + p -> jumsu[2];
    p -> avg = p -> sum / 3.0;
    p -> grade =  getGrade(p-> avg);
}
void printJumsu(struct st_jumsu* p){
    printf("%s %d %.1f %c\n", p-> name, p -> sum, p -> avg, p-> grade);

}
int getClassSum(struct st_jumsu* data[], int size, int index){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += data[i] -> jumsu[index];
    }
    return sum;
}