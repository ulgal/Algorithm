#include<iostream>
using namespace std;
int dessert[20][20] = {0};
int occupied_list[101] = {0};
int N, ans;
int dessertSum(){
    int i, cnt = 0;
    for(i = 0; i < 101; ++i){
        if(occupied_list[i] !=0){
            cnt ++;
        }        
    }
    return cnt;
}
void route(int y, int x, int bound_1, int bound_2, int dir, int cnt){
    switch(dir){
        case 1:
            if(cnt>0){
            	if(occupied_list[dessert[y+1][x-1]] == 0){
                    occupied_list[dessert[y+1][x-1]] = 1;
                    route(y+1, x-1, bound_1, bound_2, dir, --cnt);
                    occupied_list[dessert[y+1][x-1]] = 0;
                }
                else{
                    return;
                }
            }
            else{ // 여기 중복있음
                cnt = bound_2;
                route(y, x, bound_1, bound_2, ++dir, cnt); 
            }
            break;
        case 2:
            if(cnt>0){
            	if(occupied_list[dessert[y+1][x+1]] == 0){
                    occupied_list[dessert[y+1][x+1]] = 1;
                    route(y+1, x+1, bound_1, bound_2, dir, --cnt);
                    occupied_list[dessert[y+1][x+1]] = 0;
                }
                else{
                    return;
                }
            }
            else{
                cnt = bound_1;
                route(y, x, bound_1, bound_2, ++dir, cnt);
            }
            break;
        case 3:
            if(cnt>0){
            	if(occupied_list[dessert[y-1][x+1]] == 0){
                    occupied_list[dessert[y-1][x+1]] = 1;
                    route(y-1, x+1, bound_1, bound_2, dir, --cnt);
                    occupied_list[dessert[y-1][x+1]] = 0;
                }
                else{
                    return;
                }
            }
            else{
                cnt = bound_2;
                route(y, x, bound_1, bound_2, ++dir, cnt);
            }
            break;
        case 4:
            if(cnt>0){
            	if(occupied_list[dessert[y-1][x-1]] == 0){
                    occupied_list[dessert[y-1][x-1]] = 1;
                    route(y-1, x-1, bound_1, bound_2, dir, --cnt);
                    occupied_list[dessert[y-1][x-1]] = 0;
                }
                else{
                    return;
                }
            }
            else{
                int temp_ans = dessertSum();
                ans = (ans>temp_ans) ? ans : temp_ans;
                return;
            }
            break;
            
    }
    
}
void find(){
    int i, j, k, l;
    for(i = 0; i < N; ++i){
        for(j = 0; j < N; ++j){
        	for(k = 1; k < N; ++k){
            	for(l = 1; l < N; ++l){
                	if((j-k>=0) && (j+l< N) && (i+k + l < N)){
                        route(i, j, k, l, 1, k);
                    }
                }
            }
        }
    }
}
int main(){
    int T, test_case, i, j;
    cin >> T;
    for(test_case = 1; test_case <=T ; ++test_case){
        cin >> N;
        for( i = 0; i < N; ++i){
            for(j = 0; j < N; ++j){
                cin >> dessert[i][j];
            }
        }
        ans = -1;
        find();
        cout << "#" << test_case << " " << ans << endl;
    }
}
        
