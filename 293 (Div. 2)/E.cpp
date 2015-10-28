#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

int A[MAXN];

int main(){
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		scanf("%d", A[i]);
		cout << A[i] << " " ;
	}
	return 0;
}