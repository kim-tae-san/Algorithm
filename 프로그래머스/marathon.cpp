/****************************************
    
    find unmatched element

    Input : two string arrays

    Output : a unmatched element

    Find a unmatched element using hashset


    
    9/9 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> comp;
    for(auto i:completion){
        comp.insert(i);
    }
    while(participant.size()>1){
        string person = participant[participant.size()-1];
        participant.pop_back();
        if(comp.find(person) == comp.end())
            return person;
        else
            comp.erase(comp.find(person));
    }
    answer = participant[0];
    return answer;
}
int main(){
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    cout << solution(participant, completion);
}