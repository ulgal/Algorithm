#include<iostream>
using namespace std;
int N, M, K, A, B;
int curtime, time_n[9], time_m[9];
int waiting_list_n[1000], waiting_list_m[1000], ans_list[1000];
int recept[9], repair[9];
int person_cnt, wln_wait_cnt, wln_free_cnt, wlm_wait_cnt, wlm_free_cnt, ans_cnt, person_free_cnt;
struct customer{
    int arrtime;
    int recept_num;
    int recept_time;
    int repair_num;
    int repair_time;
};
customer person[1000];
void init(){
    int i;
    for(i = 0; i < 9; ++i){
        recept[i] = -1;
        repair[i] = -1;
    }
}
void show(){
    for(int i = 0; i < K; ++i){
        cout << i+1 << ": " << person[i].arrtime << ", " << person[i].recept_num + 1 << ", " << person[i].recept_time << ", " << person[i].repair_num + 1 << ", " << person[i].repair_time << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int T, test_case, i, ans;
    cin >> T;
    for(test_case = 1; test_case <=T; ++test_case){
        cin >> N >> M >> K >> A >> B;
        for(i = 0; i < N; ++i){
            cin >> time_n[i];
        }
        for(i = 0; i < M; ++i){
            cin >> time_m[i];
        }
        for(i = 0; i < K; ++i){
            cin >> person[i].arrtime;
        }
        curtime = person_cnt = wln_wait_cnt = wln_free_cnt = wlm_wait_cnt= wlm_free_cnt  = ans_cnt = person_free_cnt = 0;
        while(curtime<41001){
        	while((person_cnt < K) && curtime==person[person_cnt].arrtime){
            	waiting_list_n[wln_wait_cnt++] = person_cnt++;
            }
            for( i = 0; i < N; ++i){
                if(recept[i]!=-1 && person[recept[i]].recept_time == curtime){
                    waiting_list_m[wlm_wait_cnt++] = recept[i];
                    recept[i] = -1;
                }
            }
            for( i = 0; i < M; ++i){
                if(repair[i] != -1 && person[repair[i]].repair_time == curtime){
                    if(person[repair[i]].recept_num == A-1 && person[repair[i]].repair_num == B-1){
                        ans_list[ans_cnt++] = repair[i];
                    }
                    repair[i] = -1;
                    ++person_free_cnt;
                }
            }
            for(i = 0 ; i < N; ++i){
                if(recept[i] == -1 && wln_free_cnt<wln_wait_cnt){
                    person[waiting_list_n[wln_free_cnt]].recept_time = curtime + time_n[i];
                    person[waiting_list_n[wln_free_cnt]].recept_num = i;
                    recept[i] = waiting_list_n[wln_free_cnt++];
                }
            }
            for(i=0; i < M; ++i){
                if(repair[i] == -1 && wlm_free_cnt < wlm_wait_cnt){
                    person[waiting_list_m[wlm_free_cnt]].repair_time = curtime + time_m[i];
                    person[waiting_list_m[wlm_free_cnt]].repair_num = i;
                    repair[i] = waiting_list_m[wlm_free_cnt++];
                }
            }
            if(person_free_cnt == K){
                break;
            }

            ++curtime;
        }
        ans = 0;

        for(i = 0; i < ans_cnt; ++i){
            ans += ans_list[i] + 1;

        }
        if(ans == 0){
            ans = -1;
        }        
        cout << "#" << test_case << " " << ans << endl;
    }
}