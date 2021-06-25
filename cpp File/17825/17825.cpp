#include<iostream>

using namespace std;

struct STATE             // 움직임에 대한 정보를 받아오는 구조체
{
	int prev;            // 현재 칸
	int next;            // 이동하려는 칸
	int start_circle;    // 시작한 파랑원의 번호(1, 2, 3 중 하나)
	bool select_circle;  // 이번 움직임으로 파랑색 원의 번호가 결정되었는지에 대한 여부판단
	bool finish;         // 이번 움직임으로 윷이 도착점에 도달하였는지에 대한 여부판단
};

struct YUT
{
	int blue_circle;     // 윷이 한번이라도 시작한 파랑색 원의 번호
	int pos;             // 윷의 정보
	int score;           // 윷의 점수
	bool finish;         // 윷이 도착점에 도달했는지에 대한 여부
};

int ans;
int cmd[10];
int move_num[4];         // 각 경로 별, 움직여야 하는 최대 칸수를 저장하는 배열
int MAP_Score[4][30];    // 점수 판
bool visited[4][30];     // 이미 다른 윷이 있는지 없는지 판단하기 위한 배열
bool spc_point[4][30];   // 특별한 점 (모든 경로가 겹치는 칸들)

YUT Yut[4];

void setting()
{
	/* 기초 세팅 작업 */
	/*
	1. 각 경로 별 움직여야 하는 최대 칸수를 저장하는 배열 Move_Num에 값 삽입.
	2. 특별한 점들 체크.
	3. 점수 판 만들기
	*/
	move_num[0] = 21;
	move_num[1] = 13;
	move_num[2] = 17;
	move_num[3] = 23;

	spc_point[1][9] = spc_point[1][10] = spc_point[1][11] = spc_point[1][12] = true;
	spc_point[2][13] = spc_point[2][14] = spc_point[2][15] = spc_point[2][16] = true;
	spc_point[3][19] = spc_point[3][20] = spc_point[3][21] = spc_point[3][22] = true;
	spc_point[0][1] = spc_point[0][2] = spc_point[0][3] = spc_point[0][4] = spc_point[0][5] = spc_point[0][20] = true;

	for (int i = 1; i <= 20; i++)
	{
		MAP_Score[0][i] = 2 * i;
	}

	MAP_Score[1][6] = 13;
	MAP_Score[1][7] = 16;
	MAP_Score[1][8] = 19;
	MAP_Score[1][9] = 25;
	MAP_Score[1][10] = 30;
	MAP_Score[1][11] = 35;
	MAP_Score[1][12] = 40;

	MAP_Score[2][11] = 22;
	MAP_Score[2][12] = 24;
	MAP_Score[2][13] = 25;
	MAP_Score[2][14] = 30;
	MAP_Score[2][15] = 35;
	MAP_Score[2][16] = 40;

	MAP_Score[3][16] = 28;
	MAP_Score[3][17] = 27;
	MAP_Score[3][18] = 26;
	MAP_Score[3][19] = 25;
	MAP_Score[3][20] = 30;
	MAP_Score[3][21] = 35;
	MAP_Score[3][22] = 40;

	for (int i = 1; i <= 5; i++)
	{
		MAP_Score[1][i] = MAP_Score[0][i];
	}

	for (int i = 1; i <= 10; i++)
	{
		MAP_Score[2][i] = MAP_Score[0][i];
	}

	for (int i = 1; i <= 15; i++)
	{
		MAP_Score[3][i] = MAP_Score[0][i];
	}
}

STATE get_state(int idx, int c_idx)
{
	STATE s_temp;

	int prev = Yut[idx].pos;                 // 현재 위치
	int next = Yut[idx].pos + cmd[c_idx];    // 이동할 위치
	int start_circle = Yut[idx].blue_circle; // 해당 윷 관련 파랑색 원
	bool select_circle = false;              // 이번 턴의 움직임으로 인해 파랑색 원이 결정되었는지에 대한 여부
	bool finish = false;                     // 이번 턴의 움직임으로 인해 도착점에 도달했는지에 대한 여부

	if (start_circle == 0)                   // 아직 시작한 파랑색 원이 없을 경우에만
	{
		if (prev == 5 || prev == 10 || prev == 15) // 파랑색 원에서 시작한다면
		{
			select_circle = true;            // 이번 턴의 움직임으로 파랑색 원이 결정되었다.
			start_circle = prev / 5;         // 윷의 시작한 파랑색 원의 번호
		}
	}

	if (next >= move_num[start_circle]) finish = true; // 도착점에 도달했다면 체크.

	s_temp.prev = prev;
	s_temp.next = next;
	s_temp.start_circle = start_circle;
	s_temp.select_circle = select_circle;
	s_temp.finish = finish;

	return s_temp;
}

bool check_spc_point(int circle, int pos)
{
	/* 특별한 점에 다른 윷이 존재하는지 판단하는 함수 */
	if (circle == 0)
	{
		/* 현재 이동하려는 윷이 파랑색 원에서 시작한 적이 없는 경우. */
		/* '40'점이 설정되어있는 칸에 기존에 윷이 있는지 판단해 주면 된다.
		/* '40'점이 있는 칸은, 빨강색, 파랑색, 초록색, 주황색 모두 겹치는 경로이기 때문 ! */
		if (pos == 20)
		{
			if (visited[1][12] == true || visited[2][16] == true || visited[3][22] == true) return false;
		}
		else
		{
			if (visited[0][pos] == true) return false;
		}
	}
	else if (circle == 1)
	{
		/* 현재 윷이, 1번 파랑 원에서 시작해서 움직이고 있는 경우 */
		/* 빨강색 / 파랑색 / 주황색 경로가 겹치는 "25", "30", "35", "40" 을 체크해 주어야 한다. */
		if (visited[2][pos + 4] == true || visited[3][pos + 10] == true) return false;
		if (pos == 12)
		{
			if (visited[0][20] == true) return false;
		}
	}
	else if (circle == 2)
	{
		if (visited[1][pos - 4] == true || visited[3][pos + 6] == true) return false;
		if (pos == 16)
		{
			if (visited[0][20] == true) return false;
		}
	}
	else if (circle == 3)
	{
		if (visited[1][pos - 10] == true || visited[2][pos - 6] == true) return false;
		if (pos == 22)
		{
			if (visited[0][20] == true) return false;
		}
	}
	return true;
}

bool check_visit(STATE S, int idx)
{
	/* 현재 윷이 움직일 수 있는지를 판단해주는 함수 */
	/* 판단해 줘야 할 것
	1. 움직이려는 좌표가 특별한 점인지 ?
	- 특별한 점이라면 다른 경로를 통해서 해당 좌표에 있는 놈들도 Check.
	2. 움직이려는 좌표에 다른 윷이 존재하는지 ?
	*/
	if (spc_point[S.start_circle][S.next] == true)
	{
		if (check_spc_point(S.start_circle, S.next) == false) return false;
	}

	if (visited[S.start_circle][S.next] == true) return false;
	
	return true;
}

void make_state(STATE S, int idx, bool T)
{
	/* 실제로 윷을 옮기는 함수. */
	/* T = true 일 경우, 방문 체크 */
	/* T = false 일 경우, 방문 체크 취소 */

	if (T == true)
	{
		if (S.finish == true)
		{
			/* 현재 턴의 움직임으로 윷이 도착점에 도달했다면 ?? */

			visited[S.start_circle][S.prev] = false;   // 기존 좌표 방문 체크 해제
			Yut[idx].pos = S.next;                     // 현재 윷의 좌표 갱신
			Yut[idx].finish = true;                    // 끝났음을 표시.
													   // 마지막 좌표는 윷이 있어도 다른 윷이 올 수 있기 때문에, 해당 좌표에 방문표시는 하지 않음 ! 
		}
		else
		{
			/* 현재 턴의 움직임으로 윷이 도착점에 도달하지는 않은 경우 */
			if (S.select_circle == true)
			{
				/* 현재 턴의 움직임으로 파랑원의 번호가 결정 되었다면 ?*/

				Yut[idx].blue_circle = S.start_circle; // 윷의 파랑 원의 번호를 설정
				visited[0][S.prev] = false;            // 기존의 좌표 체크 해제.
													   // 이번 턴에 파랑원의 번호가 결정되었다 = 기존에는 파랑원이 결정되지 않은 상태였다.
													   // 즉, 기존의 좌표 체크 해제는 파랑원이 결정되지 않은 Visit[0][S.prev]로 해준다.
			}
			else
			{
				/* 현재 턴의 움직임으로 파랑원의 번호가 결정되지 않았다. */
				/* 이미 정해져있었을 수도, 아니면 아직 정해지지 않은 것일수도 있다. */

				visited[Yut[idx].blue_circle][S.prev] = false;
				/* 기존의 좌표 체크 해제. 파랑원이 기존에 정해졌는지 아직 안정해졌는지는 모르지만
				이번 턴에 결정되지는 않았으니까, Yut[idx].blue_circle 로 파랑원의 번호를 대체 */
			}

			visited[Yut[idx].blue_circle][S.next] = true;    // 방문 체크
			Yut[idx].pos = S.next;                           // 좌표갱신
			Yut[idx].score = Yut[idx].score + MAP_Score[Yut[idx].blue_circle][S.next]; // 점수갱신
		}
	}
	else
	{
		/* 실행 취소하는 과정 */
		if (S.finish == true)
		{
			/* 이번 턴으로 윷이 도착점에 도달했다면 ? */
			visited[S.start_circle][S.prev] = true;    // 기존의 좌표 방문 체크
			Yut[idx].pos = S.prev;                     // 좌표값 되돌리기
			Yut[idx].finish = false;                   // 끝남표시 해제
		}
		else
		{
			if (S.select_circle == true)
			{
				/* 이번 턴으로 인해서 파랑색 원이 결정 되었는데, 이를 실행취소 한다. */

				visited[0][S.prev] = true;             // 기존에는 아직 파랑원이 정해져 있지 않았는데, 그 좌표로 돌아가야 하므로 Visit[0][S.prev]
				visited[Yut[idx].blue_circle][S.next] = false;
				Yut[idx].pos = S.prev;
				Yut[idx].score = Yut[idx].score - MAP_Score[Yut[idx].blue_circle][S.next];
				Yut[idx].blue_circle = 0;              // 선택한 파랑원의 번호 다시 0으로 갱신.
			}
			else
			{
				visited[Yut[idx].blue_circle][S.prev] = true;
				visited[Yut[idx].blue_circle][S.next] = false;
				Yut[idx].pos = S.prev;
				Yut[idx].score = Yut[idx].score - MAP_Score[Yut[idx].blue_circle][S.next];
			}
		}
	}
}

void DFS(int cnt)
{
	if (cnt == 10)
	{
		int temp = 0;

		for (int i = 0; i < 4; i++)
		{
			temp += Yut[i].score;
		}

		if (ans < temp) ans = temp;

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (Yut[i].finish == true) continue;
		STATE state = get_state(i, cnt);
		if (check_visit(state, i) == false) continue;

		make_state(state, i, true);
		DFS(cnt + 1);
		make_state(state, i, false);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	setting();

	for (int i = 0; i < 10; i++)
	{
		cin >> cmd[i];
	}

	DFS(0);

	cout << ans << "\n";

	return 0;
}