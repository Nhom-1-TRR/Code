#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0 ; i < n ; i ++){
		cin >> a[i];
	}
	int x;
	cin >> x;
	int last = n - 1;
	int first = 0;
	while (a[first] < x && a[last] >= x){
		int len = last - first + 1;
		int c = len/3;
		if (a[c+first] >= x){
			last = first + c;
		}
		else if (a[2*c+first] >= x && a[c+first] < x){
			first =  first + c+1;
			last = 2*c + first;
		}
		else first = first + 2*c+1;
	}
	cout << first;
	return 0;
}
