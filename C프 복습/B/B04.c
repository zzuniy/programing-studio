// 1) 255 85.0
// 2) 254 84.7
// 3) 255 85.0
// 4) 221 73.7
// 5) 264 88.0

#include <stdio.h>

int main(){

int jumsu[5][3];  // 5명의 3과목 점수를 저장하는 2차원 배열
int sum[5];  // 학생별 총점
float average[5];  // 학생별 평균

for(int i=0; i<5; i++){
    scanf("%d", &jumsu[i][0]);
    scanf("%d", &jumsu[i][1]);
    scanf("%d", &jumsu[i][2]);
}


for(int i=0; i<5; i++){
    sum[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2];
}

for(int i=0; i<5; i++){
    average[i] = sum[i] / 3.0;
}

for(int i=0; i<5; i++){
    printf("%d) %d %f\n", i+1, sum[i], average[i]);
}
   
    return 0;
}


