//corr test

#include "burkertj_corr.hpp"
#include "burkertj_stats.hpp"
using namespace std;

int main(int argc, char* argv[]){
    std::vector<float> vec;
    std::vector<float> vec2;

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
        cout << "File does not exist\n";
    }

    FILE* fin2; 
    if(fin2 = fopen(argv[2], "r")){
        float num;
        fscanf (fin2, "%f", &num);    
        while (!feof (fin2))
        {  
            vec2.push_back(num);
            fscanf (fin2, "%f", &num);      
        }
    }
    else{
        cout << "File does not exist\n";
    }
    
    int ri1;
    jStats::corr corrCalc(ri1);

    float corr_co = corrCalc.calc_corr_coeff(&vec, &vec2);
    //std::cout << "correlation coefficient\t:\t" << corr_co << "\n";
    std::cout << corr_co;
    return 0;
}