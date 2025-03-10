// James 268 89.3 B

#include <stdio.h>

struct st_jumsu{
  char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
  int jumsu[3]; // 3과목 점수 (국, 영, 수)
  int sum;	// 총점
  float avg;	// 평균
  char grade;	// 평균에 대한 등급
};

char getGrade(float score);
//파라미터 : 평균 점수(score) 
//리턴값 : 해당 평균 점수의 등급 ('A','B','C','D','F')

int main(){
struct st_jumsu one; // one의 점수 데이터


    scanf("%s", one.name);
    scanf("%d", &one.jumsu[0]);
    scanf("%d", &one.jumsu[1]);
    scanf("%d", &one.jumsu[2]);


one.sum = one.jumsu[0] +one.jumsu[1]+ one.jumsu[2];
one.avg = one.sum/3.0;

one.grade = getGrade(one.avg);


    printf("%s %d %.1f %c", one.name, one.sum, one.avg, one.grade);

   
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
