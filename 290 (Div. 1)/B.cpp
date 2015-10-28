#include <bits/stdc++.h>

using namespace std;

map <pair <int, int >, int > vis;
int A[1000];
int C[1000];
int N;

int f(int x, int gcd){
	if(gcd == 1)
		return 0;
	if(x == N)
		return 1 << 29;
	if(vis.find(make_pair(x, gcd)) != vis.end())
		return vis[make_pair(x, gcd)];
	int mini = f(x + 1, gcd);
	int GCD = __gcd(gcd, A[x]) ;
	if(GCD != gcd)
		mini = min(mini, f(x + 1,  GCD) + C[x]);
	return vis[make_pair(x, gcd)] = mini;
}

int main(){
	cin >> N;
	int lol = 0;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		lol = __gcd(lol, A[i]);
	}
	for(int i = 0; i < N; i++)
		cin >> C[i];
	int ans = 1 << 30;
	
	if(lol != 1){
		cout << -1;
		return 0;
	}
	for(int i = 0; i < N; i++){
		ans = min(ans, C[i] + f(i + 1, A[i]));
	}
	
	cout << ans;
	return 0;
}