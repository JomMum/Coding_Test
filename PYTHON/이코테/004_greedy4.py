n, k = map(int, input().split())
result = 0

while n != 1:
    # 나누어 떨어질 시 k로 나누기
    if n % k == 0:
        n /= k
    # 아닐 시 1 빼기
    else:
        n -= 1

    result += 1

print(result)