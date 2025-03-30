#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STUDENT 20
#define MAX_NAME 25

typedef struct{
    int id;
    char name[MAX_NAME];
    int score;
}student;

void inputstudent(student students[], int n){
    for(int i=0;i<n;i++){
        printf("\n ==enter info for student %d ==\n",i+1);

        printf("id:");
        scanf("%d",&students[i].id);

        printf("name:");
        scanf("%s",students[i].name);

        printf("score:");
        scanf("%d",&students[i].score);

    }
}

void printstudent(student students[], int n){
    printf("\n===Student List===\n");
    for(int i=0;i<n;i++){
        printf("Stuent %d\n",i+1);
        printf("id    :%d\n",students[i].id);
        printf("name  :%s\n",students[i].name);
        printf("score :%d\n",students[i].score);
    }
}

void searchstudent(student students[],int n, int target){
    int found=0;
    for(int i=0;i<n;i++){
        if(students[i].id==target){
            printf("\n=== Student Found ===\n");
            printf("ID    : %d\n", students[i].id);
            printf("Name  : %s\n", students[i].name);
            printf("Score : %d\n", students[i].score);
            found=1;
            break;
        }
    }
    if(found==0)printf("the student id is wrong");
}

void sortstudent(student students[], int n){
    student temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(students[j].score>students[j+1].score){
                temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    printf("enter number of student (max %d):",MAX_STUDENT);
    scanf("%d",&n);

    if(n<=0 || n>MAX_STUDENT){printf("invalid number of student"); return 0;}

    student students[n];

    inputstudent(students,n);
    sortstudent(students,n);
    printstudent(students,n);

    int searchid;
    while (1)
    {
        printf("enter student id to search(-1 to exit):");
        scanf("%d",&searchid);

        if(searchid==-1) break;

        searchstudent(students,n,searchid);
    }
    
    return 0;
    
}