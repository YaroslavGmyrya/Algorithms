#pragma once
#include <vector>
#include <concepts>

enum sort_type { ASCENDING, DESCENDING };

template <typename T>
concept comparison = requires(T data, T b) {
    { data < b } -> std::convertible_to<bool>;
};

template <comparison T>
void insert_sort_increase(std::vector<T> &data){

    if(data.empty())
        return;

    T tmp;
    int j;

    for(int i = 1; i < data.size(); ++i){
        tmp = data[i];
        j = i - 1;

        while(j >= 0 && data[j] > tmp){
            data[j + 1] = data[j];
            j--; 
        }

        data[j + 1] = tmp;
    }
}

template <comparison T>
void insert_sort_decrease(std::vector<T> &data){

     if(data.empty())
        return;

    T tmp;
    int j;

    for(int i = 1; i < data.size(); ++i){
        tmp = data[i];
        j = i - 1;

        while(j >= 0 && data[j] < tmp){
            data[j + 1] = data[j];
            j--; 
        }

        data[j + 1] = tmp;
    }
}

template <comparison T>
void insert_sort(std::vector<T> &data, enum sort_type type){
    switch(type){
        case 0:
            insert_sort_increase(data);
            break;
        
        case 1:
            insert_sort_decrease(data);
            break;
    }
}