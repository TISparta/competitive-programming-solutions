#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   vector <int> path, rank;

   UnionFind(int N_){
      rank.assign(N_, 0);
      path.assign(N_, 0);
      for(int it = 0; it < N_; it++) path[it] = it;
   };

   int findSet(int idx){
      return ( path[idx] == idx ? idx : path[idx] = findSet(path[idx]) );
   }

   bool isSameSet(int idx1, int idx2){
      return ( findSet(idx1) == findSet(idx2) );
   }

   void unionSet(int idx1, int idx2){
      if( isSameSet(idx1, idx2) ) return;
      int x = findSet(idx1), y = findSet(idx2);
      if( rank[x] > rank[y] ) path[y] = x;
      else path[x] = y;
      if( rank[x] == rank[y] ) rank[y]++;
   }
};

const int LIM = 110, SIZE = 10000;

typedef pair <int, int> ii;

struct Edge_{
   int u, v, w;
   bool operator < (const Edge_& other) const{
      return ( w > other.w );
   }
}E[SIZE];

int tc, N, M, S, D, T, edge, ans;
vector < ii > AdjList[LIM];
bool vis[LIM];

void dfs(int u, int v, int w){
   vis[u] = true;
   if( u == v ){
      edge = w;
      return;
   }
   for(int it = 0; it < AdjList[u].size(); it++)
      if( not vis[AdjList[u][it].first] )
         dfs(AdjList[u][it].first, v, min(w, AdjList[u][it].second) );
}

void Kruskal(){
   UnionFind UF(N + 1);
   int setSize = 1;
   sort(E, E + M);
   for(int it = 0; it < M and setSize != N; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) ){
         AdjList[E[it].u].push_back( ii(E[it].v, E[it].w) );
         AdjList[E[it].v].push_back( ii(E[it].u, E[it].w) );
         setSize++, UF.unionSet(E[it].u, E[it].v);
      }
}

void clear_(){
   for(int it = 1; it <= N; it++) AdjList[it].clear();
   fill(vis, vis + N + 1, false);
}

int main(){
   while(scanf("%d %d", &N, &M), N | M){
      for(int it = 0; it < M; it++)
         scanf("%d %d %d", &E[it].u, &E[it].v, &E[it].w);
      Kruskal();
      scanf("%d %d %d", &S, &D, &T);
      dfs(S, D, INT_MAX);
      printf("Scenario #%d\n", ++tc);
      printf("Minimum Number of Trips = %d\n\n", ( T + edge - 2 ) / ( edge - 1 ) );
      clear_();
   }
   return(0);
}
