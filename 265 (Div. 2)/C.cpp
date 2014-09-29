#include <bits/stdc++.h>

#define INF (1 << 30)
#define MAXN 1000005

using namespace std;

char cadena[MAXN];
char aux[MAXN];

int main(){
	int N, K;
	cin >> N >> K;
	cin >> cadena;
	for(int i = 0; i < N; i++)
		aux[i] = cadena[i];
	for(int i = N - 1; i >= 0; i--){
		if(cadena[i] - 'a' + 1 == K)
			continue;
		for(char j = cadena[i] + 1; j <= 'a' + K - 1; j++){
			if(i >= 1)
				if(cadena[i - 1] == j)
					continue;

			if(i >= 2)
				if(cadena[i - 2] == j)
					continue;
			aux[i] = j;
			int pos = i + 1;

			bool chosto = true;
			while(pos < N){
				chosto = false;
				for(char k = 'a'; k <= K + 'a' - 1; k++){
					if(pos >= 1)
						if(aux[pos - 1] == k)
							continue;

					if(pos >= 2)
						if(aux[pos - 2] == k)
							continue;
					aux[pos] =  k;
					chosto = true;
					break;
				}
				if(!chosto)
					break;
				pos++;
			}
			if(chosto){
				cout << aux << endl;
				return 0;
			}
			break;
		}
	}
	puts("NO");
	return 0;
}
