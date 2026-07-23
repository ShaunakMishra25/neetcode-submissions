"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        copyList = Node(0); pointer = copyList
        memo = {}
        while head:
            node = memo.get(head, None)
            if not node:
                node = Node(head.val)
                memo[head] = node
            random = memo.get(head.random, None)
            if head.random:
                if not random: 
                    random = Node(head.random.val)
                    memo[head.random] = random
                node.random = random
            copyList.next = node
            head = head.next
            copyList = copyList.next
        return pointer.next
