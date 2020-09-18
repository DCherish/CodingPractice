#include <iostream>
#include <vector>	
#include <math.h>
#include <queue>

using namespace std;

int D, G, DU;

int N;
//int visit[300001];
bool b[300001];
vector<int> map[300001];

//void bfs() {
//	queue<int> q;
//
//	q.push(1);
//	visit[1] = 1;
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		for (int i = 0; i < map[cur].size(); i++) {
//			if (visit[map[cur][i]] != 0)continue;
//			visit[map[cur][i]] = visit[cur] + 1;
//			q.push(map[cur][i]);
//		}
//	}
//}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int src, dst;
		cin >> src >> dst;
		map[src].push_back(dst);
		map[dst].push_back(src);
	}

	int cntG = 0, cntD = 0;

	for (int i = 1; i <= N; i++) // cnt ¤¸
	{
		if (map[i].size() == 3)
		{
			cntG += 1;
		}
		else if (map[i].size() > 3)
		{
			int total_up = 1;
			int total_down = 1;

			for (int j = 1; j <= map[i].size(); j++)
			{
				total_up *= j;
			}

			int r = map[i].size() - 3;
			for (int j = 1; j <= r; j++)
			{
				total_down *= j;
			}
			total_down *= 6;
			cntG += total_up / total_down;
		}
	}

	//bfs();

	for (int i = 1; i <= N; i++) { //cnt ¤§
		if (map[i].size() < 2)continue;	
		if (b[i] == true)continue;
		for (int j = 0; j < map[i].size(); j++) {
			if (map[map[i][j]].size() < 2)continue;
			//if (b[map[i][j]] == true)continue;
			cntD += (map[map[i][j]].size()-1)* (map[i].size()-1);
			b[map[i][j]] = true;
			break;
		}
	}


	//cout << cntD << " " << cntG << endl;
	cntG *= 3;
	if (cntD > cntG) {
		cout << "D";
	}
	else if (cntD < cntG) {
		cout << "G";
	}
	else {
		cout << "DUDUDUNGA";
	}

	//cout << visit[1];
	return 0;
}