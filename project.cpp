#include "svg.h"
#include <iostream>
#include <vector>
#include "Histogram.h"
#include <time.h>


struct Input {
    std::vector<double> numbers;
    size_t bin_count{};
}; typedef struct Input Input;

Input input_data() {
    Input in;
    size_t digit{};
    std::cerr << "Enter number of elements in the basket:\n";
    std::cin >> digit;
    in.numbers.resize(digit);
    std::cerr << "Enter number of elements:\n";
    for (size_t i = 0; i < digit; ++i)
        std::cin >> in.numbers[i];
    std::cerr << "Enter number of bins:\n";
    std::cin >> in.bin_count;
    return in;
}



#ifndef test_program_
int main()
{
    srand((unsigned int)time(NULL));
    auto in = input_data();
    auto bins = make_histogram(in.numbers, in.bin_count);
    show_histogram_svg(bins);
    return 0;
}
#else
#endif

