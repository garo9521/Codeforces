#include <iostream>

using namespace std;

#define MAXN 1000006

bool criba[MAXN];

int main(){
	for(long long int i = 2; i < MAXN ; i++)
		if(!criba[i])
			for(long long int j = i * i; j < MAXN; j += i)
				criba[j] = true;
	int N;
	cin >> N;
	for(int i = 2; i < MAXN; i++){
		if(criba[i] && criba[N - i]){
			cout << i << " " << N - i << endl;
			break;
		}
	}
    return 0;
}
