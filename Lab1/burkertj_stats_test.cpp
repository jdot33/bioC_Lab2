#include "burkertj_stats.hpp"

int main(int argc, char* argv[]){
    std::vector<float> vec;

    FILE* fin1; 
    if(fin1 = fopen(argv[1], "r")){
        float num;
        fscanf (fin1, "%f", &num);    
        while (!feof (fin1))
        {  
            vec.push_back(num);
            fscanf (fin1, "%f", &num);      
        }
    }
    else{
        std::cout << "File does not exist\n";
        return 0;
    }

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
    std::cout << "Number of data points analyzed\t\t:\t" << num_p << "\n"
    << "Mean value\t\t\t\t:\t" << mean << "\n"
    << "Standard Deviation\t\t\t:\t" << stddev << "\n"
    << "Minimum\t\t\t\t\t:\t" << min << "\n"
    << "Maximum\t\t\t\t\t:\t" << max << "\n";
    return 0;
}