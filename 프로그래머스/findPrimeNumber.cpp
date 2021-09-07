/****************************************
    
    Find PrimeNumber Permutation

    Input : Number string

    Output : Number of Prime Numbers

    Calculates number of Prime Numbers using DFS


    
    9/7 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;
vector<int> perm;
bool visited[8] = {0,};

bool isPrimeNumber(int n){
    if(n<2) return false;
    for(int i=2; i<n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void getPermutation(vector<int> numbers, int endpoint, int cnt){
    if(cnt == endpoint){
        int num = 0;
        for(int i=0; i < endpoint ; i++){
            num += v[i] * pow(10, endpoint - i - 1);
        }
        perm.push_back(num);
        return;
    }
    int before = -1;
    for(int i=0; i < numbers.size(); i++){
        if((cnt == 0 && numbers[i] == 0) || visited[i] || before == numbers[i])
            continue;
        visited[i] = true;
        v.push_back(numbers[i]);
        getPermutation(numbers, endpoint, cnt + 1);
        v.pop_back();
        visited[i] = false;
        before = numbers[i];
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<int> number;
    for(auto i:numbers){
        number.push_back(i-48);
    }
    sort(number.begin(), number.end());
    for(int i=0; i<number.size();i++){
        getPermutation(number, i + 1, 0);
    }

    for(auto num:perm){
        cout << num << endl;
        if(isPrimeNumber(num))
            answer++;
    }
    return answer;
}

int main(){
    string numbers;
    cin >> numbers;
    cout << solution(numbers);
}