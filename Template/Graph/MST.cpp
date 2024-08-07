// Prim
// 时间复杂度为 O(n^2+m)
int n;  // n表示点数
int g[N][N];  // 邻接矩阵，存储所有边
int dist[N];  // 存储其他点到当前最小生成树的距离
bool st[N];  // 存储每个点是否已经在生成树中

// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int Prim() {
  memset(dist, 0x3f, sizeof dist);
  int res = 0;
  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++) {
      if (!st[j] && (t == -1 || dist[t] > dist[j])) {
        t = j;
      }
    }
    if (i && dist[t] == INF) {
      return INF;
    }
    if (i) {
      res += dist[t];
    }
    st[t] = true;
    for (int j = 1; j <= n; j++) {
      dist[j] = min(dist[j], g[t][j]);
    }
  }
  return res;
}



// Krustal
// 时间复杂度为 O(mlogm)
int n, m;       // n是点数，m是边数
int p[N];       // 并查集的父节点数组

struct Edge {
  int a, b, w;
  bool operator< (const Edge &W)const {
    return w < W.w;
  }
} edges[M];

int Find(int x) {
  if (p[x] != x) {
    p[x] = find(p[x]);
  }
  return p[x];
}

int Kruskal() {
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
      int a = edges[i].a, b = edges[i].b, w = edges[i].w;
      a = Find(a), b = Find(b);
      if (a != b) {
        p[a] = b;
        res += w;
        cnt++;
      }
    }
    if (cnt < n - 1) {
      return INF;
    }
    return res;
}
