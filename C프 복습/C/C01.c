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
    


int main(){
    struct st_person* one; // 학생 1명의 데이터
    char country[5]; // 국적입력을 위한 문자열
    
    one = malloc(sizeof(struct st_person));
    if(one == NULL){
        printf("It is NULL");
        return -1;
    }

    scanf("%s", one -> name);
    scanf("%d", &one -> gender);
    scanf("%s", country);
    scanf("%d", &one -> birthyear);
    
    one -> country = getCountry(country);
    printInfo(one);

    return 0;
}

int getCountry(char* str){

    char cn_name[6][5] = {"KR", "US", "JP", "CN", "FR", "-"};

    for(int i=0; i<6; i++){

        if(strcmp(str, cn_name[i]) == 0)
        return i;
        
    }

    return 5;
}
void printInfo(struct st_person* p){
    int age = 2025 - p->birthyear;
    char cn_name[6][5] = {"KR", "US", "JP", "CN", "FR", "-"};

    printf("%s ", p-> name);

    if(p -> gender == 0)
    printf("(Female, ");

    else{
        printf("(Male, ");
    }

    printf("age:%d, ",age);

    for(int i=0; i<6; i++){
        printf("디버깅 p: %d []:%d\n", p->country, i );
        if(p -> country == i)
            printf("from %s)\n", cn_name[i]);
    }
    
}
