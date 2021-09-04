#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(int left, int right, vector<int>& h){
    if(left==right)
        return h[left];
    int mid = (left+right)/2;
    int ret = max(solve(left, mid, h), solve(mid+1, right, h));
    int lo = mid;
    int hi = mid+1;
    int height = min(h[lo], h[hi]);
    ret = max(ret, height * 2);
    while(left < lo || right > hi){
        if(hi < right && (lo==left || h[lo-1] < h[hi+1])){
            hi++;
            height = min(height, h[hi]);
        }
        else{
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}
int main(){
    int C;
    cin >> C;
    for(int i=0; i<C; i++){
        int n;
        cin >> n;
        vector<int> h;
        for(int j=0; j< n; j++){
            int temp;
            cin >> temp;
            h.push_back(temp);
        }
        cout << solve(0, n-1, h) << endl;
    }
}