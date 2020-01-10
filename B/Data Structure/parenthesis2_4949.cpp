#include<iostream>
#define MAX_LIST 101

using namespace std;

char str_input[MAX_LIST];
bool parenthesis_stack[MAX_LIST];
// true = (), false = []

bool end_cmd() {
	if (str_input[0] == '.' && str_input[1] == '\0') {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char cmd;
	int register finger;
	int register stack_finger;
	while(1) {
		cin.getline(str_input, MAX_LIST);
		if (end_cmd()) {
			break;
		}
		finger = 0;
		stack_finger = -1;
		while ((cmd = str_input[finger++]) != '\0') {
			if (cmd == '(') {
				parenthesis_stack[++stack_finger] = true;
			}
			else if (cmd == ')') {
				if (stack_finger < 0) {
					stack_finger = -2;
					break;
				}
				if (parenthesis_stack[stack_finger]) {
					stack_finger--;
				}
				else {
					break;
				}
			}
			else if (cmd == '[') {
				parenthesis_stack[++stack_finger] = false;
			}
			else if (cmd == ']') {
				if (stack_finger < 0) {
					stack_finger = -2;
					break;
				}
				if (!parenthesis_stack[stack_finger]) {
					stack_finger--;
				}
				else {
					break;
				}
			}
			if (stack_finger < -1) {
				break;
			}
		}
		if (stack_finger == -1) {
			cout << "yes" << "\n";
		}
		else{
			cout << "no" << "\n";
		}
	}
	
	return 0;
}