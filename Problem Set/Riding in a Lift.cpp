#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 5005

long long int DP[MAXN * 2][2];


int main(){
    int N, A, B, K;
    cin >> N >> A >> B >> K;
    if(A > B){
        int n = N;
        N = N - B - 1;
        B = n - B + 1;
        A = n - A + 1;
    }else{
        N = B - 2;
    }
	DP[0][0] = 1;
    for(int i = 1; i <= N; i++)
        DP[i][0] = (DP[i - 1][0] + 1) % MOD;
    for(int k = 1; k <= K; k++){
        DP[0][k & 1] = 0;
        int a = (k + 1) & 1;
        for(int i = 1; i <= N; i++){
            DP[i][k & 1] = (DP[i - 1][k & 1] + DP[min(i * 2, N)][a] - (DP[i][a] - DP[i - 1][a]) + MOD) % MOD;
        }
    }
	if(B - A - 2 > 0)
		cout << (DP[B - A - 1][K & 1] - DP[B - A - 2][K & 1] + MOD) % MOD << endl;
	else cout << DP[B - A - 1][K & 1] << endl;

    return 0;
}