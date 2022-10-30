# N, M 입력
n, m = map(int, input().split())

# 플레이어 x 좌표, y 좌표, 방향 입력
# x, y를 반대로 받는 이유: 맵 정보를 리스트로 받으면 첫 번째 인덱스가 세로, 두 번째 인덱스가 가로로 저장되기 때문
y, x, direction = map(int, input().split())

# 전체 맵 정보 입력
map_info = []
for i in range(n):
    map_info.append(list(map(int, input().split())))

# 북, 동, 남, 서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 시작 위치는 탐사 완료로 지정
result = 1
map_info[x][y] = 2

# 왼쪽으로 회전
def turn_left():
    global direction
    if direction == 0:
        direction = 3
    else:
        direction -= 1

doNotMove = [False, False, False, False]

while True:
    # 목표 위치 구하기
    turn_left() # 왼쪽 회전
    nx = x + dx[direction]
    ny = y + dy[direction] 

    # 만약 목표 위치가 육지일 시
    if map_info[nx][ny] == 0:
        x, y = nx, ny # 목표 위치로 이동
        map_info[nx][ny] = 2 # 해당 위치를 탐사 완료로 변경
        result += 1

    # 4방향 중 이동 가능한 구역 찾기
    for i in range(len(dx)):
        target_x = x + dx[i]
        target_y = y + dy[i]

        if map_info[target_x][target_y] == 0:
            doNotMove[i] = False
        else:
            doNotMove[i] = True

    # 4방향 모두 이동 불가 시 종료
    if doNotMove[0] and doNotMove[1] and doNotMove[2] and doNotMove[3]:
        target_x = x + dx[i] * -1
        target_y = y + dy[i] * -1
        if map_info[target_x][target_y] == 0:
            x, y = target_x, target_y
        else:
            break

print(result)
