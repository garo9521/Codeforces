#include <bits/stdc++.h>

#define MAXN 1000000

using namespace std;

pair<int, int> A[MAXN];

int main(){
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= M; i++)
		cin >> A[i].first >> A[i].second;
	sort(A + 1, A + M + 1);
	M++;
	A[0] = make_pair(1, A[1].second + A[1].first - 1);
	for(int i = 1; i < M; i++){
		if(abs(A[i].second - A[i - 1].second) > A[i].first - A[i - 1].first){
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	int ans = 0;
	for(int i = 1; i < M; i++){
		int dist = A[i].first - A[i - 1].first;
		int alt = abs(A[i].second - A[i - 1].second);
		dist -= alt;
		ans = max(A[i].second, max(ans, A[i - 1].second));
		ans = max(ans, A[i].second + dist / 2);
		ans = max(ans, A[i - 1].second + dist / 2);
	}
	ans = max(ans, A[M - 1].second + N - A[M - 1].first);
	cout << ans << endl;
	return 0;
}