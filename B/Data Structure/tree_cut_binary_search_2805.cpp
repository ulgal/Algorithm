#include<iostream>
#define MAX_SIZE 1000000
using namespace std;

int arr[MAX_SIZE];
int N, M;

long long binary_search(long long mx) {
	long long start = 0, end = mx;
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
	int max_val = 0;
	cin >> N >> M;
	for (i = 0; i < N; ++i) {
		cin >> arr[i];
		max_val = (max_val > arr[i]) ? (max_val) : (arr[i]);
	}
	cout << binary_search((long long)max_val);
	return 0;
}

