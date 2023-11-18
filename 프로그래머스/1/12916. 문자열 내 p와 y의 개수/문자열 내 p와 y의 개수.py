import string
def solution(s):
    cnt = 0
    for i in s.upper():
        if i == 'P':
            cnt += 1
        elif i == 'Y':
            cnt -= 1
    return bool(not cnt)