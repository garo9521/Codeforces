#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    if(N == 0){
        cout << 0 << " " << 1 << endl;
        cout << 0 << " " << (int)(M) << endl;
        cout << 0 << " " << 0 << endl;
        cout << 0 << " " << (int)(M - 1) << endl;
        return 0;
    }
    if(M == 0){
        cout << 1 << " " << 0 << endl;
        cout << (int)(N) << " " << 0 << endl;
        cout << 0 << " " << 0 << endl;
        cout << (int)(N - 1) << " " << 0 << endl;
        return 0;
    }
    cout << 0 << " " << 0 << endl;
    cout << (int)(N) << " " << (int)(M) << endl;
    double maxi = 0.0;
    int pos = 0;
    if(N > M){
        for(double i = 0.0; i <= M / 2; i++){
            double dist = sqrt(i * i + N * N) + sqrt((M - i) * (M - i) + N * N);
            if(dist > maxi){
                pos = i;
                maxi = dist;
            }
        }
        cout << 0 << " " << (int) (M - pos) << endl;
        cout << (int)(N) << " " << 0 << endl;

    }else{
        for(double i = 0.0; i <= N / 2; i++){
            double dist = sqrt(i * i + M * M) + sqrt((N - i) * (N - i) + M * M);
            if(dist > maxi){
                pos = i;
                maxi = dist;
            }
            cout << dist << endl;
        }
        cout << (int) (N - pos) << " " << 0 << endl;
        cout << 0 << " " << (int)(M) << endl;

    }
    return 0;
}
