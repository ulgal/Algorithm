#include<iostream>
using namespace std;
int honey[100] = {0};
int possible[100] = {0};
int range[2] = {0};
int N, M, C, bound, ans;
int bucket[5];
bool occupied[100] = {false};
int cnt = 1;

void initPossible(){
    int i;
    for(i = 0; i < 100; ++i){
        possible[i] = 0;
    }
}
int calculate(int n, int sum){
	int i, j, cal = 0, temp_cal = 0;
    if(n>=M){
        for(i = 0; i < n; ++i){
        	cal += bucket[i] * bucket[i];
        }
        return cal;
    }
    for(i = range[0]; i < range[1]; ++i){
        if(!occupied[i]){
            if((sum+honey[i])<=C){
                occupied[i] = true;
                bucket[n] = honey[i];
                temp_cal = calculate(n+1, sum+bucket[n]);
                cal = (cal>temp_cal) ? (cal) : (temp_cal);
                occupied[i] = false;
            }
        }
        else{
            temp_cal = 0;
            for(j = 0; j < n; ++j){
				temp_cal += bucket[j] * bucket[j];
			}
			cal = (cal>temp_cal) ? (cal) : (temp_cal);
		}
    }
    return cal;
}
void digBruteForce(){
    int i, j, k, ans_i, ans_j;
    for(i = 0; i < bound-M+1; ++i){
        if((i+M-1)/N>(i/N)){
            i = ((i+M-1)/N)*N - 1;
            continue;
        }
        range[0] = i;
        range[1] = i+M;
        possible[i] = calculate(0, 0);
    }
}

void findMax(){
    int i, j;
    for(i = 0; i < bound-2*M+1; ++i){
        if( (i+M-1)/N>(i/N) ) {
            continue;
        }
        for(j = i+M; j < bound-M+1; ++j){
            if( (j+M-1)/N>(j/N) ){
                continue;
            }
            //cout << i/N << ", " << i%N << " /  " << j/N  << ", " << j%N << " // "  << possible[i] << " " << possible[j] << " " << possible[i]+possible[j] << endl;
            ans = (ans > possible[i] + possible[j]) ? ans : possible[i] + possible[j];
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, i, j, test_case;
    cin >> T;
    for(test_case = 1; test_case<=T; ++test_case){
        cin >> N >> M >> C;
        bound = N * N;
        ans = 0;
        initPossible();
        for(i = 0; i < bound; ++i){
			cin >> honey[i];
        }
        digBruteForce();
        findMax();
        cout << "#" << test_case << " " << ans << endl;
    }
}
