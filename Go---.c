#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 501

char board[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

void dfs(int x, int y, char color, int N) {
    if (x < 1 || x > N || y < 1 || y > N || visited[x][y] || board[x][y] != color)
        return;

    visited[x][y] = 1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], color, N);
    }
}

int count_areas(char color, int N) {
    memset(visited, 0, sizeof(visited));
    int count = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == color && !visited[i][j]) {
                dfs(i, j, color, N);
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    memset(board, '.', sizeof(board));

    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        board[L][C] = 'B';
    }

    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        board[L][C] = 'W';
    }

    int black_areas = count_areas('B', N);
    int white_areas = count_areas('W', N);

    printf("%d %d\n", black_areas, white_areas);

    return 0;
}
