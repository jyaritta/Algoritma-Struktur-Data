#include <iostream>

using namespace std;

struct Labirin {
    int grid[10][10];
    bool visited[10][10];
    int R, C;
    int FR, FC;
    int total_jalur;
};

void dfs(Labirin& map, int r, int c) {
    if (r == map.FR && c == map.FC) {
        map.total_jalur++;
        return;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < map.R && nc >= 0 && nc < map.C) {
            if (map.grid[nr][nc] == 0 && !map.visited[nr][nc]) {
                map.visited[nr][nc] = true;
                dfs(map, nr, nc);
                map.visited[nr][nc] = false; 
            }
        }
    }
}

int main() {
    Labirin map;
    map.total_jalur = 0;
    cin >> map.R >> map.C;

    for (int i = 0; i < map.R; i++) {
        for (int j = 0; j < map.C; j++) {
            cin >> map.grid[i][j];
            map.visited[i][j] = false;
        }
    }

    int SR, SC;
    cin >> SR >> SC;
    cin >> map.FR >> map.FC; 

    map.visited[SR][SC] = true;
    dfs(map, SR, SC);
    cout << map.total_jalur << "\n";
    return 0;
}