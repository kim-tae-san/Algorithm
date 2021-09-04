#include <iostream>
#include <vector>
#include <string>
using namespace std;
class FriendScore{
    public:
    int highestScore(vector <string> friends){
        vector<int> result;
        for(int i=0;i<friends.size();i++){
            result.push_back(0);
        }
        for(int i=0; i<friends.size(); i++){
            for(int j=0; j<friends.size(); j++){
                if(friends[i][j] == 'Y'){
                    result[i]++;
                }
                else if(i!=j){
                    for(int k=0; k<friends.size();k++){
                        if(friends[i][k] == 'Y' && friends[j][k] == 'Y' && i!=k){
                            result[i]++;
                        }
                    }
                }
            }
        }
        return *max_element(result.begin(), result.end());
    }
};
int main()
{
    vector <string> example = {"NNNNYNNNNN", "NNNNYNYYNN", "NNNYYYNNNN", "NNYNNNNNNN", "YYYNNNNNNY", "NNYNNNNNYN", "NYNNNNNYNN", "NYNNNNYNNN", "NNNNNYNNNN", "NNNNYNNNNN"};
    FriendScore highest;
    int result = highest.highestScore(example);
    cout << result;
}