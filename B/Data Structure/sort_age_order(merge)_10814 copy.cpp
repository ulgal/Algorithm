#include<iostream>
#define MAX_SIZE 100000
using namespace std;

int arr[MAX_SIZE][2];
char name[MAX_SIZE][101];
int cpy[MAX_SIZE][2];
int N;

void merge(int st1, int ed1, int st2, int ed2) {
	int length1 = ed1 - st1 + 1;
	int length2 = ed2 - st2 + 1;
	int cur_idx = st1;
	int start = st1;
	int end = ed2;
	int i;
	while (st1 <= ed1 || st2 <= ed2) {
		if (st1 > ed1) {
			while (st2 <= ed2) {
				cpy[cur_idx][0] = arr[st2][0];
				cpy[cur_idx][1] = arr[st2][1];
				cur_idx++;
				st2++;
			}
		}
		else if (st2 > ed2) {
			while (st1 <= ed1) {
				cpy[cur_idx][0] = arr[st1][0];
				cpy[cur_idx][1] = arr[st1][1];
				cur_idx++;
				st1++;
			}
		}
		else {
			if (arr[st1][0] > arr[st2][0]) {
				cpy[cur_idx][0] = arr[st2][0];
				cpy[cur_idx][1] = arr[st2][1];
				cur_idx++;
				st2++;
			}
			else {
				cpy[cur_idx][0] = arr[st1][0];
				cpy[cur_idx][1] = arr[st1][1];
				cur_idx++;
				st1++;
			}
		}
	}
	for (i = start; i <= end; ++i) {
		arr[i][0] = cpy[i][0];
		arr[i][1] = cpy[i][1];
	}
}

void merge_sort(int start, int end) {
	if (end - start < 1) {
		return;
	}
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	merge(start, mid, mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> arr[i][0] >> name[i];
		arr[i][1] = i;
	}
	merge_sort(0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << arr[i][0] << ' ' << name[arr[i][1]] << '\n';
	}
	return 0;
}