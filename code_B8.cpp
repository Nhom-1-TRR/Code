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