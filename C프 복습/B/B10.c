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
void printJumsu(struct st_jumsu* p);
struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index);
int countGrade(struct st_jumsu* data[], int size, char grade);

int main(){
	struct st_jumsu* jdata[20]; // 최대 20명의 점수 데이터
	// int sum_class[3]; // 과목별 총점
	// float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};

	struct st_jumsu* first[3];
    
	char grades[5] = "ABCDF";
	int count_grade[5];
	int count;
    int num=0; 

 
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        jdata[i]= malloc(sizeof(struct st_jumsu));
    
        if (jdata[i] == NULL){
            printf("%d is NULL\n", i);
            return -1;
        }
    }
     for(int i=0; i<3; i++){
        first[i]= malloc(sizeof(struct st_jumsu));
    
        if (first[i] == NULL){
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
    
    for(int i=0; i<num; i++){
        printf("%d) ", i+1);
        printJumsu(jdata[i]);
    }
  
    for(int i=0; i<3; i++){
        printf("[%s] ", class_name[i]);
        firstRanking(jdata, num, i);
    }
    for(int i=0; i<5; i++){
        count_grade[i] = countGrade(jdata, num, grades[i]);
    }
    for(int i=0; i<5; i++){
        printf("[%c] %d\n", grades[i], count_grade[i]);
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
    printf("%s - %d %.1f %c\n", p-> name, p -> sum, p -> avg, p-> grade);

}

struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index){
    int first= 0; 
    int first_num=0;
        for(int i=0; i<size; i++){
            if(data[i] -> jumsu[index]> first){
                first = data[i]-> jumsu[index];
                first_num = i;
                
            }
        }
        printf("%s %d\n",data[first_num]-> name, data[first_num]-> jumsu[index]);

        return data[first_num];
}

int countGrade(struct st_jumsu* data[], int size, char grade){
    int sum =0;
    for(int i=0; i<size; i++){
        if(data[i] -> grade == grade){
            sum ++;
        }
    }
    return sum;
}
