#include<iostream>
#include<string>
using namespace std;

#define MAX_QUEUE_SIZE 10001

int queue[MAX_QUEUE_SIZE];
int queue_front = 0;
int queue_back = -1;

#define QUEUE_SIZE (queue_back - queue_front + 1)
#define QUEUE_EMPTY ((QUEUE_SIZE > 0) ? (0) : (1))

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i, K;
	string cmd;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> K;
			queue[++queue_back] = K;
		}
		else if (cmd == "pop") {
			if ((QUEUE_EMPTY)) {
				cout << "-1\n";
			}
			else {
				cout << queue[queue_front++] << "\n";
			}
		}
		else if (cmd == "size") {
			cout << QUEUE_SIZE << "\n";
		}
		else if (cmd == "empty") {
			cout << QUEUE_EMPTY << "\n";
		}
		else if (cmd == "front") {
			if (!QUEUE_EMPTY) {
				cout << queue[queue_front] << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (cmd == "back") {
			if (!QUEUE_EMPTY) {
				cout << queue[queue_back] << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}