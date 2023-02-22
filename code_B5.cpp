int  BinarySearch(int arr[], int l, int r, int x){
    int m;
    if (r < l) return (x > arr[l] ? low + 1 : low);
    const int mid = floor((r + l) / 2);
    if (x == arr[]) return mid + 1;
    if (x > arr[mid]) 
        return BinarySearch(arr, l, mid - 1, x);
    return BinarySearch(arr, l, mid - 1, x);
}
vector<int> BinaryInsertionSort(vector<int> arr, int n){
    for(int i = 2; i <= n; i++){
        const int x = arr[i];
        int j = i - 1;
        const int index = BinarySearch(arr, 0, j, x);
        while (j >= index){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
    return arr;
}

