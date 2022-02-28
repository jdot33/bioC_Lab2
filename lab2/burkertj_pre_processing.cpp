/*
*
*
*/

#include "burkertj_pre_processing.hpp"
#include "burkertj_k_means.hpp"


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
        //system("color E4");
        std::cout << "ERROR: " << filename << " does not exist\n";
        //system("color 07");
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

    //vops.print_vector(&red_data);
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

    //vops.print_vector(&red_data);
    //vops.print_vector(&green_data);


    if(fileout = fopen(calib_data_filename, "w")){
    }
    else{
        //system("color E4");
        std::cout << "ERROR: " << fileout << " does not exist\n";
        //system("color 07");
    }
std::cout << "made it 90\n";
    //calc log ratio
    for(int i = 0; i < green_data.size(); i++){
        float logratio =  log10(red_data.at(i)/green_data.at(i));
        fprintf(fileout, "%f\n", logratio);
    }
    fclose(fileout);

    std::vector<float> all_data;
    get_data(calib_data_filename, &all_data);

    jStats::cluster clust1(-0.5);
    jStats::cluster clust2(0.0);
    jStats::cluster clust3(0.5);

    float d1, d2, d3, old_mean_1, old_mean_2, old_mean_3, criteria;
    criteria = 1;
//std::cout << "made it 107\n";
    while(criteria > 0.0001){
        //make sure the clusters are all empty and ready to get new points
        clust1.data.clear();
        clust2.data.clear();
        clust3.data.clear();

        //std::cout << "made it 112\n";
        for(float i : all_data){
            d1 = clust1.calc_distance(i);
            d2 = clust2.calc_distance(i);
            d3 = clust3.calc_distance(i);
            //std::cout << "made it 117\n";
            
            if(d1 <= d2 && d1 <= d3){
                //Add point to cluster 1
                clust1.data.push_back(i);
                //std::cout << "made it 121\n";
            } else if(d2 <= d1 && d2 <= d3){
                //add point to cluster 2
                clust2.data.push_back(i);
                //std::cout << "made it 124\n";
            }
            else{
                //add point to cluster 3
                clust3.data.push_back(i);
                //std::cout << "made it 128\n";
            }
        }
            std::cout << clust1.data.size() << "\n";
            std::cout << clust2.data.size() << "\n";
            std::cout << clust3.data.size() << "\n";
            //get old mean and calculate new means
            old_mean_1 = clust1.get_mean();
            clust1.calc_mean();
            old_mean_2 = clust2.get_mean();
            clust2.calc_mean();
            old_mean_3 = clust3.get_mean();
            clust3.calc_mean();
            //std::cout << "made it 137\n";
            //std::cout << "Old mean 1: " << old_mean_1 << "\nnew mean 1: " << clust1.get_mean() << "\n";
            //std::cout << "Old mean 2: " << old_mean_2 << "\nnew mean 2: " << clust2.get_mean() << "\n";
            //std::cout << "Old mean 3: " << old_mean_3 << "\nnew mean 3: " << clust3.get_mean() << "\n";

            criteria = abs(old_mean_1 - clust1.get_mean()) - abs(old_mean_2 - clust2.get_mean()) - abs(old_mean_3 - clust3.get_mean()); 
            std::cout << "criteria: " << criteria << "\n";
            
    }

    std::cout << "cluster 1 mean: " << clust1.get_mean() << "\n";
    std::cout << "cluster 2 mean: " << clust2.get_mean() << "\n";
    std::cout << "cluster 3 mean: " << clust3.get_mean() << "\n";

}