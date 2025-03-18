#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_movie{
	char title[100];
	int year, genre, playtime, viewers;
	char description[255];
} MOVIE;


void printMovie(MOVIE* p);
int indexGenre(char* name);

void printGenreCount(MOVIE* list[], int size);
void printReport(MOVIE* list[], int size);
int loadRecords(MOVIE* list[]);
int maxViewers(MOVIE* list[], int size);
int maxPlaytime(MOVIE* list[], int size);

const char* genre_name[] = {
    "Sci-Fi",
    "Thriller",
    "Action",
    "Romance",
    "Musical",
    "Drama",
    "Animation",
    "War"
};
//메인
int main() {
    MOVIE* mlist[50];
	int count;

	count = loadRecords(mlist);	
	for(int i=0; i<count; i++){
		printf("%d) ", i+1);
		printMovie(mlist[i]);
	}
    printf("\n");

    printGenreCount(mlist,count);
	printReport(mlist, count);

	return 0;
   
}

//영화 정보 출력
void printMovie(MOVIE* p){
    printf("%s [%d, %s, %d min, %d viewers]\n", p->title,  p->year, genre_name[p->genre], p->playtime, p-> viewers );
}

//장르 번호 찾기
int indexGenre(char* name){
    for(int i=0; i<7; i++){
        if(strcmp(name, genre_name[i]) == 0){
            return i;
        }    
    }
    return -1;
}

//장르 개수 새기
void printGenreCount(MOVIE* list[], int size){
    int numMovie[8]={0};
    for(int k=0; k<8; k++){
        for(int i=0; i<size; i++){

            if(k == list[i] -> genre){
                numMovie[k] ++;
            }
        }
    }

    printf("1. Number of movies by genre\n");
    for(int i=0; i<8; i++){
        printf("[%d] %s     %d movies\n", i+1,genre_name[i], numMovie[i]); 
    }
    printf("\n");
    
}
//두번째 섹션 출력
void printReport(MOVIE* list[], int size){
    int max_play = maxPlaytime(list, size);
    int max_view = maxViewers(list, size);

    printf("2. Longest\n");
    printf("%s [%d, %s, %d min, %d viewers]\n", list[max_play]->title,  list[max_play]->year, genre_name[list[max_play]->genre], list[max_play]->playtime, list[max_play]-> viewers );
    printf("%s\n", list[max_play] -> description);

    printf("3. Most popular\n");
    printf("%s [%d, %s, %d min, %d viewers]\n", list[max_view]->title,  list[max_view]->year, genre_name[list[max_view]->genre], list[max_view]->playtime, list[max_view]-> viewers );
    printf("%s", list[max_play] -> description);

}
//입력받기 
int loadRecords(MOVIE* list[]){
    char title[100], desc[255], genre[50];
	int year, playtime, viewers;
	int count=0;

	scanf("%d", &count);

	for(int i=0; i<count; i++){
        
		getchar();
		fgets(title, 100, stdin);
		fgets(desc, 255, stdin);
		scanf("%d %s %d %d", &year, genre, &playtime, &viewers);

		list[i] = (MOVIE*) malloc(sizeof(MOVIE));
        strcpy(list[i]->title, title);
        strcpy(list[i]->description, desc);

        list[i] -> year = year;
        list[i] -> viewers = viewers ;
        list[i] -> playtime = playtime;
        list[i] -> genre = indexGenre(genre);
    }
    return count;
}

//가장 많은 시청자를 가진 영화
int maxViewers(MOVIE* list[], int size){

    int max=0;
    int max_num=0;

    for(int i=0; i<size; i++){

        if(list[i] -> viewers >max){

            max = list[i] -> viewers;
            max_num = i;
        }
    }
    return max_num;
}

//가장 많은 시청 시간을 가진 영화
int maxPlaytime(MOVIE* list[], int size){

    int max=0;
    int max_num=0;

    for(int i=0; i<size; i++){

        if(list[i] -> playtime >max){

            max = list[i] -> playtime;
            max_num = i;
        }
    }
    return max_num;
}