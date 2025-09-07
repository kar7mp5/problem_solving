import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
space = [list(map(int, input().split())) for _ in range(n)]

shark_x, shark_y = 0, 0
shark_size = 2
eat_count = 0
total_time = 0

for i in range(n):
    for j in range(n):
        if space[i][j] == 9:
            shark_x, shark_y = i, j
            space[i][j] = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def find_fish(x, y, size):
    q = deque([(0, x, y)])
    visited = [[False] * n for _ in range(n)]
    visited[x][y] = True
    
    edible_fish = []

    while q:
        dist, cur_x, cur_y = q.popleft()

        for i in range(4):
            nx, ny = cur_x + dx[i], cur_y + dy[i]

            if 0 <= nx < n and 0 <= ny < n:
                if not visited[nx][ny]:
                    if space[nx][ny] <= size:
                        visited[nx][ny] = True
                        q.append((dist + 1, nx, ny))
                        
                        if 0 < space[nx][ny] < size:
                            edible_fish.append((dist + 1, nx, ny))
                            
    if edible_fish:
        edible_fish.sort()
        return edible_fish[0]
    else:
        return None

while True:
    target_fish = find_fish(shark_x, shark_y, shark_size)

    if target_fish is None:
        break
    
    dist, fish_x, fish_y = target_fish
    
    shark_x, shark_y = fish_x, fish_y
    total_time += dist
    
    space[fish_x][fish_y] = 0
    eat_count += 1
    
    if eat_count == shark_size:
        shark_size += 1
        eat_count = 0

print(total_time)