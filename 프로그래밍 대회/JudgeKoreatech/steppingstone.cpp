/****************************************
    
    Judge Koreatech 1011번

    Input : int array

    Output : min step

    Calculates min step using DP


    
    10/09 coded by bmkim
    
******************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T, N, Ns[10004];
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < 3; i++) Ns[i] = 0;
        for (int i = 3; i < N + 3; i++)
        {
            cin >> Ns[i];
            Ns[i] += min(min(Ns[i - 1], Ns[i - 2]), Ns[i - 3]);
        }
        Ns[N + 3] = min(min(Ns[N + 2], Ns[N + 1]), Ns[N]);
        cout << Ns[N + 3] << '\n';
    }
    return 0;
}