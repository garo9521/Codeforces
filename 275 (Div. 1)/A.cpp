#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	cout << 1 << " ";
	for(int i = 0; i < N - K - 1; i++)
		cout << i + 2 << " ";
	
	int fin = N;
	int ini = N - K + 1;
	for(int i = 0; i < K; i += 2){
		cout << fin << " ";
		fin--;
		if(i + 1 < K){
			cout << ini << " ";
			ini++;
		}
	}
	return 0;
}