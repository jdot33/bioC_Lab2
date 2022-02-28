/*
**Joel Burkert
**
*/

#include "burkertj_vector_ops.hpp"

jVector::vectorops::vectorops(){

}

float jVector::vectorops::sum_vector(std::vector<float>* vec){
    float sum = 0;
    for (float i : *vec) {
        sum += i;
    }
    return sum;
}

void jVector::vectorops::sub_vectors(std::vector<float>* vecOut, std::vector<float>* vec1, std::vector<float>* vec2){
    //std::cout << vec1->size() << "\n" << vec2->size() << "\n" << vecOut->size() << "\n";
    if(vec1->size() != vec2->size()){
        char sub_anyway;
        std::cout << "Vectors need to be the same size to subtract them\n";
        std::cout << "Would you still like to subtract the vectors?\nThe larger vector will be resized to match the smaller one,\nAny excess data will be lost! (y/n)\n";
        std::cin >> sub_anyway;
        if(sub_anyway != 'y'){
            return;
        }
        else {
            if(vec1->size() > vec2->size()){
                vec1->resize(vec2->size(), 0);
            }
            else{
                vec2->resize(vec1->size(), 0);
            }
        }
    }
    vecOut->resize(vec1->size(), 0);
    for(int i = 0; i < vec1->size(); i++){
        if(i < vecOut->size()){
            vecOut->at(i) = vec1->at(i) - vec2->at(i);
        }
        else{
            vecOut->push_back(vec1->at(i) - vec2->at(i));
        }
    }
}

void jVector::vectorops::div_vector(std::vector<float>* vecOut, std::vector<float>* vec, float constant){
    vecOut->resize(vec->size(), 0);
    for(int i = 0; i < vec->size(); i++){
        if(i < vecOut->size()){
            vecOut->at(i) = vec->at(i) / constant;
        }
        else{
            vecOut->push_back(vec->at(i) / constant); //pretty sure using resize() makes this if statement worthless, but oh well.  
        }
    }
}

void jVector::vectorops::print_vector(std::vector<float>* vec){
    std::cout << "{";
    for(int i = 0; i < vec->size(); i++){
        std::cout << vec->at(i);
        if(i != vec->size() - 1){
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

/*
int main(int argc, char* argv[]){
    
    std::vector<int> vec1;
    std::vector<int> vec2; 
    std::vector<int> vec3;
    for(int i = 0; i < 10; i++){
        vec1.push_back(i);
        vec2.push_back(9-i);
        vec3.push_back(i*2);
    }

    jVector::vectorops selky;

    int sum = selky.sum_vector(&vec1);
    selky.print_vector(&vec1);
    std::cout << "Sum: " << sum << "\n\n";

    sum = selky.sum_vector(&vec2);
    selky.print_vector(&vec2);
    std::cout << "Sum: " << sum << "\n\n";

    sum = selky.sum_vector(&vec3);
    selky.print_vector(&vec3);
    std::cout << "Sum: " << sum << "\n\n\n\n";

    selky.sub_vectors(&vec3, &vec1, &vec2);
    sum = selky.sum_vector(&vec3);
    selky.print_vector(&vec3);
    std::cout << "Sum: " << sum << "\n\n";

    vec3.push_back(65);
    vec3.push_back(70);
    vec3.push_back(75);

    std::cout << "vecOut is bigger than vec1 and vec2\n";
    selky.sub_vectors(&vec3, &vec1, &vec2);
    sum = selky.sum_vector(&vec3);
    selky.print_vector(&vec3);
    std::cout << "Sum: " << sum << "\n\n";

    vec1.push_back(66);
    vec1.push_back(71);
    vec1.push_back(76);
    vec2.push_back(65);
    vec2.push_back(70);
    vec2.push_back(75);

    std::cout << "vecOut is smaller than vec1 and vec2\n";
    selky.sub_vectors(&vec3, &vec1, &vec2);
    sum = selky.sum_vector(&vec3);
    selky.print_vector(&vec3);
    std::cout << "Sum: " << sum << "\n\n";

    std::cout << "vec3 is used as the output and argument\n";
    selky.print_vector(&vec1);
    selky.print_vector(&vec3);
    selky.sub_vectors(&vec3, &vec1, &vec3);
    sum = selky.sum_vector(&vec3);
    selky.print_vector(&vec3);
    std::cout << "Sum: " << sum << "\n\n";

    std::cout << "vec3 is used as the output and argument when dividing\n";
    selky.print_vector(&vec3);
    selky.div_vector(&vec3, &vec3, 2);
    sum = selky.sum_vector(&vec3);
    selky.print_vector(&vec3);
    std::cout << "Sum: " << sum << "\n\n";

    vec1.push_back(85);
    vec1.push_back(90);
    vec1.push_back(95);

    std::cout << "vec3 is used as the output and argument when dividing\n";
    selky.print_vector(&vec1);
    selky.print_vector(&vec2);
    selky.print_vector(&vec3);
    selky.sub_vectors(&vec3, &vec1, &vec2);
    sum = selky.sum_vector(&vec3);
    selky.print_vector(&vec3);
    std::cout << "Sum: " << sum << "\n\n";

    return 0;
}
*/