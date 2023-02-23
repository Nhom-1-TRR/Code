#include <bits/stdc++.h>

using namespace std;

int ternarySearch(int arr[], int left, int x) {
    int left = 0, right = n - 1;
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
            right = mid1 - 1;
        } else if (x > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
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
void countingSort(vector<int>& arr, int range) {
    vector<int> count(range + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= range; i++) {
        count[i] += count[i-1];
    }
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
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
