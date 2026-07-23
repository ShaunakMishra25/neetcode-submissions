class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        def dfs(i, j):

            if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] !=  1:
                return 0

            grid[i][j] = 0
            
            area = 1 

            for di, dj in {(1, 0),(- 1, 0),(0, 1),(0, -1)}:
               area += dfs(i + di, j + dj)
            
            return area
            
        max_area = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                
                max_area = max(max_area, dfs(i, j))

        return max_area

