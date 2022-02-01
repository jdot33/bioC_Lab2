#include "burkertj_stats.hpp"
#include "burkertj_stats.cpp"

int main(){
    std::vector<float> vector = {1,2,5,3,4,6};
    jStats::stats statCalc();
    statCalc.calc_max(vector);
    float max = statCalc.get_max();
    printf("Max: %f", max);
    return 0;
}