#include<iostream>
#define MAX_HASH 201
#define MAX_SIZE 100000
using namespace std;

int arr[MAX_HASH][MAX_SIZE];
int idx[MAX_HASH];
char name[MAX_SIZE][101];
int N;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;
	int age;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> age >> name[i];
		arr[age][idx[age]++] = i;
	}
	for (i = 1; i < MAX_HASH; ++i) {
		for (j = 0; j < idx[i]; ++j) {
			cout << i << ' ' << name[arr[i][j]] << '\n';
		}
	}
	return 0;
}