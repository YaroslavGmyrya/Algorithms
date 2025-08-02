#pragma once
#include <vector>
#include <concepts>
#include <cmath>

enum sort_type { ASCENDING, DESCENDING };

int max(const std::vector<int> &data){
    int max = -__INT_MAX__;

    for(int el : data){
        if(el > max){
            max = el;
        } 
    }

    return max;
}

void counting_sort_increase(std::vector<int> &data){

    if(data.empty())
        return;

    int max_value = max(data);

    std::vector<int> counting(max_value + 1);

    for(int el : data){
        ++counting[el];
    }

    data.clear();

    for(int i = 0; i < counting.size(); ++i){
        while(counting[i] > 0){
            data.push_back(counting[i]);
            --counting[i];
        }
    }
}

void counting_sort_decrease(std::vector<int> &data){

     if(data.empty())
        return;

    int max_value = max(data);

    std::vector<int> counting(max_value + 1);

    for(int el : data){
        ++counting[el];
    }

    data.clear();

    for(int i = counting.size() - 1; i >= 0; --i){
        while(counting[i] > 0){
            data.push_back(counting[i]);
            --counting[i];
        }
    }
}

void counting_sort(std::vector<int> &data, enum sort_type type){
    switch(type){
        case 0:
            counting_sort_increase(data);
            break;
        
        case 1:
            counting_sort_decrease(data);
            break;
    }
}