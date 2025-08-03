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

int len_number(int number){

    if (number == 0) return 1;
    int len = 0;
    while (number != 0) {
        number /= 10;
        ++len;
    }
    return len;
}

int get_digit(int num, int digit){

    if(digit <= 0) {return -1;}

    if(digit > len_number(num)) {return 0;}

    return static_cast<int>((num / (pow(10, digit - 1)))) % 10;
}

void radix_sort_increase(std::vector<int> &data){

    if(data.empty())
        return;

    int max_num_len = len_number(max(data)); 

    std::vector<std::vector<int>> buffer(10);

    int el;
    int el_digit;

    int el_count;

    for(int digit = 1; digit <= max_num_len; ++digit){

        for(int i = 0; i < data.size(); ++i){
            el = data[i];
    
            el_digit = get_digit(el, digit);

            if(el_digit != -1){
                buffer[el_digit].push_back(el);
            }
        }

        data.clear();

        for(int i = 0; i < 10; ++i){
            el_count = buffer[i].size();

            for(int j = 0; j < el_count; ++j){
                data.push_back(buffer[i][j]);
            }

            buffer[i].clear();

        }
    }

}

void radix_sort_decrease(std::vector<int> &data){

    if(data.empty())
        return;

    int max_num_len = len_number(max(data)); 

    std::vector<std::vector<int>> buffer(10);

    int el;
    int el_digit;

    int el_count;

    for(int digit = 1; digit <= max_num_len; ++digit){

        for(int i = 0; i < data.size(); ++i){
            el = data[i];
    
            el_digit = get_digit(el, digit);

            if(el_digit != -1){
                buffer[el_digit].push_back(el);
            }
        }

        data.clear();

        for(int i = 9; i >= 0; --i){
            el_count = buffer[i].size();

            for(int j = 0; j < el_count; ++j){
                data.push_back(buffer[i][j]);
            }

            buffer[i].clear();

        }
    }

}

void radix_sort(std::vector<int> &data, enum sort_type type){
    switch(type){
        case 0:
            radix_sort_increase(data);
            break;
        
        case 1:
            radix_sort_decrease(data);
            break;
    }
}