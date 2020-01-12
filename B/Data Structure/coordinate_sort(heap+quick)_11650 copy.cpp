#include<iostream>
#define MAX_SIZE 100000
using namespace std;

int arr[MAX_SIZE][2];
int N;


void quick_sort(int first, int last)
{
    int pivot;
    int i;
    int j;
    int temp_x, temp_y;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while ((arr[i][1] < arr[pivot][1] && i < last))
            {
                i++;
            }
            while ((arr[j][1] > arr[pivot][1]))
            {
                j--;
            }
            if (i < j)
            {
                temp_x = arr[i][0];
                temp_y = arr[i][1];
                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];
                arr[j][0] = temp_x;
                arr[j][1] = temp_y;
            }
        }
        temp_x = arr[pivot][0];
        temp_y = arr[pivot][1];
        arr[pivot][0] = arr[j][0];
        arr[pivot][1] = arr[j][1];
        arr[j][0] = temp_x;
        arr[j][1] = temp_y;

        quick_sort(first, j - 1);
        quick_sort(j + 1, last);
    }
}

void percolateDown(int i, int n) {
	int lChild = 2 * i;
	int rChild = 2 * i + 1;
	int tmp_x, tmp_y;
	if (lChild <= n) {
		if ((rChild <= n) && (arr[lChild - 1][0] < arr[rChild - 1][0])) {
			lChild = rChild;
		}
		if (arr[i - 1][0] < arr[lChild - 1][0]) {
			tmp_x = arr[i - 1][0];
			tmp_y = arr[i - 1][1];
			arr[i - 1][0] = arr[lChild - 1][0];
			arr[i - 1][1] = arr[lChild - 1][1];
			arr[lChild - 1][0] = tmp_x;
			arr[lChild - 1][1] = tmp_y;
			percolateDown(lChild, n);
		}
	}
}
void heap_sort() {
	if (N == 0) {
		return;
	}
	int i, tmp_x, tmp_y, check_idx, check_val, j;
	for (i = (N / 2); i > 0; --i) {
		percolateDown(i, N);
	}
	tmp_x = arr[0][0];
	tmp_y = arr[0][1];
	arr[0][0] = arr[N - 1][0];
	arr[0][1] = arr[N - 1][1];
	arr[N - 1][0] = tmp_x;
	arr[N - 1][1] = tmp_y;
	percolateDown(1, N - 1);
	check_val = tmp_x;
	check_idx = N - 1;
	for (i = N - 1; i > 1; --i) {
		tmp_x = arr[0][0];
		tmp_y = arr[0][1];
		arr[0][0] = arr[i - 1][0];
		arr[0][1] = arr[i - 1][1];
		arr[i - 1][0] = tmp_x;
		arr[i - 1][1] = tmp_y;
		if (arr[i - 1][0] != check_val) {
			quick_sort(i, check_idx);
			check_val = arr[i - 1][0];
			check_idx = i - 1;
		}
		percolateDown(1, i - 1);
	}
	if (arr[i - 1][0] != check_val) {
		quick_sort(i, check_idx);
	}
	else {
		quick_sort(0, check_idx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, t;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}
	heap_sort();
    for (i = 0; i < N; ++i) {
        cout << arr[i][0] << ' ' << arr[i][1] << '\n';
    }
	return 0;
}
