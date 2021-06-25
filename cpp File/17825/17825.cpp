#include<iostream>

using namespace std;

struct STATE             // �����ӿ� ���� ������ �޾ƿ��� ����ü
{
	int prev;            // ���� ĭ
	int next;            // �̵��Ϸ��� ĭ
	int start_circle;    // ������ �Ķ����� ��ȣ(1, 2, 3 �� �ϳ�)
	bool select_circle;  // �̹� ���������� �Ķ��� ���� ��ȣ�� �����Ǿ������� ���� �����Ǵ�
	bool finish;         // �̹� ���������� ���� �������� �����Ͽ������� ���� �����Ǵ�
};

struct YUT
{
	int blue_circle;     // ���� �ѹ��̶� ������ �Ķ��� ���� ��ȣ
	int pos;             // ���� ����
	int score;           // ���� ����
	bool finish;         // ���� �������� �����ߴ����� ���� ����
};

int ans;
int cmd[10];
int move_num[4];         // �� ��� ��, �������� �ϴ� �ִ� ĭ���� �����ϴ� �迭
int MAP_Score[4][30];    // ���� ��
bool visited[4][30];     // �̹� �ٸ� ���� �ִ��� ������ �Ǵ��ϱ� ���� �迭
bool spc_point[4][30];   // Ư���� �� (��� ��ΰ� ��ġ�� ĭ��)

YUT Yut[4];

void setting()
{
	/* ���� ���� �۾� */
	/*
	1. �� ��� �� �������� �ϴ� �ִ� ĭ���� �����ϴ� �迭 Move_Num�� �� ����.
	2. Ư���� ���� üũ.
	3. ���� �� �����
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

	int prev = Yut[idx].pos;                 // ���� ��ġ
	int next = Yut[idx].pos + cmd[c_idx];    // �̵��� ��ġ
	int start_circle = Yut[idx].blue_circle; // �ش� �� ���� �Ķ��� ��
	bool select_circle = false;              // �̹� ���� ���������� ���� �Ķ��� ���� �����Ǿ������� ���� ����
	bool finish = false;                     // �̹� ���� ���������� ���� �������� �����ߴ����� ���� ����

	if (start_circle == 0)                   // ���� ������ �Ķ��� ���� ���� ��쿡��
	{
		if (prev == 5 || prev == 10 || prev == 15) // �Ķ��� ������ �����Ѵٸ�
		{
			select_circle = true;            // �̹� ���� ���������� �Ķ��� ���� �����Ǿ���.
			start_circle = prev / 5;         // ���� ������ �Ķ��� ���� ��ȣ
		}
	}

	if (next >= move_num[start_circle]) finish = true; // �������� �����ߴٸ� üũ.

	s_temp.prev = prev;
	s_temp.next = next;
	s_temp.start_circle = start_circle;
	s_temp.select_circle = select_circle;
	s_temp.finish = finish;

	return s_temp;
}

bool check_spc_point(int circle, int pos)
{
	/* Ư���� ���� �ٸ� ���� �����ϴ��� �Ǵ��ϴ� �Լ� */
	if (circle == 0)
	{
		/* ���� �̵��Ϸ��� ���� �Ķ��� ������ ������ ���� ���� ���. */
		/* '40'���� �����Ǿ��ִ� ĭ�� ������ ���� �ִ��� �Ǵ��� �ָ� �ȴ�.
		/* '40'���� �ִ� ĭ��, ������, �Ķ���, �ʷϻ�, ��Ȳ�� ��� ��ġ�� ����̱� ���� ! */
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
		/* ���� ����, 1�� �Ķ� ������ �����ؼ� �����̰� �ִ� ��� */
		/* ������ / �Ķ��� / ��Ȳ�� ��ΰ� ��ġ�� "25", "30", "35", "40" �� üũ�� �־�� �Ѵ�. */
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
	/* ���� ���� ������ �� �ִ����� �Ǵ����ִ� �Լ� */
	/* �Ǵ��� ��� �� ��
	1. �����̷��� ��ǥ�� Ư���� ������ ?
	- Ư���� ���̶�� �ٸ� ��θ� ���ؼ� �ش� ��ǥ�� �ִ� ��鵵 Check.
	2. �����̷��� ��ǥ�� �ٸ� ���� �����ϴ��� ?
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
	/* ������ ���� �ű�� �Լ�. */
	/* T = true �� ���, �湮 üũ */
	/* T = false �� ���, �湮 üũ ��� */

	if (T == true)
	{
		if (S.finish == true)
		{
			/* ���� ���� ���������� ���� �������� �����ߴٸ� ?? */

			visited[S.start_circle][S.prev] = false;   // ���� ��ǥ �湮 üũ ����
			Yut[idx].pos = S.next;                     // ���� ���� ��ǥ ����
			Yut[idx].finish = true;                    // �������� ǥ��.
													   // ������ ��ǥ�� ���� �־ �ٸ� ���� �� �� �ֱ� ������, �ش� ��ǥ�� �湮ǥ�ô� ���� ���� ! 
		}
		else
		{
			/* ���� ���� ���������� ���� �������� ���������� ���� ��� */
			if (S.select_circle == true)
			{
				/* ���� ���� ���������� �Ķ����� ��ȣ�� ���� �Ǿ��ٸ� ?*/

				Yut[idx].blue_circle = S.start_circle; // ���� �Ķ� ���� ��ȣ�� ����
				visited[0][S.prev] = false;            // ������ ��ǥ üũ ����.
													   // �̹� �Ͽ� �Ķ����� ��ȣ�� �����Ǿ��� = �������� �Ķ����� �������� ���� ���¿���.
													   // ��, ������ ��ǥ üũ ������ �Ķ����� �������� ���� Visit[0][S.prev]�� ���ش�.
			}
			else
			{
				/* ���� ���� ���������� �Ķ����� ��ȣ�� �������� �ʾҴ�. */
				/* �̹� �������־��� ����, �ƴϸ� ���� �������� ���� ���ϼ��� �ִ�. */

				visited[Yut[idx].blue_circle][S.prev] = false;
				/* ������ ��ǥ üũ ����. �Ķ����� ������ ���������� ���� �������������� ������
				�̹� �Ͽ� ���������� �ʾ����ϱ�, Yut[idx].blue_circle �� �Ķ����� ��ȣ�� ��ü */
			}

			visited[Yut[idx].blue_circle][S.next] = true;    // �湮 üũ
			Yut[idx].pos = S.next;                           // ��ǥ����
			Yut[idx].score = Yut[idx].score + MAP_Score[Yut[idx].blue_circle][S.next]; // ��������
		}
	}
	else
	{
		/* ���� ����ϴ� ���� */
		if (S.finish == true)
		{
			/* �̹� ������ ���� �������� �����ߴٸ� ? */
			visited[S.start_circle][S.prev] = true;    // ������ ��ǥ �湮 üũ
			Yut[idx].pos = S.prev;                     // ��ǥ�� �ǵ�����
			Yut[idx].finish = false;                   // ����ǥ�� ����
		}
		else
		{
			if (S.select_circle == true)
			{
				/* �̹� ������ ���ؼ� �Ķ��� ���� ���� �Ǿ��µ�, �̸� ������� �Ѵ�. */

				visited[0][S.prev] = true;             // �������� ���� �Ķ����� ������ ���� �ʾҴµ�, �� ��ǥ�� ���ư��� �ϹǷ� Visit[0][S.prev]
				visited[Yut[idx].blue_circle][S.next] = false;
				Yut[idx].pos = S.prev;
				Yut[idx].score = Yut[idx].score - MAP_Score[Yut[idx].blue_circle][S.next];
				Yut[idx].blue_circle = 0;              // ������ �Ķ����� ��ȣ �ٽ� 0���� ����.
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