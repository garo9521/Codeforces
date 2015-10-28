#include <bits/stdc++.h>

using namespace std;

string a, b;

int main(){
	cin >> a >> b;
	bool can = true;
	for(int i = 0; i < a.length(); i++){
		if(a[i] == b[i])
			continue;
		if(a[i] + 1 == b[i]){
			int lol = 0;
			int n = 0;
			for(int j = i + 1; j < a.length(); j++){
				if('a'== b[i])
					lol++;
				n++;
			}
			if(lol == n)
				continue;
			
			for(int j = 0; j < i; j++)
				printf("%c", a[j]);
			printf("%c", a[i] + 1);
			for(int j = i + 1; j < a.length(); j++)
				printf("%c", 'a');
			can = false;
		}else{
			for(int j = 0; j < i; j++)
				printf("%c", a[j]);
			printf("%c", a[i] + 1);
			for(int j = i + 1; j < a.length(); j++)
				printf("%c", a[j]);
			can = false;
		}
		break;
	}
	if(can)
		puts("No such string");
	return 0;
}