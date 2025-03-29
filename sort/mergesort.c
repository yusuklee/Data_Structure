#include<stdio.h>

void merge(int arr[], int left, int mid, int right){
    int i=left;
    int j = mid+1;
    int k=0;
    int temp[right-left+1];

    while (i<=mid && j<=right)
    {if(arr[i]<arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }

    while (i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while (j<=right)
    {
        temp[k++]=arr[j++];
    }
    
    int index=0;
    for(int a=left;a<=right;a++){
        arr[a]=temp[index++];
    }
    
    
}

void mergesort(int arr[], int left, int right){
    if(right>left){ 
    int mid = (left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
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
    int arr1[]={5,4,3,2,1,10};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    printarray(arr1,n);
    printf("after sorting");
    mergesort(arr1,0,n-1);
    printarray(arr1,n);

    return 0;

}