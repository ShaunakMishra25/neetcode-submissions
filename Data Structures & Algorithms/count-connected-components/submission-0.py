class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = {i : [] for i in range(n)}

        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        visited = set()

        def dfs(node):

            visited.add(node)

            for nei in adj[node]:
                if nei not in visited :
                    dfs(nei)
            
        comp = 0

        for node in range(n):
            if node not in visited:
                comp += 1

                dfs(node)
            
        return comp