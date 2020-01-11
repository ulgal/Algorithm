#include<iostream>
#define MAX_SIZE 20000001
#define ADDER 10000000
using namespace std;

int arr_hash[MAX_SIZE];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, t;
	int register j;
	cin >> N;
	for (j = 0; j < N; ++j) {
		cin >> t;
		arr_hash[t + ADDER]++;
	}
	cin >> M;
	for (j = 0; j < M; ++j) {
		cin >> t;
		cout << arr_hash[t+ADDER] << " ";
	}
	return 0;
}