#include <iostream>
#include "includes/buble_sort.hpp"
#include <chrono>

std::vector<int> generate_numbers(int N){
    std::vector<int> result(N);

    for(int i = 0; i < N; ++i){
        result[i] = rand() %100000;
    }

    return result;
}

int main(){

    const start_N = 100;
    const end_N = 7000;
    const step = 100;
    
    std::vector<int> test_data;

    for(int N = start_N; N <= end_N; N += step){

        test_data = generate_numbers(N);

        auto start = std::chrono::high_resolution_clock::now();
        buble_sort(test_data, ASCENDING);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        printf("\n N = %d \t TIME = %ld \n", N, duration.count());

        }
        
        return 0;
    
}