#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int num[MAXN];

int main(){
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	reverse(num, num + N);
	int ans = 0;
	for(int i = 0; i < N; i += K)
		ans += (num[i] - 1) * 2;
	cout << ans << endl;
	return 0;
}