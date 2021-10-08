#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        unordered_map<int, int> hashmap;
        vector<int> nlist;
        cin >> n;
        while(n--){
            int temp;
            cin >> temp;
            hashmap[temp] += 1;
        }
        unordered_map<int, int>::iterator it;
        for(it = hashmap.begin(); it!=hashmap.end(); it++){
            if(it->second == 1)
                cout << it->first << endl;
        }
    }
}