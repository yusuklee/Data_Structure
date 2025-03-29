#include<stdio.h>
void swap(int* a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


int partition(int arr[], int low, int high){
    int piv = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(piv>arr[j]) {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high){
    if(high>low){
        int piv = partition(arr,low,high);
        quicksort(arr,low,piv-1);
        quicksort(arr,piv+1,high);
    }
}

void printarray(int arr[], int n){
    printf("array:");
    for(int i=0;i<n;i++){
        printf("%d, ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr1[]={5,4,3,2,1,10,11,7,6};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    printarray(arr1,n);
    quicksort(arr1,0,n-1);
    printf("quicksort finish");
    printarray(arr1,n);
    
}