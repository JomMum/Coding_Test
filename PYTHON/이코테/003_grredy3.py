n, m = map(int, input().split())
result = 0

for i in range(n):
    # 2차원 배열 형태로 cards 값 받기
    cards = list(map(int, input().split()))
    min_value = min(cards)

    # 최솟값들 중 가장 큰 값 저장
    result = max(result, min_value)

print(result)