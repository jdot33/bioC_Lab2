
#include "burkertj_k_means.hpp"


jStats::cluster::cluster(float m){
    this->mean = m;
}
float jStats::cluster::calc_distance(float point){
    float d = 0.0;
    d = abs(point - this->mean);
    //std::cout << "distance is: " << d << "\n";
    return d;
}
void jStats::cluster::set_name(std::string name){
    this->name = name;
}
std::string jStats::cluster::get_name(){
    return this->name;
}
void jStats::cluster::calc_mean(){
    float sum = 0;
    for(float i : this->data){
        sum += i;
    }
    float m = sum / this->data.size();
    this->mean = m;
}
float jStats::cluster::get_mean(){
    return this->mean;
}
void jStats::cluster::add_point(float point){
    this->data.push_back(point);
}
void jStats::cluster::clear_vector(){
    this->data.clear();
}