#include <bits/stdc++.h>

using namespace std;

#define MAXN 2005
#define pii pair<int, int>


int matriz[MAXN][MAXN];
vector < pii > aristas[MAXN];
priority_queue < pair<int, pii > > cola;
bool vis[MAXN];
bool chosto = true;
int K;

void busca(int nodo, int padre, long long int costo){
	if(matriz[K][nodo] != costo){
		chosto = false;
		return;
	}
	for(int i = 0; i < aristas[nodo].size(); i++)
		if(padre != aristas[nodo][i].first)
			busca(aristas[nodo][i].first, nodo, costo + aristas[nodo][i].second);
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			scanf("%d", &matriz[i][j]);
			if(i != j && matriz[i][j] == 0)
				chosto = false;
		}
	vis[0] = true;
	for(int i = 1; i < N; i++)
		cola.push(make_pair(-matriz[0][i], make_pair(0, i)));
	while(!cola.empty()){
		pair<int, pii > now = cola.top();
		cola.pop();
		while(vis[now.second.second] && !cola.empty()){
			now = cola.top();
			cola.pop();
		}
		if(! vis[now.second.second]){
			vis[now.second.second] = true;
			aristas[now.second.first].push_back(make_pair(now.second.second, -now.first));
			aristas[now.second.second].push_back( make_pair(now.second.first, -now.first));
		}
		int nodo = now.second.second;
		for(int i = 0; i < N; i++){
			if(i == nodo || vis[i])
				continue;
			cola.push(make_pair(-matriz[nodo][i], make_pair(nodo, i)));
		}
	}
	for(int i = 0; i < N; i++){
		K = i;
		busca(i, -1, 0);
	}
	if(chosto)
		puts("YES");
	else puts("NO");
	return 0;
}