#pragma once
#include <vector>
#include <concepts>

enum sort_type { ASCENDING, DESCENDING };

template <typename T>
int partition(std::vector<T> &data, int start, int end) {
    T pivot = data[end];

    int i = start;

    for(int j = start; j < end; ++j){
        if(data[j] < pivot){
            std::swap(data[i], data[j]);
            i += 1;
        }
    }

    std::swap(data[i], data[end]);

    return i;
}

template <typename T>
void heap_sort(std::vector<T> &data, int start, int end, enum sort_type type) {
    
}
