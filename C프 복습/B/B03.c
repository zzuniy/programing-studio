#include <stdio.h>

int main(){

int kor, eng, math; // 국어점수, 영어점수, 수학점수 
int total; // 총점
float average; // 평균점수 

    scanf("%d", &kor);
    scanf("%d", &eng);
    scanf("%d", &math);

    total = kor + eng + math; 
    average = total/3.0;
    
    printf("%.1f ",average);
    
    if(average <60)
    printf("F");

    else if (average < 70)
    printf("D");

    else if (average < 80)
    printf("C");
  
    else if (average < 90)
    printf("B");
  
  else{
    printf("A");
  }
    return 0;
}


