#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

char cadena[MAXN];
char cadena2[MAXN];
int cubeta[MAXN];
bool termino[MAXN];

char diferente(char a){
	if(a >= 'a' && a <= 'z')
		return a - 'a' + 'A';
	return a - 'A' + 'a';
}

int main(){
	scanf("%s", cadena);
	scanf("%s", cadena2);
	for(int i = 0; cadena2[i]; i++)
		cubeta[cadena2[i]]++;
	int a = 0, b = 0;
	for(int i = 0; cadena[i]; i++){
		cubeta[cadena[i]]--;
		if(cubeta[cadena[i]] >= 0){
			a++;
			termino[i] = true;
		}
	}
	
	for(int i = 0; cadena[i]; i++){
		if(termino[i])
			continue;
		cubeta[diferente(cadena[i])]--;
		if(cubeta[diferente(cadena[i])] >= 0){
			b++;
			termino[i] = true;
		}
	}
	
	cout << a << " " << b << endl;
	return 0;
}