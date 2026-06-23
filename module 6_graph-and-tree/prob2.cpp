#include <iostream>

using namespace std;

int main() {
    int n;
   cin >> n; 

    char vertices[15];
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }

    int matrix[15][15];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Adjacency List:\n";
    
    for (int i = 0; i < n; i++) {
        cout << vertices[i] << " -> ";
        
        bool isFirst = true;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                if (!isFirst) {
                    cout << ", "; 
                }
                cout << "(" << vertices[j] << "," << matrix[i][j] << ")";
                isFirst = false;
            }
        }  
        if (isFirst) {
            cout << "-";
        }
        cout << "\n";
    }

    return 0;
}