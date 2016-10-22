// Implement of min cost max flow algorithm using adjacency matrix (Edmond-Karp)
// Input: 	graph, construct using AddEdge()
//			soure, sink
//Output:	max flow value, min cost value
// 			to obtain the actual flow, look at positive values only.

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
	int N;
	VVL cap, flow, cost;
	VI found;
	VL dist, pi, width;
	VPII dad;

	MinCostMaxFlow(int N) :
		N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), 
		found(N), dist(N), pi(N), width(N), dad(N) {}

	void AddEdge(int from, int to, L cap, L cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
	}

	void Relax(int s, int k, L cap, L cost, int dir) {
		L val = dist[s] + pi[s] - pi[k] + cost;
		if (cap && val < dis[k]) {
			dist[k] = val;
			dad[k] = make_pair(s, dir);
			width[k] = min(cap, width[s]);
		}
	}

	L Dijkstra(int s, int t) {
		fill(found.begin(), found.end(), false);
		fill(dist.begin(), dist.end(), INF);
		fill(width.begin(), width.end(), 0);
		dist[s] = 0;
		width[s] = INF;

		while (s != -1) {
			int best = -1;
			found[s] = true;
			for (int k = 0; k < N; k ++){
				if (found[k]) continue;
				Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
				Relax(s, k, flow[k][s], - cost[k][s], -1);
				if (best == -1 || dist[k] < dist[best]) best = k;
			}
			s = best;
		}
		for (int k = 0; k < N; k++)
			pi[k] = min(pi[k] + dist[k], INF);
		return width[t];
	}

	pair<L, L> GetMaxFlow(int s, int t) {
		L totflow = 0, totcost = 0;
		while (L amt = Dijkstra(s, t)) {
			totflow += amt;
			for (int x = t; x != s; x = dad[x].first) {
				if (dad[x].second == 1) {
					flow[dad[x].first][x] += amt;
					totcost += amt * cost[dad[x].first][x];
				} else{
					flow[x][dad[x].first] -= amt;
					totcost -= amt * cost[x][dad[x].first];
				}
			}
		}
		return make_pair(totflow, totcost);
	}
};


int main(){
	int N, M;

	while (scanf("%d%d", &N, &M) == 2) {
		VVL v(M, VL(3));
		for(int i = 0; i < M; i++){
			scanf("%Ld%Ld%Ld", &v[i][0], &v[i][1], &v[i][2]);
		}
		L D, K;
		scanf("%Ld%Ld", &D, &K);

		MinCostMaxFlow mcmf(N+1);
		for (int i = 0; i < M; i++){
			mcmf.AddEdge(int(v[i][0]), int(v[i][1]), K, v[i][2]);
			mcmf.AddEdge(int(v[i][1]), int(v[i][0]), K, v[i][2]);
		}
		mcmf.AddEdge(0, 1, D, 0);

		pair<L, L> res = mcmf.GetMaxFlow(0, N)

		if (res.first == D) {
			print("%Ld\n", res.second);
		} else {
			printf("Impossible.\n");
		}
	}

	return 0;
}



