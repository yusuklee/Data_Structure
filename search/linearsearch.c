int linearsearch(int arr[], int size, int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target)return i;
    }
    return -1;
}
int main(){
    int arr1[]={1,2,3,4,5};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int index=linearsearch(arr1,n,3);
    printf("3 is at index arr1[%d]",index);
    return 0;
}