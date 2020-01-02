#include<iostream>
using namespace std;
int arr[20][20] = {0};
int line[40][20][2] = {0}; // num,length
int N, X;

void initLine(){
    int i, j, k;
    for( i = 0; i < 40; ++i)
        for( j = 0; j < 6; ++j)
            for( k = 0; k < 2; ++k)
                line[i][j][k] = 0;
}
void makeLine(){
    int i, j, line_cnt_1 = 0, line_cnt_2, num, length;
    for(i = 0; i < N; ++i){
        int num = arr[i][0];
        length = 1;
        line_cnt_2 = 0;
        for(j = 1; j < N; ++j){
        	if(arr[i][j] != num){
                line[line_cnt_1][line_cnt_2][0] = num;
                line[line_cnt_1][line_cnt_2++][1] = length;
                num = arr[i][j];
                length = 1;
            }
            else
                length++;
        }
        line[line_cnt_1][line_cnt_2][0] = num;
        line[line_cnt_1++][line_cnt_2++][1] = length;
        num = arr[0][i];
        line_cnt_2 = 0;
        length = 1;
        for(j = 1; j < N; ++j){
        	if(arr[j][i] != num){
                line[line_cnt_1][line_cnt_2][0] = num;
                line[line_cnt_1][line_cnt_2++][1] = length;
                num = arr[j][i];
                length = 1;
            }
            else
                length++;
        }
        line[line_cnt_1][line_cnt_2][0] = num;
        line[line_cnt_1++][line_cnt_2++][1] = length;
    }
}        
int ans(){
	int idx, i, j, ans = 0, bound = 2*N;
    for(idx = 0; idx < bound; ++idx){
        bool is_true = true;
        for(i = 0; i < 20; i++){
            if(line[idx][i][0] == 0 || line[idx][i+1][0] == 0){
                break;
            }
            else if(line[idx][i][0] - line[idx][i+1][0] == 1){
                if(line[idx][i+1][1]<X)
                    is_true = false;
            }
            else if(line[idx][i][0] - line[idx][i+1][0] == -1){
                if(line[idx][i][1] < X )
                    is_true = false;
                else if( (i - 1) >= 0 && (line[idx][i - 1][0] - line[idx][i][0] == 1 ) ){
                    if(line[idx][i][1] < 2*X)
                    	is_true = false;
                }
            }
            else{
                is_true = false;
            }
        }
        if(is_true)
            ans++;   
    }
    return ans;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        initLine();
        cin >> N >> X;
        int i, j;
        for( i = 0; i < N; ++i)
            for( j = 0 ; j < N ; ++j)
                cin >> arr[i][j];
        makeLine();
        cout << "#" << test_case << " " << ans() << endl;
	}
	return 0;
}