from collections import deque
import copy

table = []
temp_table = []
bomb = []
final_bomb = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
result = 0

def down():
    final_bomb.sort(key=lambda x:(x[0], x[1]))
    for i in range(len(final_bomb)):
        x, y = final_bomb.pop(0)
        for j in range(x, 0, -1):
            table[j][y] = table[j-1][y]
        table[0][y] = '.'

def change():
    for x, y in bomb:
        table[x][y] = '.'

def bfs(start_x, start_y, visited):
    count = 1
    queue = deque()
    queue.append((start_x, start_y))
    bomb.append([start_x, start_y])

    while queue:
        x, y = queue.popleft()
        visited[x][y] = True

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 12 and 0 <= ny < 6:
                if table[x][y] == table[nx][ny] and visited[nx][ny] == False:
                    queue.append((nx, ny))
                    bomb.append([nx, ny])
                    count += 1
                    visited[nx][ny] = True
    return count

# input
for i in range(12):
    table.append(list(input()))

# main
while True:
    temp_table = copy.deepcopy(table)

    for i in range(12):
        for j in range(6):
            if table[i][j] != ".":
                visited = [[False] * 6 for i in range(12)]
                count = bfs(i, j, visited)
                
                if count >= 4:
                    change()
                    final_bomb.extend(bomb)

                bomb.clear()

    if temp_table == table:
        break
    else:
        result += 1
        down()

print(result)