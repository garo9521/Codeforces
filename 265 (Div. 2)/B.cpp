#include <bits/stdc++.h>

#define INF (1 << 30)
#define MAXN 1000005

using namespace std;
 
int A[MAXN];
int grupos;
int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> A[i];
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(A[i] == 1){
			grupos++;
			while(A[i] == 1){
				ans++;
				i++;
			}
			i--;
		}
	}
	cout << ans + grupos - 1 << endl;
	return 0;
}