#include<iostream>
using namespace std;
int K;
int magnet[4][8] = {0}; // 자석정보
int input[20][2] = {0}; //자석번호, 방향
int rot_info[4] = {0};

void init(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++)
            magnet[i][j] = 0;
       	rot_info[i] = 0;
    }
    for(int i = 0; i < 20; i ++)
        for(int j = 0; j < 2; j++)
            input[i][j] = 0;
}
void clockwise(int a){
    int temp = magnet[a][7];
    for(int i = 7; i >0; i--){
        magnet[a][i] = magnet[a][i-1];
    }
    magnet[a][0] = temp;
}
void counterClockwise(int a){
    int temp = magnet[a][0];
    for(int i = 0; i < 7; i++){
        magnet[a][i] = magnet[a][i+1];
    }
    magnet[a][7] = temp;
}

void rotate(){
    for(int i = 0; i < K; i++){
        int target = input[i][0]-1;
        rot_info[target] = input[i][1];
        for(int target1 = target; target1 < 3; target1++){
            if(magnet[target1][2] != magnet[target1+1][6])
                rot_info[target1+1] = rot_info[target1] * -1;
            else
                rot_info[target1+1] = 0;
        }
        for(int target2 = target; target2>0; target2--){
             if(magnet[target2-1][2] != magnet[target2][6])
                rot_info[target2-1] = rot_info[target2] * -1;
            else
                rot_info[target2-1] = 0;
        }

        for(int j = 0; j < 4; j++){
            if(rot_info[j]==1)
                clockwise(j);
            else if(rot_info[j]==-1)
                counterClockwise(j);
        }

    }
}
int sum(){
    return magnet[0][0] + 2*magnet[1][0] + 4*magnet[2][0] + 8*magnet[3][0];
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> K;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 8; j++)
                cin >> magnet[i][j];
        for(int i = 0; i < K; i++)
            cin >> input[i][0] >> input[i][1];

        rotate();
        cout << "#" << test_case << " " << sum() << endl;
    }
	return 0;
}

