#include<iostream>
using namespace std;

#define MAX_STACK_SIZE 10000

int stack_index = -1;
int stack[MAX_STACK_SIZE] = { 0 };
char push_cmd[] = "push";
char pop_cmd[] = "pop";
char size_cmd[] = "size";
char empty_cmd[] = "empty";
char top_cmd[] = "top";

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
	int N, i;
	char cmd[10];
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> cmd;
		if (str_compare(cmd, push_cmd, 4)) {
			cin >> stack[++stack_index];
		}
		else if (str_compare(cmd, pop_cmd, 3)) {
			if (stack_index == -1) {
				cout << -1 << endl;
			}
			else {
				cout << stack[stack_index--] << endl;
			}
		}
		else if (str_compare(cmd, size_cmd, 4)) {
			cout << stack_index+1 << endl;
		}
		else if (str_compare(cmd, empty_cmd, 5)) {
			cout << ((stack_index >= 0) ? (0) : (1)) << endl;
		}
		else if (str_compare(cmd, top_cmd, 3)) {
			if (stack_index >= 0) {
				cout << stack[stack_index] << endl;
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