#include<stdio.h>
int binarySearch(int arr[],int low,int high,int target){
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            high=mid-1;
        }else if(arr[mid]<target){low=mid+1;}
        else return mid;
    }
    return -1;
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

    int result=binarySearch(arr,0,n-1,target);

    if(result!=-1){
        printf("element found at index:%d",result);
    }else{
        printf("element not found in the array");
    }
    return 0;
}