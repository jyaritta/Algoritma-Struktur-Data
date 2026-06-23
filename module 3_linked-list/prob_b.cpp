#include "double_linked_list.h"
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R;
    if (!(cin >> N >> R)) return 0;

    DoubleLinkedList arena;
    arena.init(); 

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        arena.add_back(c);
    }

    Node* alpha = arena.head;
    Node* beta = arena.tail;

    for (int i = 0; i < R; i++) {
        long long X, Y;
        cin >> X >> Y;

        if (arena.is_empty()) break;

        int move_alpha = X % arena.size;
        int move_beta = Y % arena.size;

        for (long long j = 0; j < move_alpha; j++) alpha = alpha->next;
        for (long long j = 0; j < move_beta; j++) beta = beta->prev;

        if (alpha == beta) {
            Node* next_alpha = alpha->next;
            Node* prev_beta = beta->prev;

            int idx_hancur = 0;
            Node* curr = arena.head;
            while (curr != alpha) {
                curr = curr->next;
                idx_hancur++;
            }
            arena.delete_idx(idx_hancur);

            if (arena.is_empty()) break;

            alpha = next_alpha;
            beta = prev_beta;
            
        } else if (alpha->next == beta || beta->next == alpha) {
            char temp = alpha->data;
            alpha->data = beta->data;
            beta->data = temp;
        }
    }
    arena.display();
    arena.clear();
    return 0;
}