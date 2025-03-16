#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_person{
	char name[20]; 	// Name (single word, no duplicates)
	int gender;  	// 0 - Female, 1 - Male
	int country;	// Country code (index of COUNTRY_NAME 0~5)
	int birthyear; 	// Birthyear
    };

    int getCountry(char* str);
// 파라미터: 국적을 나타내는 문자열(str) 
    // 리턴값: 국적에 해당되는 인덱스 (0~5)
    // 수행내용: 국적 문자열에 해당하는 인덱스를 찾는다.

    void printInfo(struct st_person* p);
    // 파라미터: 학생정보 구조체 포인터(p) 
    // 리턴값: 없음
    // 수행내용: 해당 학생 정보의 내용을 출력한다.

    int countGender(struct st_person* data[], int size, int gender);
    // 파라미터: 학생정보 데이터 포인터 배열(data), 데이터 개수, 성별 인덱스(0~1) 
    // 리턴값: 해당 성별 인원수
    // 수행내용: 모든 학생 정보 데이터에서 특정 성별인 인원수를 구한다.


int main(){
    struct st_person* pdata[20]; // 최대 20명의 데이터
    char country[5]; // 국적입력을 위한 문자열
    char count_gender[2]; // 성별 인원수
    int count;  // 인원수
    
    scanf("%d", &count);
        for(int i=0; i<count; i++){
            pdata[i] = malloc(sizeof(struct st_person));
        if(pdata[i] == NULL){
            printf("It is NULL");
            return -1;
        }
    }
    
    for(int i=0; i<count; i++){
          scanf("%s", pdata[i] -> name);
        scanf("%d", &pdata[i] -> gender);
        scanf("%s", country);
        scanf("%d", &pdata[i] -> birthyear);
        
        pdata[i]-> country = getCountry(country);
    }
      for(int i=0; i<2; i++){
        count_gender[i] = countGender(pdata, count, i);
    }
    

    for(int i=0; i<count; i++){
        printf("%d) ",i+1);
        printInfo(pdata[i]);
    }

    printf("Female:%d Male:%d", count_gender[0], count_gender[1]);

    return 0;
}

int getCountry(char* str){

    char cn_name[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};

    for(int i=0; i<6; i++){

        if(strcmp(str, cn_name[i]) == 0)
        return i;
        
    }

    return 5;
}
void printInfo(struct st_person* p){
    int age = 2025 - p->birthyear;
    char cn_name[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};

    printf("%s ", p-> name);

    if(p -> gender == 0)
    printf("(Female, ");

    else{
        printf("(Male, ");
    }

    printf("age:%d, ",age);

    for(int i=0; i<6; i++){
        if(p -> country == i)
            printf("from %s)\n", cn_name[i]);
    }
}

 int countGender(struct st_person* data[], int size, int gender){
    int num =0;

    for(int i=0; i<size; i++){
        
        if(data[i] -> gender ==gender){
            num++;
        }
    }
    return num;
 }
