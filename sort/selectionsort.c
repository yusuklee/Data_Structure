#include<stdio.h>
void selectionsort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[min_index]>arr[j]){
                min_index=j; 
            }
        }
        int temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int arr1[]={5,4,3,2,1};
    printf("array:");
    for(int i=0;i<5;i++){
        printf("%d",arr1[i]);
    }
    printf("\n");
    printf("array after sorting:");
    selectionsort(arr1,5);
    for(int i=0;i<5;i++){
        printf("%d",arr1[i]);
    }
}