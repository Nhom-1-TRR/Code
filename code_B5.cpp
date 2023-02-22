int  BinarySearch(int arr[], int l, int r, int x){
    int m;
    while(l <= r){
        m = l + (r - l)/2;
        if(arr[m] == x) return m;
        else if(arr[m] > x) r = m - 1;
        else l = m + 1;
    }
    return l;
}
void BinaryInsertionSort(int arr[], int n){
    int i, j, sav;
    for(int i = 2; i <= n; i++){
        sav = arr[i];
        j = i - 1;
        /// Tìm vị trí
        int id = BinarySearch(arr, 1, j, sav);

        while(id <= j){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[id] = sav;
    }
}

