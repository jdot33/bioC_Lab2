/*
**Joel Burkert
*/

#ifndef BURKERTJKMEAN_HPP
#define BURKERTJKMEAN_HPP
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

    namespace jStats {

        class cluster{
            
            public:
                cluster(float mean);
                float calc_distance(float point);
                void set_name(std::string name);
                std::string get_name();
                void calc_mean();
                float get_mean();
                void add_point(float point);
                void clear_vector();

                std::string name;
                float mean;
                std::vector<float> data;
            private:

        };
    }
#endif