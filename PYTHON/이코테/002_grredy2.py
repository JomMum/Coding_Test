# 배열 크기, 숫자가 더해지는 횟수, 연속해서 더해질 수 있는 최댓값
n, m, k = map(int, input().split())
# 자연수 배열
numbers = list(map(int, input().split()))

# 입력값을 내림차순으로 정렬, 가장 큰 수와 두 번째로 큰 수 저장
numbers.sort(reverse=True)
first_number = numbers[0]
second_number = numbers[1]

result = 0

# 가장 큰 수가 더해지는 횟수
count =  (m // (k + 1)) * k
count += m % (k + 1)

# 합 계산
result = 0
result += first_number * count
result += second_number * (m - count)

print(result)