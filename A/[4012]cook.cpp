#include<iostream>
using namespace std;
int N;
int num[16][16] = {0};
int arr1[8] = {0};
int arr2[8] = {0};
int arr_cnt, min_dif;

int abs(int a){
    if(a<0)
        return -1*a;
    else
        return a;
}
int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

void fill_dif(){
    int ans1 = 0, ans2 = 0, arr1_cnt = 0, arr2_cnt = 0, finger = 0;
    while(finger<N){
        if(finger !=arr1[arr1_cnt])
            arr2[arr2_cnt++] = finger;
        else
            arr1_cnt++;
        finger++;
    }
    for(int i = 0; i < arr_cnt; i++)
        for(int j = i+1; j < arr_cnt; j++){
            ans1 += num[arr1[i]][arr1[j]] + num[arr1[j]][arr1[i]];
            ans2 += num[arr2[i]][arr2[j]] + num[arr2[j]][arr2[i]];
        }
    min_dif = min(min_dif, abs(ans1 - ans2));
}        
void pick(int k){
    if(arr_cnt == N/2){
        fill_dif();
    }
    else{
        for(int i = k; i < N; i++){
            arr1[arr_cnt++] = i;
            pick(i+1);
            arr_cnt--;
        }
    }
}
          

void init_dif(){
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < N/2; i++)
        for(int j = i+1; j < N/2; j++)
            ans1 += num[i][j] + num[j][i];
    for(int i = N/2; i < N; i++)
        for(int j = i+1; j < N; j++)
            ans2 += num[i][j] + num[j][i];
    min_dif = abs(ans1 - ans2);
}    
    
    
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        arr_cnt = 0;
        cin >> N;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                cin>> num[i][j];
            }
        init_dif();
        arr1[arr_cnt++] = 0;
        pick(1);
        cout << "#" << test_case << " " << min_dif << endl;
    }
	return 0;
}

