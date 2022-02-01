#include "burkertj_stats.hpp"

jStats::stats::stats(){
    this->set_min(0);
    this->set_max(0);
    this->set_mean(0);
}

void jStats::stats::calc_min(std::vector<float> vector){
    float min = vector[0];
    for (int i : vector){
        if(vector[i] < min)
            min = vector[i];
    }
    jStats::stats::set_min(min);
}
void jStats::stats::calc_max(std::vector<float> vector){
    float max = vector[0];
    for (int i : vector){
        if(vector[i] > max)
            max = vector[i];
    }
    jStats::stats::set_max(max);
}
void jStats::stats::calc_mean(std::vector<float> vector){
    float sum = 0;
    for(int i : vector){
        sum += vector[i];
    }
    float mean = sum/vector.size();
    jStats::stats::set_mean(mean);
}
void jStats::stats::calc_stddev(std::vector<float> vector){

}
void jStats::stats::calc_histogram(std::vector<float> vector){

}

void jStats::stats::set_min(float num){
    this->min = num;
}

void jStats::stats::set_max(float num){
    this->max = num;
}

void jStats::stats::set_mean(float num){
    this->mean = num;
}