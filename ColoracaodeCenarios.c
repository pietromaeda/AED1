#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 1040

char matrix[MAX][MAX];

void bfs(int startX, int startY, int rows, int cols) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    matrix[startX][startY] = 'x';

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= rows && ny >= 1 && ny <= cols && matrix[nx][ny] == '.') {
                matrix[nx][ny] = 'x';
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int rows, cols, count = 0;
    scanf("%d %d", &rows, &cols);

    memset(matrix, '0', sizeof(matrix));

    for (int i = 1; i <= rows; ++i) {
        scanf("%s", &matrix[i][1]);
    }

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (matrix[i][j] == '.') {
                bfs(i, j, rows, cols);
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}