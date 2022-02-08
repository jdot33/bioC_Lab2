//corr header

#ifndef BURKERTJCORR_HPP
#define BURKERTJCORR_HPP

#include "burkertj_stats.hpp"

//NAMESPACES - std::string is a namespace::class combo. std is namespace, string is class. 
namespace jStats{

    //CLASSES
    class corr{
        public:
            corr(int ri1);

            float calc_corr_coeff(std::vector<float>* vec1, std::vector<float>* vec2);
            float denom_loop(std::vector<float>* vec);


        private:
            float corr_coeff;
    };
}

#endif