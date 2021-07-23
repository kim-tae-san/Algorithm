#include <iostream>

using namespace std;

 bool grid[100][100] = {false};
 int vx[] = {1, -1, 0, 0};
 int vy[] = {0, 0, 1, -1};
 double prod[4];

 class Crazyboy{
     public:
     double getProbability(int n, int east, int west, int south, int north){
         prod[0] = east / 100.0;
         prod[1] = west / 100.0;
         prod[2] = south / 100.0;
         prod[3] = north / 100.0;
         return dfs(50, 50, n);
     }
     double dfs(int x, int y, int n){
         if(n == 0){
             return 1;
         }
         if(grid[x][y]){
             return 0;
         }

         grid[x][y] = true;

         double ret = 0;
         
         for(int i=0;i<4;i++){
            ret += dfs(x + vx[i], y + vy[i], n-1) * prod[i];
         }
         grid[x][y] = false;
         return ret;
     }
 };
 int main(){
     Crazyboy cb;
     cout << cb.getProbability(14, 25, 25, 25, 25);
 }