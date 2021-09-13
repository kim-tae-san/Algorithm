/****************************************
    
    Programmers Lv3. BestAlbum

    Input : vector of genres and nplays

    Output : bestalbum

    Make the best album using hash_map and sort


    
    9/13 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int> > > hash_map;
    unordered_map<string, int> totalplay;
    
    for (int i = 0; i < genres.size(); i++){
        hash_map[genres[i]].push_back(make_pair(plays[i], i));
        totalplay[genres[i]] += plays[i];
    }
    for(int i=0; i< genres.size();i++){
        sort(hash_map[genres[i]].begin(), hash_map[genres[i]].end(), compare2);
    }
    vector<pair<string, int> > bestalbum(totalplay.begin(), totalplay.end());
    sort(bestalbum.begin(), bestalbum.end(), compare);
    for(auto i: bestalbum){
        vector<pair<int, int> > song = hash_map[i.first]; 
        if(song.size() < 2){
            answer.push_back(song[0].second);
            continue;
        }
        answer.push_back(song[0].second);
        answer.push_back(song[1].second);
    }
    return answer;
}