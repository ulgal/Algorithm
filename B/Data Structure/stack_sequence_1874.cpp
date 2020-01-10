#include<iostream>
#define MAX 100000

using namespace std;

int stack_input[MAX];
int stack_push[MAX];
int stack_pop[MAX];
char answer[2 * MAX];
char ans[4 * MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int register i;
	bool flag = true;
	int input_finger = -1;
	int push_finger = -1;
	int pop_finger = -1;
	int ans_finger = -1;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> stack_input[++input_finger];
	}
	stack_push[++push_finger] = stack_input[input_finger--];
	answer[++ans_finger] = '-';
	while (input_finger > -1) {
		if (stack_input[input_finger] > stack_push[push_finger]) {
			stack_push[++push_finger] = stack_input[input_finger--];
			answer[++ans_finger] = '-';
		}
		else {
			if (pop_finger < 0) {
				stack_pop[++pop_finger] = stack_push[push_finger--];
				answer[++ans_finger] = '+';
			}
			else if (stack_push[push_finger] < stack_pop[pop_finger]) {
				stack_pop[++pop_finger] = stack_push[push_finger--];
				answer[++ans_finger] = '+';
			}
			else {
				flag = false;
				break;
			}
		}
	}
	if (pop_finger == -1) {
		stack_pop[++pop_finger] = stack_push[push_finger--];
		answer[++ans_finger] = '+';
	}
	while (push_finger > -1) {
		if (stack_push[push_finger] < stack_pop[pop_finger]) {
			stack_pop[++pop_finger] = stack_push[push_finger--];
			answer[++ans_finger] = '+';
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag) {
		i = 0;
		while (ans_finger >= 0) {
			ans[i++] = answer[ans_finger--];
			ans[i++] = '\n';
		}
		ans[i++] = '\0';
		cout << ans << "\n";

	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}