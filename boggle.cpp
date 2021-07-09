#include <iostream>
#include <string>
using namespace std;
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
string board[5] = {"NNNNS", "NEEEN", "NEYEN", "NEEEN", "NNNNN"};
bool inrange(int x, int y){
    return x > 0 || x < 5 || y > 0 || y < 5;
}
bool hasWord(int y, int x, string word){
    // 기저 조건1 : 범위 벗어날 경우 false
    if(!inrange(x, y)) return false;
    // 기저 조건2 : 첫글자 일치하지 않을경우 false
    if(board[y][x] != word[0]) return false;
    // 기저 조건3 : 단어 길이가 1일 경우 true
    if(word.size() == 1) return true;
    for(int direction = 0; direction < 8; direction++){
        int nextY = dy[direction] + y;
        int nextX = dx[direction] + x;
        if(hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}
int main(){
    cout << hasWord(2, 2, "YES");
}