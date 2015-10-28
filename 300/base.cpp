#include <bits/stdc++.h>

#define MAXN 1000000

using namespace std;
char cadena[MAXN];

int main(){
	string a;
	cin >> a;
	if(a.find("CODE") < a.size() && a.find("FORCES") < a.size() && a.find("CODE") == 0 && a.find("FORCES") == a.size() - 6)
		puts("YES");
	else if(a.find("CODEFORCES") < a.size())
		puts("YES");
	else puts("NO");
	return 0;
}