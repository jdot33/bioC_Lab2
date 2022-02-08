//corr source
#include "burkertj_corr.hpp"

using namespace std;

jStats::corr::corr(int ri1){
    this->corr_coeff = 0;
}

float jStats::corr::calc_corr_coeff(std::vector<float>* vec1, std::vector<float>* vec2){
    float m1, m2, m3;
    jStats::stats vecStats(m1, m2, m3);
    float sum = 0;
    float mean_vec1, mean_vec2;
    int n = 0;
    if(vec1->size() == vec2->size()){
        n = vec1->size();
    }
    else{
        std::cout << "Warning, files are not the same length\n";
        return 0;
    }
    vecStats.calc_mean(vec1);
    mean_vec1 = vecStats.get_mean();
    vecStats.calc_mean(vec2);
    mean_vec2 = vecStats.get_mean();
    for(int i = 0; i < n; i++){
        sum += (vec1->at(i)*vec2->at(i));
    }
    float dloop_vec1, dloop_vec2;
    dloop_vec1 = this->denom_loop(vec1);
    dloop_vec2 = this->denom_loop(vec2);
    float result = (sum - (n*mean_vec1*mean_vec2)/pow((dloop_vec1*dloop_vec2), 0.5));
    return result;
}

float denom_loop(std::vector<float>* vec){
    float m1, m2, m3;
    jStats::stats vecStats(m1, m2, m3);
    float sum = 0;
    float mean;
    vecStats.calc_mean(vec);
    mean = vecStats.get_mean();
    for(int i = 0; i < vec->size(); i++){
        sum += pow(vec->at(i), 2);
    }
    float result = sum - vec->size()*pow(mean, 2);
    return result;
}

// int main(int argc, char* argv[]){
//     std::vector<float> vec = {1,2.01,5,3.2,400.12,6.5, 0.005};
//     std::vector<float> vec2 = {1,2.01,5,3.2,400.12,6.5, 0.005};

//     std::cout << "The elements of vec are : ";
 
//     for (int i = 0; i < vec.size(); i++)
//         std::cout << vec.at(i) << ',';
//     std::cout << '\n';
//     float m1, m2, m3, max, min, mean, stddev;
//     jStats::stats statCalc(m1, m2, m3);
//     statCalc.calc_max(&vec);
//     max = statCalc.get_max();
//     statCalc.calc_min(&vec);
//     min = statCalc.get_min();
//     statCalc.calc_mean(&vec);
//     mean = statCalc.get_mean();
//     statCalc.calc_stddev(&vec);
//     stddev = statCalc.get_stddev();
//     statCalc.calc_histogram(&vec);
//     int num_p = vec.size();
//     std::cout << "Number of data points analyzed\t\t:\t" << num_p << "\n";
//     std::cout << "Mean value\t\t\t\t:\t" << mean << "\n";
//     std::cout << "Standard Deviation\t\t\t:\t" << stddev << "\n";
//     std::cout << "Minimum\t\t\t\t\t:\t" << min << "\n";
//     std::cout << "Maximum\t\t\t\t\t:\t" << max << "\n";

//     int ri1;
//     jStats::corr corrCalc(ri1);

//     float corr_co = corrCalc.calc_corr_coeff(&vec, &vec2);
//     std::cout << "correlation coefficient\t:\t" << corr_co << "\n";
//     return 0;
// }