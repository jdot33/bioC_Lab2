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
    int n = -1;
    if(vec1->size() == vec2->size()){
        n = vec1->size();
    }
    else{
        std::cout << "Warning, files are not the same length\n";
        return 0;
    }
    //cout << "n = " << n << "\n";
    vecStats.calc_mean(vec1);
    mean_vec1 = vecStats.get_mean();
    cout << mean_vec1 << "\n";
    vecStats.calc_mean(vec2);
    mean_vec2 = vecStats.get_mean();
    cout << mean_vec1 << "\n";
    for(int i = 0; i < n; i++){
        sum += (vec1->at(i)*vec2->at(i));
    }
    cout << sum << "\n";
    float dloop_vec1, dloop_vec2;
    dloop_vec1 = this->denom_loop(vec1);
    dloop_vec2 = this->denom_loop(vec2);
    float result = (sum - (n*mean_vec1*mean_vec2))/pow((dloop_vec1*dloop_vec2), 0.5);
    return result;
}

float jStats::corr::denom_loop(std::vector<float>* vec){
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