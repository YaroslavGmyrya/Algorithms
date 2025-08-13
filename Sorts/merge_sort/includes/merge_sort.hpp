#pragma once
#include <vector>
#include <concepts>

enum sort_type { ASCENDING, DESCENDING };

// concept comparison = requires(T data, T buffer) {
//     { data < buffer } -> std::convertible_to<bool>;
// };

template <typename T>
void merge_increase(std::vector<T> &data, int start, int mid, int end) {
    std::vector<T> buffer;
    for(int i = start; i <= end; ++i) {
        buffer.push_back(data[i]);
    }

    int left = start;
    int right = mid + 1;
    int i = start;

    while(left <= mid && right <= end) {
        if(buffer[left - start] < buffer[right - start]) {
            data[i] = buffer[left - start];
            ++left;
        } else {
            data[i] = buffer[right - start];
            ++right;
        }
        ++i;
    }

    while(left <= mid) {
        data[i] = buffer[left - start];
        ++left;
        ++i;
    }

    while(right <= end) {
        data[i] = buffer[right - start];
        ++right;
        ++i;
    }
}

template <typename T>
void merge_decrease(std::vector<T> &data, int start, int mid, int end) {
    std::vector<T> buffer;
    for(int i = start; i <= end; ++i) {
        buffer.push_back(data[i]);
    }

    int left = start;
    int right = mid + 1;
    int i = start;

    while(left <= mid && right <= end) {
        if(buffer[left - start] > buffer[right - start]) {
            data[i] = buffer[left - start];
            ++left;
        } else {
            data[i] = buffer[right - start];
            ++right;
        }
        ++i;
    }

    while(left <= mid) {
        data[i] = buffer[left - start];
        ++left;
        ++i;
    }

    while(right <= end) {
        data[i] = buffer[right - start];
        ++right;
        ++i;
    }
}

template <typename T>
void merge_sort(std::vector<T> &data, int start, int end, enum sort_type type) {
    if(start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    merge_sort(data, start, mid, type);
    merge_sort(data, mid + 1, end, type);

    if(type == ASCENDING) {
        merge_increase(data, start, mid, end);
    } else {
        merge_decrease(data, start, mid, end);
    }
}
