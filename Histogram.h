#ifndef HISTOGRAM_H_INCLUDED 
#define HISTOGRAM_H_INCLUDED
#include "internal_histogram.h"
std::vector<size_t> make_histogram(const std::vector<double>&, size_t);
void find_minmax(const std::vector<double>&, double&, double&);
#endif