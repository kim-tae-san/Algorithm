#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class InterestingParty{
    public:
    int bestInvitation(vector <string> first, vector <string> second){
        int result = 0;
        for(int i=0; i<first.size(); i++){
            int f = 0;
            int s = 0;
            for(int j=0; j<first.size();j++){
                if(first[i]==first[j])
                    f++;
                if(first[i]==second[j])
                    f++;
                if(second[i]==first[j])
                    s++;
                if(second[i]==second[j])
                    s++;
            }
            result = max(f, result);
            result = max(s, result);
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