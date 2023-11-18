def solution(n):
    for i in range(2, n+1):
        if (n-1) % i == 0:
            return i