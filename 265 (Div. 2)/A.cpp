#include <bits/stdc++.h>

#define INF (1 << 30)
#define MAXN 1000005

using namespace std;

char cadena[MAXN];

int main(){
	int N;
	cin >> N;
	cin >> cadena;
	int ans = 0;
	for(int i = 0; i < N; i++){
		ans++;
		if(cadena[i] == '0')
			break;
	}
	cout << ans << endl;
	return 0;
}