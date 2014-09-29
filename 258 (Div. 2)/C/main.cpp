#include <bits/stdc++.h>

using namespace std;

#define lld long long int

bool solve(lld N, lld K, lld D1, lld D2){
    // case 1
    lld x = (K - (D1 * 2 + D2));
    lld y = N - K - D2 * 2 - D1;
    if(x % 3 == 0 && y % 3 == 0 && x >= 0 && y >= 0)
       return true;
    // case 2
    x = (K - (D2 * 2 + D1));
    y = N - K - D1 * 2 - D2;
    if(x % 3 == 0 && y % 3 == 0 && x >= 0 && y >= 0)
       return true;
    x = (K - max(D1, D2) - abs(D1 - D2));
    y = N - K - D1 - D2;
    if(x % 3 == 0 && y % 3 == 0 && x >= 0 && y >= 0)
       return true;
    x = (K - D2 - D1);
    y = N - K - max(D1, D2) - abs(D1 - D2);
    if(x % 3 == 0 && y % 3 == 0 && x >= 0 && y >= 0)
       return true;

    return false;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        lld a, b, c, d;
        cin >> a >> b >> c >> d;
        if(solve(a, b, c, d))
            puts("yes");
        else puts("no");
    }
    return 0;
}
