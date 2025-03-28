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
void insertionSort(int arr[],int n){
    int i, key, j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;

        while (j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
        
    }
}

int main(int argc,char *argv[]){
    if(argc<2){
        printf("enter the argument value:\n");
        return -1;
    }
    int n=argc-1;
    int *arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("memory allocation failed\n");
        return -1;
    }
    for(int i=0;i<n;i++){
        arr[i]=atoi(argv[i+1]);
    }
    insertionSort(arr,n);

    printf("Array");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");

    int target;

    printf("enter the target value to search:");
    scanf("%d",&target);

    int result=binarySearch(arr,0,n-1,target);

    if(result!=-1){
        printf("element found at index:%d\n",result);
    }else{
        printf("element not found in the array\n");
    }
    return 0;
}