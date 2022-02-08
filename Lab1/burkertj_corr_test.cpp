//corr test

#include "burkertj_corr.hpp"
#include "burkertj_stats.hpp"
#include "burkertj_corr.cpp"
#include "burkertj_stats.cpp"
using namespace std;

int main(int argc, char* argv[]){
    std::vector<float> vec = {1,2.01,5,3.2,400.12,6.5, 0.005};
    std::vector<float> vec2 = {1,2.01,5,3.2,400.12,6.5, 0.005};

    std::cout << "The elements of vec are : ";
 
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << ',';
    std::cout << '\n';
    float m1, m2, m3, max, min, mean, stddev;
    jStats::stats statCalc(m1, m2, m3);
    statCalc.calc_max(&vec);
    max = statCalc.get_max();
    statCalc.calc_min(&vec);
    min = statCalc.get_min();
    statCalc.calc_mean(&vec);
    mean = statCalc.get_mean();
    statCalc.calc_stddev(&vec);
    stddev = statCalc.get_stddev();
    statCalc.calc_histogram(&vec);
    int num_p = vec.size();
    std::cout << "Number of data points analyzed\t\t:\t" << num_p << "\n";
    std::cout << "Mean value\t\t\t\t:\t" << mean << "\n";
    std::cout << "Standard Deviation\t\t\t:\t" << stddev << "\n";
    std::cout << "Minimum\t\t\t\t\t:\t" << min << "\n";
    std::cout << "Maximum\t\t\t\t\t:\t" << max << "\n";

    int ri1;
    jStats::corr corrCalc(ri1);

    float corr_co = corrCalc.calc_corr_coeff(&vec, &vec2);
    std::cout << "correlation coefficient\t:\t" << corr_co << "\n";
    return 0;
}