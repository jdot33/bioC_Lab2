
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

int main(int argc, char* argv[]){
    
    int num_genes = atoi(argv[1]);
    char* stationary_file = argv[2];
    char* suppressed_file = argv[3];
    char* expressed_file = argv[4];

    std::vector<float> all_data;
    get_data("log_ratio_input.dat", &all_data);
    //all_data.resize(num_genes);
    //std::cout << all_data.size() << "\n";

    jStats::cluster clust1(-0.5);
    jStats::cluster clust2(0.0);
    jStats::cluster clust3(0.5);

    float d1, d2, d3, old_mean_1, old_mean_2, old_mean_3, criteria;
    criteria = 1;

    //int runs = 0;
    while(criteria > 0.0001){
        //make sure the clusters are all empty and ready to get new points
        clust1.data.clear();
        clust2.data.clear();
        clust3.data.clear();
        //runs++;

        for(float i : all_data){
            d1 = clust1.calc_distance(i);
            d2 = clust2.calc_distance(i);
            d3 = clust3.calc_distance(i);
            
            if(d1 < d2 && d1 < d3){
                //Add point to cluster 1
                clust1.data.push_back(i);
            } else if(d2 <= d1 && d2 <= d3){
                //add point to cluster 2
                clust2.data.push_back(i);
            }
            else if(d3 < d1 && d3 < d2){
                //add point to cluster 3
                clust3.data.push_back(i);
            }
        }

// std::cout << clust1.data.size() << "\n";
// std::cout << clust2.data.size() << "\n";
// std::cout << clust3.data.size() << "\n";

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

            criteria = abs(old_mean_1 - clust1.get_mean()) + abs(old_mean_2 - clust2.get_mean()) + abs(old_mean_3 - clust3.get_mean()); 
            //std::cout << "criteria: " << criteria << "\n";
            
    }

    //cluster 1 is most negative = suppression, cluster 2 is close to zero = stationary, cluster 3 is most positive = expression.
    std::cout << "cluster 1 mean: " << clust1.get_mean() << "\n";
    std::cout << "cluster 2 mean: " << clust2.get_mean() << "\n";
    std::cout << "cluster 3 mean: " << clust3.get_mean() << "\n";
    //std::cout << runs << " runs\n";
    int i = 0;
    int j = 0;
    int k = 0;
    int y = 0;
    float dpoint;
    FILE* gene_names; 
    FILE* suppressed = fopen(suppressed_file, "w");
    FILE* stationary = fopen(stationary_file, "w");
    FILE* expressed = fopen(expressed_file, "w");
    rewind(suppressed);
    rewind(stationary);
    rewind(expressed);
    if(gene_names = fopen("./microarray/gene_list.txt", "r")){
        char line[10];
        fscanf (gene_names, "%s", line);    
        while (!feof(gene_names) && i < num_genes)
        {  
            
            if(clust1.data.size() > 0 && clust1.data.at(j) == all_data.at(i)){
                //Add gene to suppressed file
                fprintf(suppressed, "%s\n", line);
                if(j < clust1.data.size()){
                    j++;
                }
//                std::cout << i << "\t" << all_data.at(i) << "\t\t" << "clust1 size:\t" << clust1.data.size() << "\tj:\t" << j << "\n";
            } else if(clust2.data.size() > 0 && clust2.data.at(k) == all_data.at(i)){
                //add gene to stationary file
                fprintf(stationary, "%s\n", line);
                if(k < clust2.data.size()){
                    k++;
                }
//                std::cout << i << "\t" << all_data.at(i) << "\t\t" <<  "clust2 size:\t" << clust2.data.size() << "\tk:\t" << k << "\n";
            }
            else if(clust3.data.size() > 0 && clust3.data.at(y) == all_data.at(i)){
                //add gene to expressed file
                fprintf(expressed, "%s\n", line);
                if(y < clust3.data.size()){
                    y++;
                }
//                std::cout << i << "\t" << all_data.at(i) << "\t\t" <<  "clust3 size:\t" << clust3.data.size() << "\ty:\t" << y << "\n";
            }
            //std::cout << i << "\n";
            i++;
            fscanf (gene_names, "%s", line);      
        }
    }
    else{
        std::cout << "ERROR: gene_list.txt does not exist\n";
    }
    std::cout << "\n" << all_data.size();
    std::cout << "\n" << clust1.data.size();
    std::cout << "\n" << clust2.data.size();
    std::cout << "\n" << clust3.data.size();
    fclose(gene_names);
    fclose(suppressed);
    fclose(stationary);
    fclose(expressed);
    return 0;
}