/****************************************
    
    제 7회 한국기술교육대 프로그래밍 대회 D번 문제

    Input : int n

    Output : Tribonacci Num

    Calculates Tribonacci Num using Matrix Power Method


    
    9/19 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long> > base = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};

vector<vector<long long> > multifly(vector<vector<long long> > a, vector<vector<long long> > b){
    vector<vector<long long> > ret;
    for(int i=0; i<3; i++){
        vector<long long> vec;
        for(int j=0; j<3; j++){
            long long elem = 0;
            for(int k=0; k<3 ;k++){
                elem += a[i][k] * b[k][j];
            }
            elem %= 1000000007;
            vec.push_back(elem);
        }
        ret.push_back(vec);
    }
    return ret;
}

vector<vector<long long> > power(int n){
    vector<vector<long long> > ans = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<long long> > matrix = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    while(n > 0){
        if(n%2 == 1){
            ans = multifly(ans, matrix);
        }
        matrix = multifly(matrix, matrix);
        n /= 2;
    }
    return ans;
}

int solution(int n){
    if(n < 4)
        return n;
    n -= 3;
    vector<vector<long long> > matrix = power(n);
    return (3 * matrix[0][0] + 2 * matrix[0][1] + matrix[0][2]) % 1000000007;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        cout << solution(n) << endl;
    }
}