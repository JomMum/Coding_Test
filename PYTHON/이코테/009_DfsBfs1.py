## 음료수 얼려 먹기 ##

# N, M 입력
n, m = map(int, input().split())

# 얼음 틀 입력
frame = []
for i in range(n):
    frame.append(list(map(int, input())))

result = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 위치가 얼음틀을 벗어나는지 체크
def is_out_range(x, y):
    global n, m
    if x >= 0 and x < n and y >= 0 and y < m:
        return False
    else:
        return True

# 아이스크림 생성
def create_icecream(x, y):
    global frame
    frame[x][y] = 1 # 방문 처리
    # 동서남북 조회
    for i in range(4):
        target_x = x + dx[i]
        target_y = y + dy[i]
        # 만약 범위를 벗어나지 않았고, 목표 위치가 뚫린 부분일 시 탐색
        if is_out_range(target_x, target_y) == False:
            if frame[target_x][target_y] == 0:
                create_icecream(target_x, target_y)
    return

# 얼음틀에서 뚫린 부분 찾기
for i in range(n):
    for j in range(m):
        # 만약 뚫린 부분이 있을 시, 아이스크림 생성
        if frame[i][j] == 0:
            create_icecream(i, j)
            result += 1

print(result)
