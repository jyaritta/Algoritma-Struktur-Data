#include "single_linked_list.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    SingleLinkedList sll;
    sll.init();

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        sll.add_back(val);
    }

    int k_awal = k;
    int current_idx = 0; 

    while (sll.size > 1) {
        current_idx = (current_idx + k - 1) % sll.size;

        int batu_hancur = sll.get(current_idx);
        sll.delete_idx(current_idx);

        if (batu_hancur % 2 == 0) {
            k++;
        } else {
            k--;
        }

        if (k <= 0) {
            k = k_awal;
        }
    }

    cout << sll.get(0) << "\n";
    sll.clear(); 
    return 0;
}