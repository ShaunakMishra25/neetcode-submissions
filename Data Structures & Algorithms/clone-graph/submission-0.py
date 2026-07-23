from typing import Optional
from collections import deque

class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        old_to_new = {}

        def clone(node):
            if node in old_to_new:
                return old_to_new[node]

            cp = Node(node.val)
            old_to_new[node] = cp

            for nei in node.neighbors:
                cp.neighbors.append(clone(nei))

            return cp

        return clone(node) if node else None