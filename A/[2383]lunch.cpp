#include<iostream>
using namespace std;
int st1[10];
int st2[10];
int ans;
int abs(int a){
    return (a>0) ? a : a*-1;
}
struct wait_p{
    int x;
    int y;
    int st1;
    int st2;
   	bool cur;
};
wait_p person[10];
struct stair{
    int x;
    int y;
    int length;
    int p1;
    int p2;
    int p3;
};
stair st[2];
void st1Sort(int start, int end){
    int length = end - start+1;
    if(length <= 1){
        return;
    }

    int p = start+length/2;
    int temp = st1[p];
    st1[p] = st1[end];
    st1[end] = temp;
    int finger1 = start;

    for(int finger2 = start; finger2 < end; ++finger2){
        if(person[st1[finger2]].st1 < person[st1[end]].st1){
            temp = st1[finger2];
            st1[finger2] = st1[finger1];
            st1[finger1++] = temp;
        }
    }
    temp = st1[finger1];
    st1[finger1] = st1[end];
    st1[end] = temp;
        
    st1Sort(start, finger1-1);
    st1Sort(finger1+1, end);
}

void st2Sort(int start, int end){

    int length = end - start+1;
    if(length <= 1){
        return;
    }
    int p = start+length/2;
    int temp = st2[p];
    st2[p] = st2[end];
    st2[end] =temp;
    int finger1 = start;
    for(int finger2 = start; finger2 < end; ++finger2){
        if(person[st2[finger2]].st2 < person[st2[end]].st2){
            temp = st2[finger2];
            st2[finger2] = st2[finger1];
            st2[finger1++] = temp;
        }
    }
    temp = st2[finger1];
    st2[finger1] = st2[end];
    st2[end] = temp;

    st2Sort(start, finger1-1);
    st2Sort(finger1+1, end);
}
void calculate(int n){
	int st1_cnt = 0, st2_cnt = 0, i;
    for(i = 0; i < n; ++i){
        if(person[i].cur){
            st1[st1_cnt++] = i;
        }
        else{
            st2[st2_cnt++] = i;
        }
    }

    st1Sort(0, st1_cnt-1);
    st2Sort(0, st2_cnt-1);

    int passing_person = 0, time = person[st1[0]].st1, max1 = 0, max2 = 0, max;
    st[0].p1 = st[0].p2 = st[0].p3 = 0;
    while(passing_person<st1_cnt){
        if(st[0].p1  <= time){
            st[0].p1 = 0;
        }
        if(st[0].p2 <= time){
            st[0].p2 = 0;
        }
        if(st[0].p3 <= time){
            st[0].p3 = 0;
        }
        if(st[0].p1 == 0 && time>=person[st1[passing_person]].st1){
            st[0].p1 = time + st[0].length;
            passing_person++;
        }
        if(st[0].p2 == 0 && time>=person[st1[passing_person]].st1){
            st[0].p2 = time + st[0].length;
            passing_person++;
        }
        if(st[0].p3 == 0 && time>=person[st1[passing_person]].st1){
            st[0].p3 = time + st[0].length;
            passing_person++;
        }
        time++;
    }
    max1 = ((st[0].p1 > st[0].p2) ? st[0].p1 : st[0].p2);
    max1 = (max1 > st[0].p3) ? max1 : st[0].p3;
    passing_person = 0, time = person[st2[0]].st2;
    st[1].p1 = st[1].p2 = st[1].p3 = 0;
    while(passing_person<st2_cnt){
        if(st[1].p1 <= time){
            st[1].p1 = 0;
        }
        if(st[1].p2 <= time){
            st[1].p2 = 0;
        }
        if(st[1].p3 <= time){
            st[1].p3 = 0;
        }
        if(st[1].p1 == 0 && time>=person[st2[passing_person]].st2){
            st[1].p1 = time + st[1].length;
            passing_person++;
            
        }
        if(st[1].p2 == 0 && time>=person[st2[passing_person]].st2){
            st[1].p2 = time + st[1].length;
            passing_person++;
        }
        if(st[1].p3 == 0 && time>=person[st2[passing_person]].st2){
            st[1].p3 = time + st[1].length;
            passing_person++;

        }
        time++;
        
    }
    
    
    max2 = ((st[1].p1 > st[1].p2) ? st[1].p1 : st[1].p2);
    max2 = (max2 > st[1].p3) ? max2 : st[1].p3;
    max = (max1> max2) ? max1 : max2;
    ans = (ans > max) ? max : ans;
}


void dfs(int a, int n){
    if(a>=n){
        calculate(n);
    	return;
    }
    person[a].cur = true;
    dfs(a+1, n);
    person[a].cur = false;
    dfs(a+1, n);
}

int main(){
    int T, test_case, i, j, temp, N, stair_cnt, person_cnt;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        stair_cnt = person_cnt = 0;
        ans = 100000000;
        for(i = 0;  i < N; ++i){
            for(j = 0; j < N; ++j){
                cin >> temp;
                switch(temp){
                    case 1:
                        person[person_cnt++] = {j, i, 0, 0, true};
                    case 0:
                        break;
                    default:
                        st[stair_cnt++] = {j, i, temp, 0, 0, 0};
                }
            }
        }
        for(i = 0; i < person_cnt; i++){
            person[i].st1 = abs(person[i].x - st[0].x) + abs(person[i].y - st[0].y) + 1;
            person[i].st2 = abs(person[i].x - st[1].x) + abs(person[i].y - st[1].y) + 1;
        }
        dfs(0, person_cnt);
        cout << "#" << test_case << " " << ans << endl;
    }
}