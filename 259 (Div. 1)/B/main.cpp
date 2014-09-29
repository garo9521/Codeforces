#include <bits/stdc++.h>

using namespace std;

int DP[105][1 << 17];
bool vis[105][1 << 17];
int numero[10000];
int M[100];
int A[105];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int N;

int f(int pos, int mask){
    if(vis[pos][mask])
        return DP[pos][mask];
    vis[pos][mask] = 1;
    if(pos == N)
        return DP[pos][mask] = 0;
    DP[pos][mask] = (1 << 29);
    for(int i = 0; i < 16; i++){
        if(!((1 << i) & mask)){
            for(int j = prime[i]; j < 59; j += prime[i]){
                if(!(M[j] & mask)){
                    DP[pos][mask] = min(DP[pos][mask], f(pos + 1, mask | M[j]) + abs(A[pos] - j));
                }
            }
        }
    }
    return DP[pos][mask] = min(DP[pos][mask], f(pos + 1, mask) + A[pos] - 1);
}

void F(int pos, int mask){
    if(pos == N)
        return;
    int mejor = (1 << 29);
    int a;
    int lol;
    for(int i = 0; i < 16; i++){
        if(!((1 << i) & mask)){
            for(int j = prime[i]; j < 59; j += prime[i]){
                if(!(M[j] & mask)){
                    if(mejor > f(pos + 1, mask | M[j]) + abs(A[pos] - j)){
                        mejor = f(pos + 1, mask | M[j]) + abs(A[pos] - j);
                        a = j;
                        lol = mask | M[j];
                    }
                }
            }
        }
    }
    if(mejor > f(pos + 1, mask) + A[pos] - 1){
        mejor = f(pos + 1, mask) + A[pos] - 1;
        a = 1;
        lol = mask;
    }
    cout << a << " ";
    F(pos + 1, lol);
}

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
                M[i] |= (1 << numero[j]);
                a /= j;
            }
        }
        if(a > 1)
            M[i] |= (1 << numero[a]);
    }
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    f(0, 0);
    F(0, 0);
    return 0;
}
