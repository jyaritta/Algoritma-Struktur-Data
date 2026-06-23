#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0; 

    Stack memory;
    init(&memory);

    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int A2 = peek(&memory); 
            pop(&memory);
            
            int A1 = peek(&memory); 
            pop(&memory);
            
            int hasil = 0;

            if (token == "+") {
                hasil = A1 + A2;
            } else if (token == "-") {
                hasil = A1 - A2;
            } else if (token == "*") {
                hasil = A1 * A2;
            } else if (token == "/") {
                hasil = A1 / A2; 
            }

            push(&memory, hasil);
            
        } else {
            push(&memory, stoi(token));
        }
    }

    cout << peek(&memory) << endl;

    return 0;
}
