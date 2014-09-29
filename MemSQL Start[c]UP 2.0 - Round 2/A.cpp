#include <bits/stdc++.h>

#define MAXN 1000000

using namespace std;
char A[MAXN], B[MAXN];
long long int a[MAXN], b[MAXN];

int main(){
	cin >> A >> B;
	int n = strlen(A);
	int m = strlen(B);
	a[0] = A[n - 1] - '0';
	int pos = 0;
	for(int i = n - 2; i >= 0; i--){
		++pos;
		a[pos] += A[i] - '0';
		int x = min(a[pos - 1], a[pos]);
		a[pos + 1] += x;
		a[pos] -= x;
		a[pos - 1] -= x;
	}
	b[0] = B[m - 1] - '0';
	pos = 0;
	for(int i = m - 2; i >= 0; i--){
		++pos;
		b[pos] += B[i] - '0';
		int x = min(b[pos - 1], b[pos]);
		b[pos + 1] += x;
		b[pos] -= x;
		b[pos - 1] -= x;
	}
	for(int i = 0; i <= n + 2; i++)
		cout << a[i] << " ";
	cout << endl;
	for(int i = 0; i <= m + 2; i++)
		cout << b[i] << " ";
	
	return 0;
}