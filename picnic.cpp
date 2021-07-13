#include <iostream>
#include <string>
using namespace std;
int c, n, m;
bool areFriends[10][10] = {0,};
bool visited[10] = {0,};
int dfs(){
    int firstFree = -1;
    for(int i=0; i<n; i++){
        if(!visited[i])
        {
            firstFree = i;
            break;
        }            
    }
    if(firstFree == -1)
        return 1;
    int ret = 0;
    for(int i=firstFree+1; i<n; i++){
        if(!visited[i] && areFriends[firstFree][i]){
            visited[i] = visited[firstFree] = true;
            ret += dfs();
            visited[i] = visited[firstFree] = false;
        }
    }
    return ret;
}
int main(){
    cin >> c;
    for(int i=0; i<c;i++){
        for(int n=0; n<10; n++)
        {
            visited[n] = false;
            for(int m=0; m<10; m++){
                areFriends[n][m] = false;
            }
        }
        cin >> n >> m;
        for(int j=0; j< m; j++)
        {
            int f1, f2;
            cin >> f1 >> f2;
            areFriends[f1][f2] = true;
            areFriends[f2][f1] = true;
        }
        int result = dfs();
        cout << result << endl;
    }
}