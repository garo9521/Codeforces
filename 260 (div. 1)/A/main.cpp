#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

long long int dp[MAXN];
long long int num[MAXN];
long long int suma[MAXN];
vector <long long int> A;

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);
    suma[num[0]] = num[0];
    A.push_back(num[0]);
    for(int i = 1; i < N; i++){
        suma[num[i]] += num[i];
        if(num[i] != num[i - 1])
            A.push_back(num[i]);
    }
    A.push_back(-1);
    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] == A[i + 1] + 1)
            dp[i] = max(dp[i + 1], dp[i + 2] + suma[A[i]]);
        else dp[i] = dp[i + 1] + suma[A[i]];
    }
    cout << dp[0] << endl;
    return 0;
}
