def solution(s):
    answer = 1
    left = 0
    right = 0
    for mid in range(1, len(s) - 1):
        temp = 1
        left = mid - 1
        right = mid + 1
        while right < len(s) and left >= 0:        
            if s[left] == s[right]:
                temp += 2
                left -= 1
                right += 1
            else:
                break
        if temp > answer:        
            answer = temp
        
    for midLeft in range(len(s) - 1):
        if s[midLeft] == s[midLeft + 1]:
            temp = 2
            left = midLeft - 1
            right = midLeft + 2
            while right < len(s) and left >= 0:
                if s[left] == s[right]:
                    temp += 2
                    left -= 1
                    right += 1
                else:
                    break
            if temp > answer:
                answer = temp

    return answer