#include <bits/stdc++.h>

#define MOD 1000000009
#define INF (1 << 30)
#define MAXN 1000005


using namespace std;

int num[MAXN];
int answer;

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> num[i];
    int cont = 0, ant = 0;
    int i = 1, pos;
    for( i = 1; i <= N; i++){
        if(num[i - 1] < num[i]){
            ant++;
        }else{
            pos = i - 1;
            cont = 1;
            break;
        }
    }
    answer = ant;
    i++;
    if(i > N){
        printf("%d\n", N);
        return 0;
    }
    for( ; i <= N; i++){
        if(num[i - 1] < num[i]){
            cont++;
        }else{
            if(num[pos - 1] + 1 < num[pos + 1] && ant > 1)
                answer = max(ant + cont, answer);
            if(ant == 1)
                answer = max(ant + cont, answer);
            if(num[pos] < num[pos + 2] - 1 && cont > 1)
                answer = max(ant + cont, answer);
            if(cont == 1)
                answer = max(ant + cont, answer);
            answer = max(answer, cont + 1);
            ant = cont;
            pos = i - 1;
            cont = 1;

        }
    }
    if(num[pos - 1] + 1 < num[pos + 1] && ant > 1)
                answer = max(ant + cont, answer);
            if(ant == 1)
                answer = max(ant + cont, answer);
            if(num[pos] < num[pos + 2] - 1 && cont > 1)
                answer = max(ant + cont, answer);
            if(cont == 1)
                answer = max(ant + cont, answer);
            answer = max(answer, cont+ 1);
    cout << answer << endl;
    return 0;
}
