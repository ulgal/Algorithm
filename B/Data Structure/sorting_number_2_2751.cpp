#include<iostream>
#define MAX_VAL_SIZE 1000000
using namespace std;

int arr[MAX_VAL_SIZE];
int N;
void percolateDown(int i, int n) {
	int lChild = 2 * i;
	int rChild = 2 * i + 1;
	if (lChild <= n) {
		if ((rChild <= n) && (arr[lChild - 1] < arr[rChild - 1])) {
			lChild = rChild;
		}
		if (arr[i - 1] < arr[lChild - 1]) {
			int tmp = arr[i - 1];
			arr[i - 1] = arr[lChild - 1];
			arr[lChild - 1] = tmp;
			percolateDown(lChild, n);
		}
	}
}
void heap_sort() {
	if (N == 0) {
		return;
	}
	int i;
	for (i = (N / 2); i > 0; --i) {
		percolateDown(i, N);
	}
	for (i = N; i > 1; --i) {
		int tmp = arr[0];
		arr[0] = arr[i - 1];
		arr[i - 1] = tmp;
		percolateDown(1, i - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, t;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	heap_sort();
	for (i = 0; i < N; ++i) {
		cout << arr[i] << '\n';
	}


	return 0;
}