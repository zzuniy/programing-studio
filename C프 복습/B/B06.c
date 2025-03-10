#include <stdio.h>

int studentSum(int s[5][3], int number);
//파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
//리턴값 : 해당 학생의 총점
char getGrade(float score);
//파라미터 : 평균 점수(score) 
//리턴값 : 해당 평균 점수의 등급 ('A','B','C','D','F')
int classSum(int s[5][3], int number);
//파라미터 : 점수배열(s)과 과목번호(0,1,2) 
//리턴값 : 해당 과목의 총점

int main(){
int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
int sum_student[5]; // 학생별 총점
float average_student[5];  // 학생별 평균
char grade[5]; // 학생별 등급 

int sum_class[3]; // 과목별 총점
float average_class[3]; // 과목별 평균
char class_name[3][20] = {"Korean", "English", "Math"};

for(int i=0; i<5; i++){
    scanf("%d", &jumsu[i][0]);
    scanf("%d", &jumsu[i][1]);
    scanf("%d", &jumsu[i][2]);
}

for(int i=0; i<5; i++){
     sum_student[i] = studentSum(jumsu,i);
}

for(int i=0; i<5; i++){
     average_student[i] = sum_student[i]/3.0;
}

for(int i=0; i<5; i++){
    grade[i] = getGrade(average_student[i]);
}

for(int i=0; i<3; i++){
     sum_class[i] = classSum(jumsu,i);
}

for(int i=0; i<3; i++){
     average_class[i] = sum_class[i]/5.0;
}

for(int i=0; i<5; i++){
    printf("%d) %d %.1f %c\n", i+1, sum_student[i],average_student[i], grade[i]);
}
for(int i=0; i<3; i++){
    printf("%s %d %.1f\n", class_name[i], sum_class[i],average_class[i]);
}

    return 0;
}



int studentSum(int s[5][3], int number){
    int sum = s[number][0] + s[number][1] + s[number][2];
    return sum;
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

int classSum(int s[5][3], int number){
    int sum = s[0][number] +s[1][number] + s[2][number] + s[3][number] + s[4][number];
    return sum;
}

