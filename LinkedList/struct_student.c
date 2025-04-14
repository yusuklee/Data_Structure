#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 20
#define MAX_NAME 25

struct Student
{
    int id;
    char name[MAX_NAME];
    int score;
};

void inputStudents(struct Student students[], int n){
    for(int i=0;i<n;i++){
        printf("write %d student info.\n",(i+1));

        printf("ID:\n");
        scanf("%d",&students[i].id);
        printf("Name:\n");
        scanf("%s",&students[i].name);
        printf("Score:\n");
        scanf("%d",&students[i].score);
        


    }
}

void printStudents(struct Student students[], int n){
    for(int i = 0; i < n; i++){
        printf("\nStudent %d\n", i+1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Score: %d\n", students[i].score);
    }
}


void searchStudent(struct Student students[], int n, int id){
    for(int i=0;i<n;i++){
        if(students[i].id==id){
            printf("Student Found:");
            printf("ID:%d",students[i].id);
            printf("Name:%s",students[i].name);
            printf("Score:%d",students[i].score);


        }
    }
}

void sortStudentsByScore(struct Student students[], int n){
    struct Student temp;
    for (int i = 0; i < n-1; i++){
        for(int j = 0; j< n - i -1; j++){
            if(students[j].score < students[j+1].score){
                temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d",&n);
    if(n>MAX_STUDENTS){
        printf("The students number has reached the maximum. exit");
        return 1;
    }
    struct Student students[n];
    
    
    

    inputStudents(students, n);
    sortStudentsByScore(students, n);
    printf("\nStudents sorted by scores: \n");
    printStudents(students, n);

    int searchID;
    while (1)
    {
        printf("\nEnter the ID of the student you want to search (Enter -1 to exit): ");
        scanf("%d", &searchID);
        if (searchID == -1)
        {
            break;
        }
        searchStudent(students, n, searchID);
        
    }

    return 0;
    
}