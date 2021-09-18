/****************************************
    
    제 7회 한국기술교육대 프로그래밍 대회 C번 문제

    Input : Adjency list of states, Start Point

    Output : Longest distance among Shortest distance

    Find Longest Distance in Shortest distances using Dijkstra Algorithm


    
    9/18 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int p,q,r;
vector<vector<pair<int, int> > > peaks;
vector<int> mv;
vector<int> shortest_dist;
void dijkstra(){
    priority_queue<pair<int, int> > pq;
    shortest_dist.resize(p + 1, INT_MAX);
    for(int i=1; i<=p; i++){
        shortest_dist[i] = INT_MAX;
    }
    for(auto v:mv){
        pq.push(make_pair(0, v));
    }
    while(!pq.empty()){
        int dist = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(dist > shortest_dist[current])
            continue;
        shortest_dist[current] = dist;
        for(auto dest: peaks[current]){
            int nextdist = dist + dest.second;
            int next = dest.first;
            if(nextdist < shortest_dist[next]){
                shortest_dist[next] = nextdist;
                pq.push(make_pair(-nextdist, next));
            }
        }
    }
}
int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> p >> q >> r;
        peaks.resize(p+1);
        mv.clear();
        for(int i=1; i<=p; i++){
            peaks[i].clear();
        }
        while(q--){
            int a, b, c;
            cin >> a >> b >> c;
            peaks[b].push_back(make_pair(a, c));
        }
        while(r--){
            int d;
            cin >> d;
            mv.push_back(d);
        }
        dijkstra();
        int ret = 0;
        int loc = 0;
        for(int i=1; i<=p; i++){
            if(shortest_dist[i] > ret){
                ret = shortest_dist[i];
                loc = i;
            }
        }
        cout << loc << " " << ret << endl;
    }
}