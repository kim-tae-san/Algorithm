#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class MazeMaker{
    public:
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol){
        int width = maze[0].size();
        int height = maze.size();
        int ret = 0;
        int board[50][50];
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                board[i][j] = -1;
            }
        }
        board[startRow][startCol] = 0;
        queue<int> QueueX;
        queue<int> QueueY;
        QueueX.push(startCol);
        QueueY.push(startRow);
        while(!QueueX.empty()){
            int currentCol = QueueX.front();
            int currentRow = QueueY.front();
            QueueY.pop();
            QueueX.pop();
            for(int i=0; i < moveRow.size(); i++){
                int dx = currentCol + moveCol[i];
                int dy = currentRow + moveRow[i];
                if(dx >= 0 && dy >= 0 && dx < width && dy < height && board[dy][dx] == -1 && maze[dy][dx] == '.'){
                    QueueX.push(dx);
                    QueueY.push(dy);
                    board[dy][dx] = board[currentRow][currentCol] + 1;
                }
            }
        }
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(maze[i][j] == '.' && board[i][j] == -1)
                    return -1;
                ret = max(ret, board[i][j]);
            }
        }
        return ret;
    }
};
int main(){
    MazeMaker maze;
    vector <string> maze1 = {"X.X", "...", "XXX", "X.X"};
    vector <string> maze2 = {".......",
                             "X.X.X..",
                             "XXX...X",
                             "....X..", 
                             "X....X.", 
                             "......."};
    int startRow = 5;
    int startCol = 0;
    vector<int> moveRow = {1, 0, -1, 0, -2, 1};
    vector<int> moveCol = {0, -1, 0, 1, 3, 0};
    cout << maze.longestPath(maze2, startRow, startCol, moveRow, moveCol);
}