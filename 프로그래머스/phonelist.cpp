#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[1000001] = {0,};

bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i=0; i<phone_book.size(); i++){
        visited[i] = true;
        for(int j=0; j<phone_book.size();j++){
            if(phone_book[i].size() > phone_book[j].size() || visited[j])
                continue;
            if(phone_book[i] == phone_book[j].substr(0, phone_book[i].size())){
                answer = false;
            }
        }
        visited[i] = false;
    }
    return answer;
}
int main(){
    vector<string> pb = {"119", "97674223", "1195524421"};
    vector<string> pb2 = {"123", "456", "789"};
    vector<string> pb3 = {"12","123","1235","567","88"};
    cout << solution(pb3);
}