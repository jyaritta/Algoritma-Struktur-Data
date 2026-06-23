#include <iostream>

using namespace std;

struct State {
    int r, c, dist;
};

State q[10005];
int head = 0; 
int tail = 0;

void push(int r, int c, int d) {
    q[tail].r = r;
    q[tail].c = c;
    q[tail].dist = d;
    tail++;
}

State pop() {
    State s = q[head];
    head++;
    return s;
}

bool isEmpty() {
    return head == tail;
}

int grid[101][101];
bool visited[101][101];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    int SR, SC, FR, FC;
    cin >> SR >> SC;
    cin >> FR >> FC;

    push(SR, SC, 0);
    visited[SR][SC] = true;

    int ans = -1;

    while (!isEmpty()) {
        State curr = pop(); 

        if (curr.r == FR && curr.c == FC) {
            ans = curr.dist;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (grid[nr][nc] == 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    push(nr, nc, curr.dist + 1);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}