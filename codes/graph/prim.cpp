const int N = 2005;
int dis[N][N]; // input
int distfromtree[N];
for (int i = 1; i <= n; i++)
	distfromtree[i] = dis[1][i];
int res = 0;
for (int i = 2; i <= n; i++) {
	int mindist = INT_MAX, next = -1;
	for (int j = 1; j <= n; j++) {
		if (distfromtree[j] != 0 && distfromtree[j] < mindist) {
			mindist = distfromtree[j];
			next = j;
		}
	}
	res += mindist;
	for (int j = 1; j <= n; j++)
		distfromtree[j] = min(distfromtree[j], dis[next][j]);
}