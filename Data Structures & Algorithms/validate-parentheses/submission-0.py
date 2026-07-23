class Solution:
    def isValid(self, s: str) -> bool:
        pair = {')': '(', '}': '{', ']': '['}
        stack=[]

        for ch in s:
            if ch in pair:
                top=stack.pop() if stack else '#'
                if pair[ch]!=top:
                    return False
            else:
                stack.append(ch)
        return not stack