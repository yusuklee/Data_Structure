#include<stdio.h>

int binarysearch(int arr[], int size, int target){
    int left=0;
    int right = size-1;
    while (right>=left)
    {
        int mid = (left+right)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) right=mid-1;
        else left = mid+1;
    }
    return -1;
    
}
int main(){
    int arr1[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int target;

    printf("enter the number that you are trying to find at arr1:");
    scanf("%d",&target);
    if(binarysearch(arr1,n,target)==-1){
        printf("the number that you are finding is not in the arr1");
    }else{
        printf("the number is at arr1[%d]",binarysearch(arr1,n,target));
    }
} //탐색 완료