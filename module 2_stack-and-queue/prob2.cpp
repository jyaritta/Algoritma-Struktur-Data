#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    Queue window;
    init(&window);
    long long current_sum = 0; 
    int temp;

    for (int i = 0; i < k; i++) {
        cin >> temp;
        enqueue(&window, temp);
        current_sum += temp;
    }
    cout << current_sum;

    for (int i = k; i < n; i++) {
        cin >> temp;
        current_sum -= front(&window);
        dequeue(&window); 
        enqueue(&window, temp);
        current_sum += temp;
        cout << " " << current_sum;
    }
    cout << endl;
    return 0;
}
