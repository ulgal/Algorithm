#include<iostream>
using namespace std;
int N;
int num[12] = {0};
int opr[4] = {0};
int cal[11] = {0};
int max_num, min_num;

int max(int, int);
int min(int, int);
void rec_cal(int ,int);
void rec_cal_call(int);
                  
    
        
    
    
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		opr[0] = opr[1] = opr[2] = opr[3] = 0;
        max_num = -100000001;
        min_num = 100000001;       
        cin >> N;
        for(int i = 0; i < 4; i++){
            cin >> opr[i];
        }
        for(int i = 0; i < N; i++){
            cin >> num[i];
        }
        rec_cal_call(0);
        cout << "#" << test_case << " " << max_num-min_num << endl;
    }
	return 0;
}

int max(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

void rec_cal_call(int n){
    if(opr[0]>0){
     	rec_cal(0, n);
    }
    if(opr[1]>0){
     	rec_cal(1, n);
    }
    if(opr[2]>0){
     	rec_cal(2, n);
    }
    if(opr[3]>0){
        rec_cal(3, n);
    }
}
void rec_cal(int a, int n){
    if(a == 0){
        opr[0]--;
        cal[n] = 0;
        rec_cal_call(n+1);
        opr[0]++;
    }
    else if( a==1 ){
        opr[1]--;
        cal[n] = 1;
        rec_cal_call(n+1);
        opr[1]++;
    }
    else if( a==2 ){
        opr[2]--;
        cal[n] = 2;
        rec_cal_call(n+1);
        opr[2]++;
    }
    else if( a==3 ){
        opr[3]--;
        cal[n] = 3;
        rec_cal_call(n+1);
        opr[3]++;
    }
    if(n==N-2){
        int ans = num[0];
        for(int i = 0; i < N-1; i++){
            if(cal[i]==0){
                ans += num[i+1];
            }
            else if(cal[i]==1){
                ans -= num[i+1];
            }
            else if(cal[i]==2){
                ans *= num[i+1];
            }
            else if(cal[i]==3){
                ans /= num[i+1];
            }
        }
        max_num = max(max_num, ans);
        min_num = min(min_num, ans);
    }
}