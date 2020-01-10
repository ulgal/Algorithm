#include<iostream>
#define MAX_LIST 50

using namespace std;

char str_input[MAX_LIST];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i;
	char cmd;
	int register finger;
	int register stack_finger;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> str_input;
		finger = 0;
		stack_finger = 0;
		while ((cmd = str_input[finger++]) != '\0') {
			if (cmd == '(') {
				stack_finger++;
			}
			else {
				stack_finger--;
			}
			if (stack_finger < 0) {
				break;
			}
		}
		if (stack_finger != 0) {
			cout << "NO" << "\n";
		}
		else{
			cout << "YES" << "\n";
		}
	}
	
	return 0;
}