#include <bits/stdc++.h>

#define MAXN 1000005
#define pii pair <int, int> 

using namespace std;
int costo[MAXN];

int main(){
	int N;
	cin >> N;
	for(int i = 2; i < (1 << (N + 1)); i++)	
		cin >> costo[i];
	int ans = 0;
	for(int i = (1 << N) - 1; i > 0; i--){
		ans += abs(costo[i * 2] - costo[i * 2 + 1]);
		costo[i] += max(costo[i * 2], costo[i * 2 + 1]);
	}
	cout << ans << endl;
	return 0;
}