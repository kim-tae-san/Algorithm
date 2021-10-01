#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pn; // playernumber
int parent[100001] = {0,};
int rnk[100001];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int find(int n){
    if(n == parent[n])
        return n;
    return find(parent[n]);
}

void unionn(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b){
        parent[b] = a;
        rnk[a] += rnk[b];
    }
    else if(a > b){
        parent[a] = b;
        rnk[b] += rnk[a];
    }
}

int solution(){
    int ret = 0;
    sort(pn.begin(), pn.end());
    for(int i=1; i<100001; i++){
        rnk[i] = 1;
        parent[i] = 0;
    }
    for(int i=0;i<pn.size(); i++){
        parent[pn[i]] = pn[i];
    }
    for(int i=1; i<100001; i++){
        if(parent[i] == 0)  continue;
        for(int j=i+1; j<100001; j++){
            if(parent[j] == 0)  continue;
            if(gcd(i, j) > 0){
                unionn(i, j);
            }
        }
    }
    cout << endl;
    for(auto i:pn){
        cout << parent[i] << " ";
    }
    for(int i=1; i<100001; i++)
        if(ret < rnk[i])
            ret = rnk[i];
    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        pn = vector<int>();
        int n;
        cin >> n;
        while(n--){
            int num;
            cin >> num;
            pn.push_back(num);
        }
        cout << solution() << endl;
    }
}