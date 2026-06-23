#include <iostream>

using namespace std;

int getIndex(char v, char vertices[], int n) {
    for (int i = 0; i < n; i++) {
        if (vertices[i] == v) return i;
    }
    return -1; 
}

int main() {
    int n;
    cin >> n; 

    char vertices[15]; 
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }

    int m;
    cin >> m; 

    int matrix[15][15] = {0};

    for (int i = 0; i < m; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w; 

        matrix[getIndex(u, vertices, n)][getIndex(v, vertices, n)] = w;
    }
    
    cout << "Adjacency Matrix:\n  ";
    
    for (int i = 0; i < n; i++) {
        cout << vertices[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << vertices[i]; 
        for (int j = 0; j < n; j++) {
            cout << " " << matrix[i][j]; 
        }
        cout << "\n";
    }

    return 0;
}