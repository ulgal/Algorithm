#include<iostream>
#define R 31
#define M 1234567891
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i, k;
	long long cur_x = 1;
	long long ans = 0;
	char str[51];
	cin >> N;
	cin >> str;
	for (i = 0; i < N; ++i) {
		k = str[i] - 'a' + 1;
		ans += cur_x * k;
		ans %= M;
		cur_x *= R;
		cur_x %= M;
	}
	cout << ans;
	return 0;
}