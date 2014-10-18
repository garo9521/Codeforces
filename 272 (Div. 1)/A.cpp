#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define INF (1 << 30)
#define MOD 1000000007


int main(){
	long long int a, b;
	cin >> a >> b;
	long long int ans = 0;
	for(int x = 1; x < b; x++){
		ans = (ans + (a * x) % MOD) % MOD;
		long long int sum = ((a * (a + 1)) / 2) % MOD;
		long long int c = (((x * b) % MOD) * sum) % MOD;
		ans = (ans + c) % MOD;
	}
	cout << ans << endl;
	return 0;
}