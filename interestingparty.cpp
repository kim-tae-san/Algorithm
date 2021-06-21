#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class InterestingParty{
    public:
    int bestInvitation(vector <string> first, vector <string> second){
        map <string, int> dic;
        for(int i=0; i<first.size(); i++){
            dic[first[i]]=0;
            dic[second[i]]=0;
        }
        for(int i=0;i<first.size();i++){
            dic[first[i]]++;
            dic[second[i]]++;
        }
        int result =0;
        map <string, int>::iterator it;
        for(it= dic.begin(); it!= dic.end(); it++){
            result = max(result, it->second);
        }
        return result;
    }
};

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector <string> first = {"snakes", "programming", "cobra", "monty"};
    vector <string> second = {"python", "python", "anaconda", "python"};
    InterestingParty party;
    int a = party.bestInvitation(first, second);
    printf("%d", a);

} 