#include<iostream>
#define MAX_SIZE 500000
using namespace std;

int arr[MAX_SIZE][2];
int N;
int min_val, max_val;

void show(int k, int idx) {
	cout << idx << endl;
	for (int i = 0; i < k; ++i) {
		cout << arr[i][0] << " ";
	}
	cout << endl;
	for (int i = 0; i < k; ++i) {
		cout << arr[i][1] << " ";
	}
	cout << endl;
}

void percolateDown(int i, int n) {
	int lChild = 2 * i;
	int rChild = 2 * i + 1;
	if (lChild <= n) {
		if ((rChild <= n) && (arr[lChild - 1][0] < arr[rChild - 1][0])) {
			lChild = rChild;
		}
		if (arr[i - 1][0] < arr[lChild - 1][0]) {
			int tmp = arr[i - 1][0];
			arr[i - 1][0] = arr[lChild - 1][0];
			arr[lChild - 1][0] = tmp;
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
	tmp = arr[0][0];
	arr[0][0] = arr[N - 1][0];
	arr[N - 1][0] = tmp;
	percolateDown(1, N - 1);
	check_val = tmp;
	check_idx = N - 1;
	for (i = N - 1; i > 1; --i) {
		tmp = arr[0][0];
		arr[0][0] = arr[i - 1][0];
		arr[i - 1][0] = tmp;
		if (arr[i - 1][0] != check_val) {
			for (j = i; j <= check_idx; ++j) {
				arr[j][1] = check_idx - i + 1;
			}
			check_val = arr[i - 1][0];
			check_idx = i - 1;
		}
		percolateDown(1, i - 1);
	}
	if (arr[i - 1][0] != check_val) {
		for (j = i; j <= check_idx; ++j) {
			arr[j][1] = check_idx - i + 1;
		}
		arr[0][1] = 1;
	}
	else {
		for (j = 0; j <= check_idx; ++j) {
			arr[j][1] = check_idx + 1;
		}
	}
}

int binary_search(int low, int high, int target) {
	if (target > max_val || target < min_val) {
		return 0;
	}
	if (low > high) {
		return 0;
	}
	int mid = (low + high) / 2;
	if (arr[mid][0] == target) {
		return arr[mid][1];
	}
	else if (arr[mid][0] > target) {
		return binary_search(low, mid - 1, target);
	}
	else {
		return binary_search(mid + 1, high, target);
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	int j, t;
	cin >> N;
	for (j = 0; j < N; ++j) {
		cin >> arr[j][0];
	}
	heap_sort();
	min_val = arr[0][0];
	max_val = arr[N - 1][0];
	cin >> M;
	for (j = 0; j < M; ++j) {
		cin >> t;
		cout << binary_search(0, N, t) << " ";
	}
	return 0;
}