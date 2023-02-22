#include <bits/stdc++.h>

using namespace std;

int ternarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == x) {
            return mid1;
        }

        if (arr[mid2] == x) {
            return mid2;
        }

        if (x < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, x);
        } else if (x > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, x);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
        }
    }

    return -1;
}
/// 5
/// 1 4 5 8 10

void insertionSort(int arr[], int n){
    int i, j, sav;
    for(int i = 2; i <= n; i++){
        sav = arr[i];
        j = i - 1;

        /// Lớn hơn đẩy sang phải
        while(j >= 1 && arr[j] > sav) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = sav;
    }
}
int binarySearch(int arr[], int l, int r, int x){
    int m;
    while(l <= r){
        m = l + (r - l)/2;
        if(arr[m] == x) return m;
        else if(arr[m] > x) r = m - 1;
        else l = m + 1;
    }
    return l;
}
void binaryInsertionSort(int arr[], int n){
    int i, j, sav;
    for(int i = 2; i <= n; i++){
        sav = arr[i];
        j = i - 1;
        /// Tìm vị trí
        int id = binarySearch(arr, 1, j, sav);

        while(id <= j){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[id] = sav;
    }
}
void countingSort(int arr[], int n){
    int Max = arr[1];
    for(int i = 2; i <= n; i++) Max = max(Max, arr[i]);
    int d[Max + 1]; /// Đếm sl xuất hiển của index
    memset(d, 0, sizeof(d));
    for(int i = 1; i <= n; i++) d[arr[i]]++;
    int id = 0;

    for(int i = 0; i <= Max; i++) {
        while(d[i] > 0){
            d[i]--;
            arr[++id] = i;
        }
    }
    //cout << id;
}
/*
    Độ phức tạp thời gian của thuật toán sắp xếp đếm là O(n + k),
    trong đó n là số lượng phần tử trong dãy, k là giá trị lớn nhất
    có thể xuất hiện trong dãy. Tuy nhiên, độ phức tạp không gian
    của thuật toán là O(k), do cần sử dụng một mảng đếm để lưu trữ
    số lần xuất hiện của từng giá trị trong dãy.
*/
int main(){
    int n; cin >> n;
    int arr[n + 5];
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= n; i++) cin >> arr[i];
    //binaryInsertionSort(arr, n);
    //insertionSort(arr, n);
    countingSort(arr, n);
    for(int i = 1; i <= n; i++) cout << arr[i] << ' ';
    //cout << ternarySearch(arr, 1, n, 4);
}
