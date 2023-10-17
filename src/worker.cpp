#include <algorithm>
#include "worker.hh"

std::vector<int> demo_work::do_work(const std::vector<int>& input){
    std::vector<int> retval = input;
    std::sort(retval.begin(), retval.end());
    return retval;
}