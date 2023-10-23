void reverseArray(int *a, int lenth){
    int t;
    for(int i = 0;i<=lenth/2;++i){
        t=a[i];
        a[i]=a[lenth-1-i];
        a[lenth-1-i]=t;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    puts("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    reverseArray(arr, length);

    printf("Reversed array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}