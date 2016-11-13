#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e6 + 5;
const int maxV = 1e5 + 5;
typedef struct edge{
	int begin, end, weight;
}edge;
edge edges[maxn], cs[maxn];
int n, m, cnt, node[maxV], fa[maxV];
long long sum;
bool cmp(struct edge a,struct edge b){
	return a.weight < b.weight;
}
int find(int x){
	return fa[x] == 0 ? x : fa[x] = find(fa[x]);
}//注意此行
void Kruskal(int Edges){//传入边数
	sum = 0;
	memset(fa, 0,sizeof(fa));
	for (int i = 0; i < Edges; i++){
		int x = edges[i].begin;
		int y = edges[i].end;
		int dx = find(x);
		int dy = find(y);
		if (dx != dy){
			fa[dx] = dy;
			sum += edges[i].weight;
			G[x].push_back(y);
			G[y].push_back(x);
			cs[cnt++] = edges[i];
		}
	}
}
vector<int>G[maxV];
void init(){
	for (int i = 1; i <= n; i++){
		G[i].clear();
	}
}
int DFS(int now, int fa){
	int ans = 1;
	int siz = G[now].size();
	for (int i = 0; i < siz; i++){
		int next = G[now][i];
		if (next != fa){
			ans += DFS(next, now);
		}
	}
	node[now] = ans;
	return ans;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> n >> m;
		init();
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &edges[i].begin, &edges[i].end, &edges[i].weight);
		sort(edges, edges + m, cmp);
		memset(node, 0, sizeof(node));
		cnt = 0;
		Kruskal(m);
		DFS(1, -1);
		double exp = 0;
		for (int i = 0; i < cnt; i++){
			int x = cs[i].begin;
			int y = cs[i].end;
			int dMin = min(node[x], node[y]);
			int dMax = n - dMin;
			exp += (long long)dMin*dMax*cs[i].weight;
		}
		exp = exp / n / (n - 1) * 2;
		printf("%lld %.2lf\n", sum, exp);
	}
	return 0;
}//1001
