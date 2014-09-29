#include <bits/stdc++.h>

using namespace std;

int DP[105][1 << 17];
bool vis[105][1 << 17];
int numero[10000];
int M[100];

int main(){
    numero[2] = 0;
    numero[3] = 1;
    numero[5] = 2;
    numero[7] = 3;
    numero[11] = 4;
    numero[13] = 5;
    numero[17] = 6;
    numero[19] = 7;
    numero[23] = 8;
    numero[29] = 9;
    numero[31] = 10;
    numero[37] = 11;
    numero[41] = 12;
    numero[43] = 13;
    numero[47] = 14;
    numero[53] = 15;
    for(int i = 2; i < 59; i++){
        int a = i;
        int raiz =(int) (sqrt(i));
        for(int j = 2; j <= raiz; j++){
            while(a % j == 0){
                num[i] |= (1 << numero[j]);
                a /= j;
            }
        }
        if(a > 1)
            num[i] |= (1 << numero[a]);
        cout << num[i] << endl;
    }
    return 0;
}
