#include<iostream>
using namespace std;
int pwd[28];
void swap(int a, int b){
    int temp = pwd[a];
    pwd[a] = pwd[b];
    pwd[b] = temp;
}
void arrsort(int first, int last){
    int length = last - first + 1;
    if(length>1){
        swap(first + length/2, last);
        int finger1 = first;
        for(int finger2 = first; finger2 < last; finger2++){
            if(pwd[finger2] > pwd[last]){
                swap(finger2, finger1);
                finger1++;
            }
        }
        swap(finger1, last);
        arrsort(first, finger1-1);
        arrsort(finger1+1, last);
    }
}

void dup_remove(int size){
    for(int i = 0; i < size-1; i++){
        if((pwd[i]==pwd[i+1])&&(pwd[i]!=-1)){
            int temp = pwd[i], idx = i + 1;
            while(temp == pwd[idx]){
                pwd[idx]=-1;
                idx++;
            }
        }
    }
    for(int i = 0; i < size-1; i++){
        if(pwd[i]==-1){
            int j = i;
            while(pwd[j]==-1){
                j++;
            }
            int dif = j - i;
            for(int k = i; k < size-dif; k++){
                swap(k, k + dif);
            }
        }
    }       
}
int hex_to_dec(char c){
    if(c == 'F')
        return 15;
    else if(c == 'E')
        return 14;
    else if(c== 'D')
        return 13;
    else if(c=='C')
        return 12;
    else if(c=='B')
        return 11;
    else if(c=='A')
        return 10;
    else
        return c - '0';
} 
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, k;
        string input;
        cin >> n >> k;
        cin >> input;
        int line_length = n / 4;
        for(int i = 0; i < line_length-1; i++){
            input += input[i];
        }
        for(int i = 0; i < n; i++){
            int num = 0;
            for(int j = i; j < i+line_length; j++){
                num *= 16;
                num += hex_to_dec(input[j]);
            }
            pwd[i] = num;
        }
        arrsort(0, n);
        dup_remove(n);
        cout << "#" << test_case << " " << pwd[k-1] << endl;     
	}
	return 0;
}