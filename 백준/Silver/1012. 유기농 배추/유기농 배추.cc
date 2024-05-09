#include<iostream>
#include<string.h>

int map[50][50], m, n;

int dfs(int x, int y) {
    map[x][y] = 0;

    if (x + 1 < m && map[x + 1][y] == 1) dfs(x + 1, y);
    if (x - 1 >= 0 && map[x - 1][y] == 1) dfs(x - 1, y);
    if (y + 1 < n && map[x][y + 1] == 1) dfs(x, y + 1);
    if (y - 1 >= 0 && map[x][y - 1] == 1) dfs(x, y - 1);
    return 0;
}

int main() {
    int t;

    std::cin >> t;

    int k, x, y, cnt;

    for (int test_case = 0; test_case < t; test_case++) {
        memset(map, 0, sizeof(map));
        std::cin >> m >> n >> k;

        while (k--) {
            std::cin >> x >> y;
            map[x][y] = 1;
        }

        cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        std::cout << cnt << "\n";
    }
    return 0;
}