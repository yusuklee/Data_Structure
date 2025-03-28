void selectionsort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j; //가장작은 값을 가진 인덱스를 찾는과정
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int main(){
    int arr1[]={5,4,3,2,1};
    printf("array:");
    for(int i=0;i<5;i++){
        printf("%d,",arr1[i]);
    }
    printf("\n");
    printf("array after sorting:");
    selectionsort(arr1,5);
    for(int i=0;i<5;i++){
        printf("%d,",arr1[i]);
    }
    
}