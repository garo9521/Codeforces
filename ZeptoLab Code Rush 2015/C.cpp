#include <bits/stdc++.h>

#define MAXN 1000005
#define pii pair <int, int> 
#define lld long long int

using namespace std;


lld T, A, B, C, D;

lld costo(lld x){
	lld sobra = T - x * C;
	if(sobra < 0)	return -100000000000ll;
	lld y = sobra / D;
	return x * A + y * B;
}

int main(){
	cin >> T >> A >> B >> C >> D;
	lld ans = 0;
	for(int i = 0; i < MAXN; i++)
		ans = max(ans, costo(i));
	swap(A, B);
	swap(C, D);
	
	for(int i = 0; i < MAXN; i++)
		ans = max(ans, costo(i));
	cout << ans << endl;
	return 0;
}