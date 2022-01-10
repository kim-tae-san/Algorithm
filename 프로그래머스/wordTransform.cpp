
/****************************************
    
    Programmers Lv.3 단어 변환

    Input : pair<pair<int, string>, int> 

    Output : min num of word transform processes

    Using Queue BFS

    
    2022/1/10 coded by bmkim
    
******************************************/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>    

using namespace std;

int solution(string begin, string target, vector<string> words) {
    // 나중에 완전탐색에서 min계산을 하기위해 큰 값으로 초기화
    int answer = 1000;
    // 단어를 방문했는지 구분하기 위함
    bool visited[50] = {0,};
    // ((단어, 이동횟수), 배열의 인덱스) 로 이루어진 데이터 구조  
    queue<pair<pair<string, int>, int> > q;
    q.push(make_pair(make_pair(begin, 0), -1));
    while(!q.empty()){
        pair<pair<string, int>, int> process = q.front();
        string word = process.first.first;
        int n = process.first.second;
        q.pop();
        if(word == target){
            answer = min(answer, n);
            break;
        }
        // 첫번째 시도가 아닐경우 해당 단어의 배열 인덱스를 바탕으로 방문기록을 남김
        if(process.second != -1)
            visited[process.second] = true;
        for(int i=0; i<words.size();i++){
            if(visited[i]) continue;
            int cnt = 0;
            for(int j=0; j<words[0].size(); j++){
                if(word[j] != words[i][j])
                    cnt++;
            }
            if(cnt == 1)
            {
                q.push(make_pair(make_pair(words[i], process.first.second + 1), i));
            }
        }
    }
    if(answer == 1000)
        return 0;
    return answer;
}