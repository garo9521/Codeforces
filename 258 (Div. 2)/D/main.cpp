#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

char cadena[MAXN];

long long int par,impar;
long long int A[2];
long long int B[2];

int main(){
    cin >> cadena;
    for(int i = 0; cadena[i]; i++){
        if(cadena[i] == 'a'){
            impar += A[i & 1];
            par += A[(i + 1) & 1];
            A[i & 1] ++;
        }else{
            impar += B[i & 1];
            par += B[(i + 1) & 1];
            B[i & 1] ++;
        }
    }
    cout << par << " " << impar + strlen(cadena) << endl;
    return 0;
}
