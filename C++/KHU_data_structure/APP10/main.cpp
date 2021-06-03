#include <iostream>
#include <vector>
#include "GraphType.h"
#include "QueType.h"
using namespace std;

vector<int> v[101];
int visited[101] = { 0 };
int num;

void virus(int x) {
	if (visited[x]) return;
	visited[x] = 1;
	num++;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		virus(y);
	}
}
int main() {
	int n, m, a, b;
	cin >> n;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	virus(0);
	cout << num << endl;
	
	return 0;
}