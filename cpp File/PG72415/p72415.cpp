#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MAX 4
#define CARD_MAX 7

using namespace std;

struct info_xy
{
	int x;
	int y;
};

struct info_xyz
{
	int x;
	int y;
	int cnt;
};

vector<bool> selected(CARD_MAX, false);

vector<int> card;
vector<int> card_order;
vector<int> card_order_idx;
vector<info_xy> card_pos[CARD_MAX];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int BFS(int x, int y, int find_cnt, int order, int idx, vector<vector<int>> &MAP)
{
	if (find_cnt == 2) return 0;

	queue<info_xyz> Q;
	vector<vector<bool>> visited(MAP.size(), vector<bool>(MAP.size(), false));
	
    visited[x][y] = true;
    
	Q.push({ x, y, 0 });

	int cx = 0;
	int cy = 0;

	if (find_cnt == 0)
	{
		cx = card_pos[order][idx].x;
		cy = card_pos[order][idx].y;
	}
	else
	{
		cx = card_pos[order][!idx].x;
		cy = card_pos[order][!idx].y;
	}

	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int cnt = Q.front().cnt;
		Q.pop();

		if (x == cx && y == cy)
		{
			MAP[x][y] = 0;
			cnt += BFS(x, y, find_cnt + 1, order, idx, MAP);
            
			return cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = true;
			Q.push({ nx, ny, cnt + 1 });
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			while (true)
			{
				if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX)
				{
					nx -= dx[i];
					ny -= dy[i];
					break;
				}

				if (MAP[nx][ny] != 0) break;

				nx += dx[i];
				ny += dy[i];
			}

			if (visited[nx][ny]) continue;
			
            visited[nx][ny] = true;
			Q.push({ nx, ny, cnt + 1 });
		}
	}
}

void setting_final(int cnt, vector<vector<int>> &MAP, int r, int c, int &answer)
{
	if (cnt == card.size())
	{
		vector<vector<int>> T_MAP = MAP;

		int result = 0;
        
		int x = r;
		int y = c;

		for (int i = 0; i < card.size(); i++)
		{
			int order = card_order[i];
			int idx = card_order_idx[i];
            
			result += BFS(x, y, 0, order, idx, T_MAP);

			x = card_pos[order][!idx].x;
			y = card_pos[order][!idx].y;
		}

		answer = min(answer, result);
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		card_order_idx.push_back(i);
		setting_final(cnt + 1, MAP, r, c, answer);
		card_order_idx.pop_back();
	}
}

void setting(int cnt, vector<vector<int>> &MAP, int r, int c, int &answer)
{
	if (cnt == card.size())
	{
		setting_final(0, MAP, r, c, answer);
		return;
	}

	for (int i = 0; i < card.size(); i++)
	{
		if (selected[i]) continue;
		selected[i] = true;
		card_order.push_back(card[i]);
		setting(cnt + 1, MAP, r, c, answer);
		card_order.pop_back();
		selected[i] = false;
	}
}

void find_card_pos(vector<vector<int>> &board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == 0) continue;
            
			card_pos[board[i][j]].push_back({ i, j });
		}
	}
}

void find_card_idx(vector<vector<int>> &board)
{
	vector<bool> exist(CARD_MAX, false);

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == 0) continue;
            
			if (!exist[board[i][j]])
			{
				exist[board[i][j]] = true;
				card.push_back(board[i][j]);
			}
		}
	}
}

int solution(vector<vector<int>> board, int r, int c)
{
	int answer = INT_MAX;

	find_card_idx(board);
	find_card_pos(board);
    
	setting(0, board, r, c, answer);

	answer += (card.size() * 2);

	return answer;
}