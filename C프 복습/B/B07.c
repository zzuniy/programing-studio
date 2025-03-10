#include <stdio.h>

int studentSum(int s[20][3], int size, int index);
char getGrade(float score);
int classSum(int s[20][3], int size, int index);
int firstRanking(float s[20], int size);

int main(){
	int jumsu[20][3]; // 최대 20명의 3과목 점수를 저장하고 있는 2차원 배열 
	int sum_student[20]; // 최대 20명의 학생별 총점
	float average_student[20];  // 최대 20명의 학생별 평균
	char grade[20]; // 최대 20명의 학생별 등급 
	int first;	// 1등 학생 번호
	int all;	// 인원수
	int sum_class[3]; // 과목별 총점
	float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};
    int number= 0; 

	scanf("%d",&number);

    for(int i=0; i<number; i++){
    scanf("%d", &jumsu[i][0]);
    scanf("%d", &jumsu[i][1]);
    scanf("%d", &jumsu[i][2]);
    }

    for(int i=0; i<number; i++){
        sum_student[i] = studentSum(jumsu,number,i);
    }

    for(int i=0; i<number; i++){
        average_student[i] = sum_student[i]/3.0;
    }

    for(int i=0; i<number; i++){
        grade[i] = getGrade(average_student[i]);
    }

    for(int i=0; i<3; i++){
        sum_class[i] = classSum(jumsu,number,i);
    }

    for(int i=0; i<3; i++){
        average_class[i] = sum_class[i]/(float)number;
    }

    for(int i=0; i<number; i++){
        printf("%d) %d %.1f %c\n", i+1, sum_student[i],average_student[i], grade[i]);
    }
    for(int i=0; i<3; i++){
        printf("%s %d %.1f\n", class_name[i], sum_class[i],average_class[i]);
    }
    first = firstRanking(average_student, number);
    printf("1st Ranking: %d", first+1);

	return 0;
}


int studentSum(int s[20][3], int size, int index){
    int sum = s[index][0] + s[index][1] + s[index][2];
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

int classSum(int s[20][3], int size, int index){
    int sum =0;
    for(int i=0; i<size; i++){

        sum += s[i][index];
    }
    return sum;
}

int firstRanking(float s[20], int size){
    float first=0;
    int num=0;
    for(int i=0; i<size; i++){
        if(s[i] > first){
        first = s[i];
        num = i;
        }
    }
    return num;
}
