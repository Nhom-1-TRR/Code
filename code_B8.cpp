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