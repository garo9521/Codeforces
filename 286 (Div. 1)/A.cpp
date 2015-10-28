#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000


int gemas[MAXN];
int total[MAXN];

map <pair <int, int>, int> dp;

int f(int x, int d){
	if(d <= 2)
		return total[x + 1];
	if(d == 3)
		return total[x + 2];
	if(x + d - 1 > 30000)
		return 0;
	return max(f(x + d, d) + gemas[x + d], max(f(x + d - 1, d - 1) + gemas[x + d - 1], f(x + d + 1, d + 1) + gemas[x + d + 1]));
}

int main(){
	int N, D;
	cin >> N >> D;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		gemas[a]++;
	}
	for(int i = MAXN - 2; i >= 0; i--)
		total[i] = gemas[i] + total[i + 1];
	cout << f(D, D) + gemas[D] << endl;
	return 0;
}