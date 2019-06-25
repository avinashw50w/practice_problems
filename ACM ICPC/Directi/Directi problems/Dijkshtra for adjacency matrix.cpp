#define REP(i,a,b) for(int i=a;i<b;++i)
#define INF 1000000007
int N; // number of nodes

int findMin(int dist[], int vis[]) {
	int mini = INF, m;
	REP(i, 0, N)
		if(!vis[i] and dist[i] <= mini) {
			mini = dist[i];
			m = i;
		}
	return m;
}

void dijkshtra(int G[N][N], int src, int dist[N]) {

	bool vis[N];
	REP(i,0,N) vis[i] = false, dist[i] = INF;

	dist[src] = 0;

	REP(cnt, 0, N-1) {
		int u = findMin(dist, vis);

		vis[u] = true;

		REP(v, 0, N) {
			if(!vis[v] and G[u][v] and dist[u] != INF and dist[v] > dist[u] + G[u][v])
				dist[v] = dist[u] + G[u][v];
		}
	}
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[N][N] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
  	int dist[N];

    dijkstra(graph, 0, dist);
  
    return 0;
}