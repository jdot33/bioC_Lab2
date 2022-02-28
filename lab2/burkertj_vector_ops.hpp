/*
**Joel Burkert
*/

#ifndef BURKERTJVECTOROPS_HPP
#define BURKERTJVECTOROPS_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>

namespace jVector{

    class vectorops{

        public:
            vectorops();
            float sum_vector(std::vector<float>* vec);
            void sub_vectors(std::vector<float>* vec1, std::vector<float>* vec2, std::vector<float>* vecOut);
            void div_vector(std::vector<float>* vecOut, std::vector<float>* vec, float constant);
            void print_vector(std::vector<float>* vec);
        private:

    };
}

#endif