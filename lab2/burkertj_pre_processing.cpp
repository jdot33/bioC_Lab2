/*
*
*
*/

#include "burkertj_pre_processing.hpp"
//#include "burkertj_k_means.hpp"


int get_data(char* filename, std::vector<float>* vec){
    FILE* file; 
    if(file = fopen(filename, "r")){
        float num;
        fscanf (file, "%f", &num);    
        while (!feof (file))
        {  
            vec->push_back(num);
            fscanf (file, "%f", &num);      
        }
        fclose(file);
        return 0;
    }
    else{
        std::cout << "ERROR: " << filename << " does not exist\n";
        return 1;
    }
}




int main(int argc, char* argv[]) {
    FILE* fileout;
    FILE* log_ratio_input_file;
    int a, b, c;
    std::vector<float> red_data;
    std::vector<float> red_background_data;
    std::vector<float> green_data;
    std::vector<float> green_background_data;
    std::vector<float> calib_vec;

    if(get_data(argv[1], &red_data)){
        return 1;
    }
    if(get_data(argv[2], &red_background_data)){
        return 1;
    }
    if(get_data(argv[3], &green_data)){
        return 1;
    }
    if(get_data(argv[4], &green_background_data)){
        return 1;
    }
    char* calib_data_filename = argv[5];
    int num_genes = atoi(argv[6]);
    
    jVector::vectorops vops;
    jStats::stats statCalc(a, b, c);

    if(num_genes > red_data.size()){
        std::cout << "ERROR: The requested number of genes is greater than the number of data points\n";
        return 0;
    }

    vops.sub_vectors(&red_data, &red_data, &red_background_data);
    vops.sub_vectors(&green_data, &green_data, &green_background_data);

    //normalize red vector
    statCalc.calc_mean(&red_data);
    vops.div_vector(&red_data, &red_data, statCalc.get_mean());

    //normalize green vector
    statCalc.calc_mean(&green_data);
    vops.div_vector(&green_data, &green_data, statCalc.get_mean());

    if(fileout = fopen(calib_data_filename, "w")){
    }
    else{
        std::cout << "ERROR: " << fileout << " does not exist\n";
    }

    //calc log ratio
    for(int i = 0; i < num_genes; i++){
        float logratio =  log10(red_data.at(i)/green_data.at(i));
        fprintf(fileout, "%f\n", logratio);
    }
    fclose(fileout);
}