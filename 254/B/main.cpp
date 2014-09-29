#include <bits/stdc++.h>

#define MOD 1000000009
#define INF (1ll << 60)
#define MAXN 1005

#define lld long long int

using namespace std;

lld num[2][MAXN];

#define M ((l + r) / 2)
#define Left (node * 2)
#define Right (node * 2 + 1)

#define pii pair <lld, lld>
#define mp make_pair

lld answer = -INF;
lld FIL[MAXN * MAXN];
lld COL[MAXN * MAXN];

struct SegmentTree{
    pii* tree;

    pii create(int node, int l, int r, int x){
        if(l == r) return tree[node] = mp(num[x][l], l);
        pii L = create(Left, l, M, x);
        pii R = create(Right, M + 1, r, x);
        return tree[node] = max(L, R);
    }

    pii update(int node, int l, int r, int a, lld set){

        if(a < l || r < a)
            return tree[node];
        if(a <= l && r <= a){
            return tree[node] = mp(set, a);
        }
        pii L = update(Left, l, M, a, set);
        pii R = update(Right, M + 1, r, a, set);
        return tree[node] =  max(L, R);
    }

    pii query(int node, int l, int r, int a, int b){
        if(b < l || r < a)
            return mp(-INF,-1);
        if(a <= l && r <= b)
            return tree[node];
        pii L = query(Left, l, M, a, b);
        pii R = query(Right, M + 1, r, a, b);
        return max(L, R);
    } // O(log n)

    void init(int n, int x){
        tree = new pii[n * 4];
        create(1, 0, n - 1, x);
    }
};

int main(){
    int N, m, K;
    lld P;
    cin >> N >> m >> K >> P;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < m; j++){
            lld a;
            cin >> a;
            num[0][i] += a;
            num[1][j] += a;
        }
    }
    lld C = 0, F = 0;
    SegmentTree fila, columna;
    fila.init(N, 0);
    columna.init(m, 1);
    for(int i = 1; i <= K; i++){
        pii f, c;
        f = fila.query(1, 0, N - 1, 0, N - 1);
        c = columna.query(1, 0, m - 1, 0, m - 1);
        FIL[i] = f.first;
        num[0][f.second] -= P * m;
        fila.update(1, 0, N - 1, f.second, num[0][f.second]);
        COL[i] = c.first;
        num[1][c.second] -= P * N;
        columna.update(1, 0, m - 1, c.second, num[1][c.second]);
    }
    for(int i = 1; i <= K; i++)
        COL[i]+= COL[i - 1], FIL[i] += FIL[i - 1];
    for(lld i = 0; i <= K; i++)
        answer = max(answer, COL[i] + FIL[K - i] - (K - i) * P * i);
    cout << answer << endl;
    return 0;
}
