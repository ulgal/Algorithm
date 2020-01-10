#include<iostream>

using namespace std;

#define MAX_DEQUE_SIZE 10000
#define LAST_INDEX 9999

int deque_front = 0;
int deque_back = -1;
int deque[MAX_DEQUE_SIZE] = { 0 };
int overflow_flag = 0;
char push_front_cmd[] = "push_front";
char push_back_cmd[] = "push_back";
char pop_front_cmd[] = "pop_front";
char pop_back_cmd[] = "pop_back";
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
	int N, i, K;
	char cmd[16];
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> cmd;
		if (str_compare(cmd, push_front_cmd, 10)) {
			cin >> K;
			if (deque_back - deque_front + 1 + overflow_flag * MAX_DEQUE_SIZE == MAX_DEQUE_SIZE) {
				cout << "deque is full" << endl;
			}
			else {
				if (deque_front == 0) {
					deque_front = MAX_DEQUE_SIZE;
					overflow_flag++;
				}
				deque[--deque_front] = K;
			}
		}
		else if (str_compare(cmd, push_back_cmd, 9)) {
			cin >> K;
			if (deque_back - deque_front + 1 + overflow_flag * MAX_DEQUE_SIZE == MAX_DEQUE_SIZE) {
				cout << "deque is full" << endl;
			}
			else {
				deque[++deque_back] = K;
			}
			if (deque_back == LAST_INDEX) {
				deque_back = -1;
				overflow_flag++;
			}
		}
		else if (str_compare(cmd, pop_front_cmd, 9)) {
			if ((deque_back - deque_front < 0 && overflow_flag == 0)) {
				cout << -1 << endl;
			}
			else {
				cout << deque[deque_front++] << endl;
				if (deque_front == MAX_DEQUE_SIZE) {
					deque_front = 0;
					overflow_flag--;
				}
			}
		}
		else if (str_compare(cmd, pop_back_cmd, 8)) {
			if ((deque_back - deque_front < 0 && overflow_flag == 0)) {
				cout << -1 << endl;
			}
			else {
				if (deque_back == -1) {
					deque_back = LAST_INDEX;
					overflow_flag--;
				}
				cout << deque[deque_back--] << endl;
			}
		}
		else if (str_compare(cmd, size_cmd, 4)) {
			cout << deque_back - deque_front + 1 + overflow_flag * MAX_DEQUE_SIZE << endl;
		}
		else if (str_compare(cmd, empty_cmd, 5)) {
			cout << ((deque_back - deque_front + 1 + overflow_flag * MAX_DEQUE_SIZE > 0) ? (0) : (1)) << endl;
		}
		else if (str_compare(cmd, front_cmd, 5)) {
			if (deque_back - deque_front + 1 + overflow_flag * MAX_DEQUE_SIZE > 0) {
				cout << deque[deque_front] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (str_compare(cmd, back_cmd, 4)) {
			if (overflow_flag == 1 && deque_back == -1) {
				cout << deque[LAST_INDEX] << endl;
			}
			else if (deque_back - deque_front + 1 + overflow_flag * MAX_DEQUE_SIZE > 0) {
				cout << deque[deque_back] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else {
			cout << "undefined command" << endl;
		}
	}
	return 0;
}