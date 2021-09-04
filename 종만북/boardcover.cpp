#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1 ,1}},
    {{0, 0}, {1, 0}, {1, -1}}
};
bool set(vector<vector<int> >&board, int x, int y, int type, int delta){
    bool ok = true;
    for(int i=0; i<3; i++){
        int dx, dy;
        dx = x + coverType[type][i][1];
        dy = y + coverType[type][i][0];
        if(dx >= 0 && dy >= 0 && dx < board[0].size() && dy < board.size())
        {
            board[dy][dx] += delta;
            if(board[dy][dx] > 1){
                ok = false;
            }
        }
        else{
            ok = false;
        }
    }
    return ok;
}
int cover(vector<vector<int> >&board){
    int y = -1;
    int x = -1;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size();j++){
            if(board[i][j]==0){
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }
    if(y == -1)
        return 1;
    int ret = 0;
    for(int type=0; type< 4; type++){
        if(set(board, x, y, type, 1)){
            ret += cover(board);
        }
        set(board, x, y, type, -1);
    }
    return ret;
}
int main(){
    int c, h, w;
    cin >> c;
    for(int i=0; i<c; i++){
        cin >> h >> w;
        vector<vector<int> > board;
        int cnt=0;
        int answer=0;
        for(int j=0; j<h; j++){
            vector<int> temp;
            string line;
            cin >> line;
            for(int k=0; k<w; k++){
                if(line[k] == '#')
                {
                    temp.push_back(1);
                }
                else{
                    temp.push_back(0);
                    cnt++;
                }
            }
            board.push_back(temp);
        }
        if(cnt%3 != 0){
            cout << answer;
            continue;
        }
        answer = cover(board);
        cout << answer << endl;
    }
    return 0;
}