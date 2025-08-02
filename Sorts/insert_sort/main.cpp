#include <iostream>
#include "includes/insert_sort.hpp"
#include <chrono>

std::vector<int> generate_numbers(int N){
    std::vector<int> result(N);

    for(int i = 0; i < N; ++i){
        result[i] = rand();
    }

    return result;
}

int main(){

    const int start_N = 100;
    const int end_N = 10000;
    const int step = 100;
    
    std::vector<int> test_data;

    for(int N = start_N; N <= end_N; N += step){

        test_data = generate_numbers(N);

        auto start = std::chrono::high_resolution_clock::now();
        insert_sort(test_data, ASCENDING);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        printf("\n N = %d \t TIME = %ld \n", N, duration.count());

    }
        
        return 0;
    
}