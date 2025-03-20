#include<stdio.h>
#include <time.h>
int binarySearch(int arr[],int low,int high,int target){
    if(low>high){return -1;}
    int mid=(low+high)/2;
    if(target>arr[mid]){
    low=mid+1;}else if(target<arr[mid]){
        high=mid-1;
    }else{return mid;}
    return binarySearch(arr,low,high,target);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target;

    printf("Array: ");

    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("enter the search target: ");
    scanf("%d",&target);

    clock_t start_time=clock();
    int result=binarySearch(arr,0,n-1,target);
    clock_t end_time=clock();

    if(result!=-1){
        printf("element found at index:%d",result);
        
    }else{
        printf("element not found in the array");
    }
    printf("Execution time:%.10f seconds",(double)(end_time-start_time)/CLOCKS_PER_SEC);
    return 0;
}