#include<iostream>

using namespace std;

#define MAX_QUEUE_SIZE 10000
#define LAST_INDEX 9999

int queue_front = 0;
int queue_back = -1;
int queue[MAX_QUEUE_SIZE];
int overflow_flag = 0;
char push_cmd[] = "push";
char pop_cmd[] = "pop";
char size_cmd[] = "size";
char empty_cmd[] = "empty";
char front_cmd[] = "front";
char back_cmd[] = "back";

int str_compare(char* src, char* dst, int length) {
	int i;
	for (i = 0; i < length; ++i) {
		if (src[i] != dst[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i, K;
	char cmd[10];
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> cmd;
		if (str_compare(cmd, push_cmd, 4)) {
			cin >> K;
			if (queue_back - queue_front + 1 + overflow_flag * MAX_QUEUE_SIZE == MAX_QUEUE_SIZE) {
				cout << "queue is full" << "\n";
			}
			else {
				queue[++queue_back] = K;
			}

			if (queue_back == LAST_INDEX) {
				queue_back = -1;
				overflow_flag++;
			}
		}
		else if (str_compare(cmd, pop_cmd, 3)) {
			if ((queue_back - queue_front < 0 && overflow_flag == 0)) {
				cout << "-1\n";
			}
			else {
				cout << queue[queue_front++] << "\n";
				if (queue_front == MAX_QUEUE_SIZE) {
					queue_front = 0;
					overflow_flag--;
				}
			}
		}
		else if (str_compare(cmd, size_cmd, 4)) {
			cout << queue_back - queue_front + 1 + overflow_flag * MAX_QUEUE_SIZE << "\n";
		}
		else if (str_compare(cmd, empty_cmd, 5)) {
			cout << ((queue_back - queue_front + 1 + overflow_flag * MAX_QUEUE_SIZE > 0) ? (0) : (1)) << "\n";
		}
		else if (str_compare(cmd, front_cmd, 5)) {
			if (queue_back - queue_front + 1 + overflow_flag * MAX_QUEUE_SIZE > 0) {
				cout << queue[queue_front] << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (str_compare(cmd, back_cmd, 4)) {
			if (overflow_flag == 1 && queue_back == -1) {
				cout << queue[LAST_INDEX] << "\n";
			}
			else if (queue_back - queue_front + 1 + overflow_flag * MAX_QUEUE_SIZE > 0) {
				cout << queue[queue_back] << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else {
			cout << "undefined command" << "\n";
		}
	}
	return 0;
}