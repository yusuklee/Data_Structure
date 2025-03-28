#include<stdio.h>

void bubblesort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            }
        }
    }
    
}

int main(){
    int arr1[]={5,4,3,2,1};
    printf("array:");
    for(int i=0;i<5;i++){
        printf("%d,",arr1[i]);
    }
    printf("\n");
    bubblesort(arr1,5);
    printf("array after sorting:");
    for(int i=0;i<5;i++){
        printf("%d,",arr1[i]);
    }

}