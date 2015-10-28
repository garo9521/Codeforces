#include <bits/stdc++.h>

using namespace std;

#define MAXN 105
#define pii pair <int, int >
#define lli long long int

char cadena[MAXN][MAXN];

int aristas[MAXN][MAXN];
int grado[MAXN];
bool vis[MAXN];
int lol[MAXN];
int cont = 1;
bool chosto;
vector <char> salida;



int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		scanf("%s", cadena[i]);
		for(int j = 0; cadena[i][j]; j++)
			cadena[i][j] -= 'a' - 1;
	}

	for(int i = 1; i < N; i++){
		int j = 0;
		for(; cadena[i][j] == cadena[i - 1][j]; j++);
		if(cadena[i - 1][j]){
			if(!aristas[cadena[i - 1][j]][cadena[i][j]]){
				aristas[cadena[i - 1][j]][cadena[i][j]] = 1;
				grado[cadena[i][j]]++;
			}
		}
	}
	for(int i = 1; i <= 'z' - 'a' + 1; i++){
		char letra;
		int mini = 100000;
		for(int j = 1; j <= 'z' - 'a' + 1; j++){
			if(vis[j])
				continue;
			if(mini > grado[j]){
				letra = j + 'a' - 1;
				mini = grado[j];
			}
		}
		if(mini != 0){
			puts("Impossible");
			return 0;
		}
		vis[letra - 'a' + 1] = true;
		salida.push_back(letra);
		for(int j = 1; j <= 'z' - 'a' + 1; j++){
			if(aristas[letra - 'a' + 1][j] == 0)
				continue;
			grado[j]--;
		}
	}
	for(int i = 0; i < salida.size(); i++)
		printf("%c", salida[i]);
	puts("");
	return 0;
}
