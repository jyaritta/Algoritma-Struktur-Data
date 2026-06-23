#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i=0; i < n-1; i++) {
        for (int j=0; j < n-i-1; j++) {
            m.comparisons++; 
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
            }
        }
    }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void selection_sort(std::vector<int>& data, Metrics& m){
    int n = data.size();
    auto start = Clock::now();

    for(int i = 0; i < n - 1; ++i){
        int min_idx = i;
        for(int j = i + 1; j < n; ++j){
            m.comparisons++;
            if(data[j]<data[min_idx]){
                min_idx = j;
            }
        }
        if (min_idx != i){
            std::swap(data[i], data[min_idx]);
            m.swaps++;
        }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
    }
}


void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

   for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;
        m.comparisons++;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            m.shifts++;
            j = j - 1;
            m.comparisons++;
        }
        data[j + 1] = key;
   }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


// merge =====================================================

void merge(std::vector<int>& data, int left, int mid, int right, Metrics& m){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = data[left + i];
    for (int j = 0; j < n2; j++) R[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        m.comparisons++; 
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){ data[k] = L[i]; i++; k++; }
    while (j < n2){ data[k] = R[j]; j++; k++; }
}

void divide(std::vector<int>& data, int left, int right, Metrics& m) {
    m.recursive_calls++;
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    divide(data, left, mid, m);
    divide(data, mid + 1, right, m);
    merge(data, left, mid, right, m);
}

void merge_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    if (n <= 1) return;

    auto start = Clock::now();
    divide(data, 0, n - 1, m);
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void partition(std::vector<int>& data, int low, int high, Metrics& m) {
    m.recursive_calls++;
    
    if (low >= high) return;

    int pivot = data[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        m.comparisons++;
        if (data[j] <= pivot){
            i++;
            std::swap(data[i], data[j]);
            m.swaps++;
        }
    }

    std::swap(data[i + 1], data[high]);
    m.swaps++;

    int pi = i + 1;

    partition(data, low, pi - 1, m);
    partition(data, pi + 1, high, m);
}

void quick_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    if (n <= 1) return;

    auto start = Clock::now();
    partition(data, 0, n - 1, m);
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

// radix ======================================================
int getMax(const std::vector<int>& data, int n, Metrics& m) {
    int mx = data[0];
    m.array_accesses++;
    for (int i = 1; i < n; i++) {
        if (data[i] > mx) {
            mx = data[i];
        }
    }
    return mx;
}

void countSort(std::vector<int>& data, int n, int exp, Metrics& m) {
    std::vector<int> output(n);
    int count[10] = { 0 };

    for (int i = 0; i < n; i++) {
        count[(data[i] / exp) % 10]++;
        m.array_accesses++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        m.array_accesses += 2;
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(data[i] / exp) % 10] - 1] = data[i];
        m.array_accesses += 2;
        
        count[(data[i] / exp) % 10]--;
         m.array_accesses++;
    }

    for (int i = 0; i < n; i++) {
        data[i] = output[i];
        m.array_accesses++;
    }
}

void radix_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    if (n <= 1) return;
    auto start = Clock::now(); 

    int max_val = getMax(data, n, m);

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countSort(data, n, exp, m);
    }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}