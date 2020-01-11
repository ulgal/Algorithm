#include<iostream>
#define max_val_SIZE 100000
using namespace std;

int arr[max_val_SIZE];
int N;
int min_val, max_val;
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

void quick_sort(int first, int last) {
	int pivot;
	int i;
	int j;
	int temp;
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (arr[i] <= arr[pivot] && i < last)
			{
				i++;
			}
			while (arr[j] > arr[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;

		quick_sort(first, j - 1);
		quick_sort(j + 1, last);
	}
}

int binary_search(int low, int high, int target) {
	if (target > max_val || target < min_val) {
		return 0;
	}
	if (low > high) {
		return 0;
	}
	int mid = (low+high) / 2;
	if (arr[mid] == target) {
		return 1;
	}
	else if (arr[mid] > target) {
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
		cin >> arr[j];
	}
	heap_sort();
	//quick_sort(0, N - 1);
	min_val = arr[0];
	max_val = arr[N - 1];
	cin >> M;
	for (j = 0; j < M; ++j) {
		cin >> t;
		cout << binary_search(0, N, t) << "\n";
	}
	

	return 0;
}