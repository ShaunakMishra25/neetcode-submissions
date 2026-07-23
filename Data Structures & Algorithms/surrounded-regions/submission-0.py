class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        ROWS, COLS = len(board), len(board[0])

        def dfs(i , j):

            if i < 0 or i >= ROWS or j < 0 or j >= COLS or board[i][j] != 'O':
                return

            board[i][j] = 'T'

            for di, dj in {(1,0), (-1, 0), (0, 1), (0, -1)}:
                dfs(i + di, j + dj)

            
        for i in range(ROWS):
            for j in range(COLS):
                if board[i][j] == 'O' and (i in [0, ROWS -1] or j in [0, COLS - 1]):
                    dfs(i, j)


        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == 'O':
                    board[r][c] = 'X'

        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == 'T':
                    board[r][c] = 'O'

                
