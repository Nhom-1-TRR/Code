#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	
	for (int i = 1 ; i < n ; i++){
		int key = a[i];
		int first = 0;
		int last = i;
		while (last != first){
			int c = (first + last )/2;
			if (a[i] <= a[c]){
				last = c;
			}
			else first = c + 1;
		}
		for (int j = i ; j > last ; j--){
			a[j] = a[j-1];
		}
		a[last] = key;
	}
	
	for (int i = 0 ; i < n ; i++){
		cout << a[i] << " ";
	}
	return 0;
}
