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
bool areAligned(vector<int>& direction){
    bool ok = true;
    for(int i=0; i< CLOCKS; i++){
        if(direction[i] != 12){
            ok = false;
            break;
        }
    }
    return ok;
}
void move(vector <int> &direction, int swtch){
    for(int clock = 0; clock < CLOCKS; clock++){
        if(connected[swtch][clock] == 'x'){
            direction[clock] += 3;
            if(direction[clock] == 15) direction[clock] = 3;
        }
    }
}
int click(vector <int> &direction, int swtch){
    if(swtch == SWITCHES) return areAligned(direction)?0:INF;
    int ret = INF;
    for(int i=0; i<4; i++){
        ret = min(ret, i + click(direction, swtch + 1));
        move(direction, swtch);
    }
    return ret;
}
int main(){
    int C;
    cin >> C;
    for(int i=0; i< C; i++){
        vector <int> direction;
        for(int j=0; j<CLOCKS; j++){
            int temp;
            cin >> temp;
            direction.push_back(temp);
        }
        int result = click(direction, 0);
        if(result >= INF) cout << -1 << endl;
        else cout << result << endl;
    }
}