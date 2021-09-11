/****************************************
    
    Programmer Lv2. Phone_book

    Input : string vector

    Output : Existence of Preffix

    Define the Existence of Preffix in a string vector using bubble sort algorithm


    
    9/11 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    bool answer = true;
    for(int i=0; i<phone_book.size() - 1; i++){
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))
            return false;
    }
    return answer;
}
int main(){
    vector<string> pb = {"119", "97674223", "1195524421"};
    vector<string> pb2 = {"123", "456", "789"};
    vector<string> pb3 = {"12","123","1235","567","88"};
    cout << solution(pb3);
}