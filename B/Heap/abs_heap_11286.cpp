#include<iostream>
using namespace std;
#define ABS(a) ((a>0) ? (a) : (a*(-1)))
#define MAX_NUM 100000
int arr[MAX_NUM];
int idx = 0;
void percolateUp(int i) {
	int parent = (i % 2 == 0) ? (i / 2) : ((i - 1) / 2);
	if (parent >= 1) {
		if ((ABS(arr[i - 1]) < ABS(arr[parent - 1])) || ((ABS(arr[i - 1]) == ABS(arr[parent - 1])) && (arr[i - 1] < arr[parent - 1]))) {
			int tmp = arr[i - 1];
			arr[i - 1] = arr[parent - 1];
			arr[parent - 1] = tmp;
			percolateUp(parent);
		}
	}
}

void percolateDown(int i, int n) {
	int lChild = 2 * i;
	int rChild = 2 * i + 1;
	if (lChild <= n) {
		if ((rChild <= n) && ( (ABS(arr[lChild - 1]) > ABS(arr[rChild - 1])) || ((ABS(arr[lChild - 1]) == ABS(arr[rChild - 1])) && (arr[lChild - 1] > arr[rChild - 1])))) {
			lChild = rChild;
		}
		if ((ABS(arr[i - 1]) > ABS(arr[lChild - 1])) || (ABS(arr[i - 1]) == ABS(arr[lChild - 1]) && (arr[i - 1] > arr[lChild - 1]))) {
			int tmp = arr[i - 1];
			arr[i - 1] = arr[lChild - 1];
			arr[lChild - 1] = tmp;
			percolateDown(lChild, n);
		}
	}
}

void add_heap(int k) {
	arr[idx++] = k;
	if (idx > 1) {
		percolateUp(idx);
	}
}

void remove_heap() {
	if (idx == 0) {
		cout << "0\n";
	}
	else {
		cout << arr[0] << "\n";
		arr[0] = arr[idx - 1];
		percolateDown(1, --idx);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, x;
	cin >> N;
	while (N-- > 0) {
		cin >> x;
		if (x == 0) {
			remove_heap();
		}
		else {
			add_heap(x);
		}
	}
	return 0;
}