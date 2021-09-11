/****************************************
    
    Programmer Lv2. Phone_book

    Input : string vector

    Output : Existence of Preffix

    Define the Existence of Preffix in a string vector using hashmap


    
    9/11 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book){
    bool answer = true;

    unordered_map<string, int> hash_map;
    for(int i=0; i<phone_book.size(); i++){
        hash_map[phone_book[i]] = 1;
    }

    for(int i=0; i<phone_book.size(); i++){
        string phone_number = "";
        for(int j=0; j<phone_book.size();j++){
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && phone_number != phone_book[i])
                return false;
        }
    }
    return true;
}