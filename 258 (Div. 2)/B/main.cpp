#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
int N;

int A[MAXN];

bool valida(){
    for(int i = 1; i < N; i++)
        if(A[i] - A[i - 1] < 0)
            return false;
    return true;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    int ini = -1, fin = -1;
    for(int i = 1; i < N; i++){
        if(A[i] - A[i - 1] < 0){
            ini = i - 1;
            break;
        }
    }
    if(ini == -1)
        ini = 0;
    for(int i = ini + 1; i < N; i++){
        if(A[i] - A[i - 1] > 0){
            fin = i;
            break;
        }
    }
    if(fin == -1)
        fin = N;
    reverse(A + ini, A + fin);
    if(valida())
        cout << "yes" << endl << ini + 1<< " " << fin << endl;
    else cout << "no" << endl;
    return 0;
}
