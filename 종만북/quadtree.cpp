#include <iostream>
#include <string>
using namespace std;
string reverse(string::iterator& it){
    char head = *it;
    it++;
    if(head == 'b' || head == 'w'){
        return string(1, head);
    }
    string upperleft = reverse(it);
    string upperright = reverse(it);
    string lowerleft = reverse(it);
    string lowerright = reverse(it);
    return string("x") + lowerleft + lowerright + upperleft + upperright;
}
int main(){
    int C;
    cin >> C;
    while(C--){
        string temp;
        cin >> temp;
        string::iterator it = temp.begin();
        cout << reverse(it) << endl;
    }
}