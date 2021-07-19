#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int CLOCKS = 16;
const int SWITCHES = 10;
const int INF = 9999;
char connected[SWITCHES][CLOCKS+1] = {
    "xxx.............", 
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};
void move(vector <int> &direction, int place){
    
}
int click(vector <int> &direction, int cnt){
    bool ok = true;
    for(int i=0; i<CLOCKS; i++){
        if(direction[i] != 12){
            ok = false;
            break;
        }
    }
    if(ok){
        return cnt;
    }
    int ret = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<SWITCHES; j++){
            
        }
    }
}
int main(){
    int C;
    vector <int> direction;
    cin >> C;
    for(int i=0; i< C; i++){
        for(int j=0; j<CLOCKS; j++){
            int temp;
            cin >> temp;
            direction.push_back(temp);
        }
    }
}