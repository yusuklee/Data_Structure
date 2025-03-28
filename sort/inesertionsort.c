void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while (arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr1[]={5,4,3,2,1};
    printf("array:");
    for(int i=0;i<5;i++){
        printf("%d,",arr1[i]);
    }
    printf("\n");
    printf("after sorting:");
    insertionsort(arr1,5);
    for(int i=0;i<5;i++){
        printf("%d,",arr1[i]);
    }
}