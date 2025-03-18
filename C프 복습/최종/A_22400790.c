
//허주은
// 22400790
// 나 허주은은 하나님과 사람 앞에서 정직하고 설실하게 테스트를 수행하겠습니다. 

#include <stdio.h>

const char *monthnames [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

int main(){

    char name[20];
    int birthdate; 
    int age;
    int year,month, day;

    scanf("%s %d",name, &birthdate);
    
    year = birthdate / 10000;  
    month = (birthdate / 100)%100; 
    day = birthdate %100;      
    age = 2025 - year;      

    printf("%s - %d (%s %d, %d)", name, age, monthnames[month-1], day, year);
    return 0;
}