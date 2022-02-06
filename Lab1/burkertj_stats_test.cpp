#include "burkertj_stats.hpp"
//#include "burkertj_stats.cpp"

// int main(int argc, char* argv[]){
//     std::vector<float> vector = {1,2,5,3,4,6};

//     std::cout << "The elements of Vector are : ";
 
//     for (int i = 0; i < vector.size(); i++)
//         std::cout << vector.at(i) << ',';
//     std::cout << '\n';

//     float m1, m2, m3, max, min, mean, stddev;
//     jStats::stats statCalc(m1, m2, m3);
//     statCalc.calc_max(vector);
//     max = statCalc.get_max();
//     statCalc.calc_min(vector);
//     min = statCalc.get_min();
//     statCalc.calc_mean(vector);
//     mean = statCalc.get_mean();
//     statCalc.calc_stddev(vector);
//     stddev = statCalc.get_stddev();
//     int num_p = vector.size();
//     std::cout << "Number of data points analyzed\t\t:\t" << num_p << "\n";
//     std::cout << "Mean value\t\t\t\t:\t" << mean << "\n";
//     std::cout << "Standard Deviation\t\t\t:\t" << stddev << "\n";
//     std::cout << "Minimum\t\t\t\t\t:\t" << min << "\n";
//     std::cout << "Maximum\t\t\t\t\t:\t" << max << "\n";
//     return 0;
// }