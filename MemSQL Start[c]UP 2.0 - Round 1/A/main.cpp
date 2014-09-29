#include <bits/stdc++.h>

using namespace std;

char poken[8][10] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char cadena[100];

int main(){
    int N;
    cin >> N;
    cin >> cadena;
    for(int i = 0; i < 8; i++){

        if(N == strlen(poken[i])){
            bool chosto = false;
            for(int j = 0; poken[i][j]; j++){
                if(cadena[j] != '.' && cadena[j] != poken[i][j]){
                    chosto = true;
                    break;
                }
            }
            if(!chosto){
                cout << poken[i] << endl;
                break;
            }
        }
    }
    return 0;
}
