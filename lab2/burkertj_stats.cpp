#include "burkertj_stats.hpp"
using namespace std;

jStats::stats::stats(float a, float b, float c){
    this->min = 0;
    this->max = 0;
    this->mean = 0;
    this->stddev = 0;
}

void jStats::stats::calc_min(std::vector<float>* vec){
    float m = vec->at(0);
    for (float i : *vec){
        if(i < m)
            m = i;
    }
    this->min = m;
}
void jStats::stats::calc_max(std::vector<float>* vec){
    float m = vec->at(0);
    for (float i : *vec){
        if(i > m)
            m = i;
    }
    this-> max = m;
}
void jStats::stats::calc_mean(std::vector<float>* vec){
    float sum = 0;
    for(float i : *vec){
        sum += i;
    }
    float m = sum / vec->size();
    this->mean = m;
}
void jStats::stats::calc_stddev(std::vector<float>* vec){
    float sum = 0;
    this->calc_mean(vec);
    for(float i : *vec){
        sum += (pow((i - this->mean), 2));
    }
    float s = pow((sum/vec->size()), 0.5);
    this->stddev = s;
}

void jStats::stats::calc_histogram(std::vector<float>* vec){
    std::vector<float> bin_edges;
    std::vector<float> bin_count;

    this->calc_stddev(vec);
    float bin_width = 0.4*(this->stddev);
    float bin_start = -3*(this->stddev);
    float bin_end = 3*(this->stddev);
    int num_bins = 15; // 6/0.4 = 15

    int i = 0;
    float edge_tracker = bin_start;

    while(edge_tracker <= bin_end){
        bin_edges.push_back(edge_tracker);
        bin_count.push_back(0);
        edge_tracker += bin_width;
    }

    for(int i = 0; i < vec->size(); i++){
        for(int j = 0; j < bin_count.size()-1; j++){
            if(vec->at(i) >= bin_edges.at(j) && vec->at(i) < bin_edges.at(j+1)){
                bin_count.at(j)++;
            }
        }
    }

    for(int i = 0; i < bin_edges.size(); i++){
        std::cout << "\n" << bin_edges.at(i) << "\n";
        for(int j = 0; j < bin_count.at(i); j+=100){
            std::cout << "=";
        }
    }
    std::cout << "Each '=' is equivalent to 100 data points\n";
}

float jStats::stats::get_max(){
    return this->max;
}

float jStats::stats::get_min(){
    return this->min;
}

float jStats::stats::get_mean(){
    return this->mean;
}

float jStats::stats::get_stddev(){
    return this->stddev;
}

float jStats::stats::get_histogram(){
    return this->histogram;
}


// int main(int argc, char* argv[]){
//     std::vector<float> vec = {1,2.01,5,3.2,400.12,6.5, 0.005};

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
//     std::cout << "Number of data points analyzed\t\t:\t" << num_p << "\n"
//     << "Mean value\t\t\t\t:\t" << mean << "\n"
//     << "Standard Deviation\t\t\t:\t" << stddev << "\n"
//     << "Minimum\t\t\t\t\t:\t" << min << "\n"
//     << "Maximum\t\t\t\t\t:\t" << max << "\n";
//     return 0;
// }