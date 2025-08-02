#pragma once
#include <vector>
#include <concepts>

enum sort_type { ASCENDING, DESCENDING };

template <typename T>
concept comparison = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

template <comparison T>
void buble_sort_increase(std::vector<T> &data){

    if(data.empty())
        return;

    bool swapped = true;
    T tmp;
    do{
        swapped = false;

        for(int i = 1; i < data.size(); ++i){
            if(data[i - 1] > data[i]){
                tmp = data[i - 1];
                data[i - 1] = data[i];
                data[i] = tmp;
                swapped = true;
            }
        }

    }while(swapped);
}

template <comparison T>
void buble_sort_decrease(std::vector<T> &data){

    if(data.empty())
        return;

    bool swapped = true;
    T tmp;
    do{
        swapped = false;

        for(int i = 1; i < data.size(); ++i){
            if(data[i - 1] < data[i]){
                tmp = data[i - 1];
                data[i - 1] = data[i];
                data[i] = tmp;
                swapped = true;
            }
        }

    }while(swapped);
}

template <comparison T>
void buble_sort(std::vector<T> &data, enum sort_type type){
    switch(type){
        case 0:
            buble_sort_increase(data);
            break;
        
        case 1:
            buble_sort_decrease(data);
            break;
    }
}