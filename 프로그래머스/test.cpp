/****************************************
    
    Brute Force

    Input : Answer String

    Output : Most collected student

    Find the best student using brute force


    
    9/7 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ansNum[3] = {0,};
    vector<vector<int> > pattern =
    {{1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5 ,5}
    };
    int index[3] = {0,};
    for(auto i:answers){
        for(int j=0; j<3; j++){
            if(index[j] == pattern[j].size())
                index[j] = 0;
            if(pattern[j][index[j]] == i)
                ansNum[j]++;
            index[j]++;
        }
    }
    int max = -1;
    for(int i=0; i<3; i++)
    {
        if(max < ansNum[i]){
            max = ansNum[i];
        }
    }
    for(int i=0; i<3; i++)
    {
        if(ansNum[i] == max)
            answer.push_back(i+1);
    }
    return answer;
}

int main(){
    vector<int> answers;
    int n;
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        answers.push_back(temp);
    }
    vector<int> ans = solution(answers);
    for(auto i:ans)
        cout << i;
}