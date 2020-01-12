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
	for (i = N ; i > 1; --i) {
		tmp = arr[0];
		arr[0] = arr[i - 1];
		arr[i - 1] = tmp;
		percolateDown(1, i - 1);
	}
}

int linear_search() {
	int H = arr[N - 1], cur_height = 0, cur_number = 0, idx = N - 1;
	while (H >= 0) {
		if (arr[idx] > H) {
			while (arr[idx] > H) {
				cur_number++;
				idx--;
			}
		}
		cur_height += cur_number * 1;
		if (cur_height >= M) {
			return H;
		}
		H--;
	}
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
	cout << linear_search();
	return 0;
}

