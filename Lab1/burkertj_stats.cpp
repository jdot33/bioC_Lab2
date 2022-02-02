#include "burkertj_stats.hpp"

jStats::stats::stats(float a, float b, float c){
    this->min = 0;
    this->max = 0;
    this->mean = 0;
}

void jStats::stats::calc_min(std::vector<float> vector){
    float m = vector[0];
    for (int i : vector){
        if(i < min)
            m = i;
    }
    this->min = m;
}
void jStats::stats::calc_max(std::vector<float> vector){
    float m = vector[0];
    for (int i : vector){
        printf("i = %d\n", i);
        if(i > max)
            m = i;
    }
    this-> max = m;
}
void jStats::stats::calc_mean(std::vector<float> vector){
    float sum = 0;
    for(int i : vector){
        printf("%d: %f + %f\n", i-1, sum, vector[i-1]);
        sum += vector[i-1];
    }
    printf("sum = %f\n", sum);
    printf("vectorsize = %lu\n", vector.size());
    float m = sum/vector.size();
    this->mean = m;
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


int main(int argc, char* argv[]){
    std::vector<float> vector = {1,2,5,3,4,6};
    float m1, m2, m3, max, min, mean;
    jStats::stats statCalc(m1, m2, m3);
    statCalc.calc_max(vector);
    max = statCalc.get_max();
    printf("Max: %f\n", max);
    statCalc.calc_min(vector);
    min = statCalc.get_min();
    printf("Min: %f\n", min);
    statCalc.calc_mean(vector);
    mean = statCalc.get_mean();
    printf("Mean: %f\n", mean);
    return 0;
}