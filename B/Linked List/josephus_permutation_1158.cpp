#include<iostream>
#define MAX_SIZE 5001
using namespace std;

int next_element[MAX_SIZE];
int ans[MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	int i;
	int target = 1;
	int idx = 1;
	cin >> N >> K;
	if (K > 1) {
		for (i = 1; i <= N; ++i) {
			next_element[i] = i + 1;
		}
		next_element[N] = 1;
		while (idx <= N) {
			i = K;
			while (i > 2) {
				target = next_element[target];
				i--;
			}
			ans[idx++] = next_element[target];
			next_element[target] = next_element[next_element[target]];
			target = next_element[target];
		}
		cout << "<";
		for (i = 1; i < N; ++i) {
			cout << ans[i] << ", ";
		}
		cout << ans[N] << ">";
	}
	else {
		cout << "<";
		for (i = 1; i < N; ++i) {
			cout << i << ", ";
		}
		cout << N << ">";
	}
	
	
	return 0;
}