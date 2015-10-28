#include <bits/stdc++.h>

#define MAXN 1000000

using namespace std;

int dig[MAXN];

int main(){
	int N;
	cin >> N;
	int k = 0;
	while(N){
		dig[k++] = N % 10;
		N /= 10;
	}
	int n = 0;
	for(int i = 0; i < 7; i++)
		n = max(n, dig[i]);
	cout << n << endl;
	for(int i = 0; i < n; i++){
		int sal = 0;
		int pot = 1;
		for(int j = 0; j < 7; j++){
			if(dig[j]){
				sal += pot;
				dig[j]--;
			}
			pot *= 10;
		}
		cout << sal << " ";
	}
	return 0;
}