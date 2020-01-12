#include<iostream>
#define MAX_SIZE 1000000
using namespace std;

int arr[MAX_SIZE];
int N, M;

void show(int k) {
	for (int i = 0; i < k; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

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
	int i, tmp, check_idx, check_val, j;
	for (i = (N / 2); i > 0; --i) {
		percolateDown(i, N);
	}
	for (i = N; i > 1; --i) {
		tmp = arr[0];
		arr[0] = arr[i - 1];
		arr[i - 1] = tmp;
		percolateDown(1, i - 1);
	}
}

long long binary_search() {
	long long start = 0, end = arr[N - 1];
	long long mid;
	long long cur_max = 0;
	int i;
	long long H;
	while (start <= end) {
		mid = (start + end) / 2;
		H = 0;
		for (i = 0; i < N; ++i) {
			if (arr[i] > mid) {
				H += arr[i] - mid;
			}
		}
		if (H >= M) {
			cur_max = cur_max > mid ? cur_max : mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return cur_max;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, t;
	cin >> N >> M;
	for (i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	heap_sort();
	cout << binary_search();
	return 0;
}

