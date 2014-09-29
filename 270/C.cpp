#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

pair <string, string> names[MAXN];

bool menor(string a, string b){
	for(int i = 0; i < min(a.size(), b.size()); i++){
		if(a[i] < b[i])
			return true;
		if(a[i] > b[i])
			return false;
	}
	if(a.size() < b.size())
		return true;
	return false;
}

int main(){
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> names[i].first >> names[i].second;
	string ant = "";
	bool chosto = true;
	for(int i = 0; i < N && chosto; i++){
		int pos;
		cin >> pos;
		if(menor(names[pos].first, names[pos].second)){
			if(menor(ant, names[pos].first)){
				ant = names[pos].first;
			}else{
				if(menor(ant, names[pos].second)){
					ant = names[pos].second;
				}else{
					chosto = false;
				}
			}
		}else{
			if(menor(ant, names[pos].second)){
				ant = names[pos].second;
			}else{
				if(menor(ant, names[pos].first)){
					ant = names[pos].first;
				}else{
					chosto = false;
				}
			}
		}
	}
	if(chosto)
		puts("YES");
	else puts("NO");
	return 0;
}