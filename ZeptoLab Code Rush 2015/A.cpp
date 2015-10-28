#include <bits/stdc++.h>

#define MAXN 1000005
#define pii pair <int, int> 

using namespace std;
char A[MAXN];

int main(){
	int N;
	cin >> N;
	cin >> A;
	for(int i = 0; i < N; i++){
		if(A[i] == '.')
			continue;
		for(int j = 1; j < N; j++){
			if(A[i + j] == '*' && A[i + 2 * j] == '*' && A[i + 3 * j] == '*' && A[i + 4 * j] == '*'){
				puts("yes");
				return 0;
			}
		}
	}
	puts("no");
	return 0;
}