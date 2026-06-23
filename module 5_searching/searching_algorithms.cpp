#include "searching_algorithms.h"
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void linear_search(const std::vector<int>& data, int target, Metrics& m) {
    m.reset();
    auto start = Clock::now();
    m.n = data.size();

    for (int i = 0; i < data.size(); i++) {
        m.comparisons++;
        if (data[i] == target) {
            m.found_index = i;
            break;
        }
    }
    m.time_us = std::chrono::duration<double, std::micro>(Clock::now() - start).count();
}


void binary_search(const std::vector<int>& data, int target, Metrics& m) {
    m.reset();
    m.n = data.size();
    auto start = Clock::now();
    
    int low = 0;
    int high = data.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        m.comparisons++;
        if (data[mid] == target) {
            m.found_index = mid;
            break;
        }
        if (data[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    m.time_us = std::chrono::duration<double, std::micro>(Clock::now() - start).count();
}