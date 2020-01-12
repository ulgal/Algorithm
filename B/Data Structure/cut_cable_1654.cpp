#include<iostream>
#define MAX_SIZE 10000
using namespace std;

int arr[MAX_SIZE];
int K, N;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i;
	long long sum = 0;
	cin >> K >> N;
	for (i = 0; i < K; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	long long start = 1, end = sum / N;
	long long mid, n;
	long long cur_max = 1;
	while (start <= end) {
		mid = (start + end) / 2;
		n = 0;
		for (i = 0; i < K; ++i) {
			n += arr[i] / mid;
		}
		if (n >= N) {
			start = mid + 1;
			cur_max = (cur_max > mid) ? (cur_max) : (int)(mid);
		}
		else {
			end = mid - 1;
		}
	}
	cout << cur_max;
	return 0;
}