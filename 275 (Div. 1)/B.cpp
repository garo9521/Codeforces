#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005



pair <int, pair <int ,int> > A[MAXN];
int cont;
pair <int, pair <int, int> > Q[MAXN];
int ans[MAXN];

#define Mid ((l + r) / 2)
#define Left (node * 2)
#define Right (node * 2 + 1)

struct SegmentTree{
    int* tree;

    int create(int node, int l, int r){
        if(l == r) return tree[node] = 0;
        int L = create(Left, l, Mid);
        int R = create(Right, Mid + 1, r);
        return tree[node] = L | R;
    }

    int update(int node, int l, int r, int a, int set){

        if(a < l || r < a)
            return tree[node];
        if(a <= l && r <= a){


            return tree[node] = set;
        }
        int L = update(Left, l, Mid, a, set);
        int R = update(Right, Mid + 1, r, a, set);
        return tree[node] =  L | R;
    }

    int query(int node, int l, int r, int a, int b){
        if(b < l || r < a)
            return 0;


        if(a <= l && r <= b)
            return tree[node];
        int L = query(Left, l, Mid, a, b);
        int R = query(Right, Mid + 1, r, a, b);
        return L | R;
    }

    void init(int n){
        tree = new int[n * 4];
        create(1, 0, n - 1);
    }
};

#define LOGN 20

int logs[MAXN];
int sparse[MAXN][LOGN];

void precalc_sparse(int n){ // O(n log n)
    for(int i = 2; i < MAXN; i++)
        logs[i] = logs[i / 2] + 1;
        
    for(int i = 0; i < n; i++)
        sparse[i][0] = ans[i];
        
    for(int i = 0; i < logs[n]; i++){
        for(int j = 0; j < n; j++){
            int k = min(j + (1 << i), n - 1);
            int join = (sparse[j][i] & sparse[k][i]);
            sparse[j][i + 1] = join;
        }
    }
}

int query(int a, int b){ // O(1)
    if(a == b) return sparse[a][0];
    
    int binlog = logs[b - a + 1];
    int k = b - (1 << binlog) + 1;
    return (sparse[a][binlog] & sparse[k][binlog]);
}



int main(){
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		ans[i] = (1 << 30) - 1;
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		Q[i] = make_pair(a, make_pair(b, c));
		A[i * 2].first = a;
		A[i * 2].second.first = c;
		A[i * 2].second.second = i;
		A[i * 2 + 1].first = b + 1;
		A[i * 2 + 1].second.first = -1;
		A[i * 2 + 1].second.second = i;
	}
	sort(A, A + M * 2);
	SegmentTree num;
	num.init(M);
	int j = 0;
	for(int i = 1; i <= N; i++){
		while(A[j].first == i){
			if(A[j].second.first == -1){
				num.update(1, 0, M - 1, A[j].second.second, 0);
			}else{
				num.update(1, 0, M - 1, A[j].second.second, A[j].second.first);
			}
			j++;
		}
		ans[i - 1] = num.query(1, 0, M - 1, 0, M - 1);
	}
	precalc_sparse(N);
	bool can = true;
	for(int i = 0; i < M; i++){
		if(query(Q[i].first - 1, Q[i].second.first - 1) != Q[i].second.second){
			can = false;
			break;
		}
	}
	if(can){
		puts("YES");
		for(int i = 0; i < N; i++)
			cout << ans[i] << " ";
	}else puts("NO");
	return 0;
}
