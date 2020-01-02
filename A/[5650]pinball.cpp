#include<iostream>
using namespace std;

int table[102][102];
int line_length;

int path(int a, int b, int c){ // c={0:상, 1:하, 2:좌, 3:우}
    int init_a = a, init_b = b, score = 0;
    while(1){
        if(table[a][b]==1){
            score++;
            if(c==0){//to 상 - from 하
                c = 1;
            }
            else if(c==1){//to 하 - from 상
                c = 3;
            }
            else if(c==2){//to 좌 - from 우
                c = 0;
            }
            else if(c==3){//to 우 - from 좌
                c = 2;
            }
        }
        else if(table[a][b]==2){
            score++;
            if(c==0){//to 상 - from 하
                c = 3;
            }
            else if(c==1){//to 하 - from 상
                c = 0;
            }
            else if(c==2){//to 좌 - from 우
                c = 1;
            }
            else if(c==3){//to 우 - from 좌
                c = 2;
            }
        }
        else if(table[a][b]==3){
            score++;
            if(c==0){//to 상 - from 하
                c = 2;
            }
            else if(c==1){//to 하 - from 상
                c = 0;
            }
            else if(c==2){//to 좌 - from 우
                c = 3;
            }
            else if(c==3){//to 우 - from 좌
                c = 1;
            }
        }
        else if(table[a][b]==4){
            score++;
            if(c==0){//to 상 - from 하
                c = 1;
            }
            else if(c==1){//to 하 - from 상
                c = 2;
            }
            else if(c==2){//to 좌 - from 우
                c = 3;
            }
            else if(c==3){//to 우 - from 좌
                c = 0;
            }
        }
        else if(table[a][b]==5){
            score++;
            if(c==0){//to 상 - from 하
                c = 1;
            }
            else if(c==1){//to 하 - from 상
                c = 0;
            }
            else if(c==2){//to 좌 - from 우
                c = 3;
            }
            else if(c==3){//to 우 - from 좌
                c = 2;
            }
        }
        else if(table[a][b]>=6 && table[a][b]<=10){
            int brk_cnt=0;
            for(int i = 1; i < line_length - 1; i++){
                for(int j = 1; j < line_length - 1; j++){
                    if(((i!=a)||(j!=b))&&(table[i][j]==table[a][b])){
                        brk_cnt++;
                        a = i;
                        b = j;
                        break;
                    }
                }
                if(brk_cnt==1){
                    break;
                }
            }
        }
        if(c==0){
            a--;
        }
        else if(c==1){
            a++;
        }
        else if(c==2){
            b--;
        }
        else if(c==3){
            b++;
        }
        //종료조건
        if(table[a][b]==-1){
            break;
        }
        if((a==init_a)&&(b==init_b)){
            break;
        }
    }
    return score;
}
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> line_length;
        line_length += 2;
        for(int i = 1; i < line_length-1 ; i++){
            for(int j = 1; j < line_length-1 ; j++){
                cin >> table[i][j];
            }
        }
        for(int i = 1; i < line_length-1; i++){
            table[0][i] = 5;
            table[i][0] = 5;
            table[line_length-1][i] = 5;
            table[i][line_length-1] = 5;
        }
        int max_num = 0;
        for(int init_i = 1; init_i < line_length-1; init_i++){
            for(int init_j = 1; init_j < line_length-1; init_j++){
                if(table[init_i][init_j]==0){                    
                    max_num = max(max_num, max(max(path(init_i, init_j, 0), path(init_i, init_j, 1)), max(path(init_i, init_j, 2), path(init_i, init_j, 3))));
                }
            }
        }
        cout << "#" << test_case << " " << max_num << endl;
	}
	return 0;
}