n = int(input())
board = [list(input().strip()) for _ in range(n)]
def line_check(b, idx, is_row):
    max_num, num = 1, 1
    for j in range(1, n):
        if is_row:  num = num + 1 if b[idx][j-1] == b[idx][j] else 1
        else:       num = num + 1 if b[j-1][idx] == b[j][idx] else 1
        max_num = max(num, max_num)
    return max_num

res = 0
for i in range(n):
    for j in range(n-1):
        board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
        res = max(res, line_check(board, j, is_row=False), line_check(board, j+1, is_row=False), line_check(board, i, is_row=True))
        board[i][j], board[i][j+1] = board[i][j+1], board[i][j]

        board[j][i], board[j+1][i] = board[j+1][i], board[j][i]
        res = max(res, line_check(board, j, is_row=True), line_check(board, j+1, is_row=True), line_check(board, i, is_row=False))
        board[j][i], board[j+1][i] = board[j+1][i], board[j][i]
print(res)

