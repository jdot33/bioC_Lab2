
#ifndef BURKERTJSTATS_HPP
#define BURKERTJSTATS_HPP

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

//NAMESPACES - std::string is a namespace::class combo. std is namespace, string is class. 
namespace jStats{

    //CLASSES
    class stats{
        public:

            stats(float a, float b, float c); //Constructor
            //~stats();
            
            float get_min();
            float get_max();
            float get_mean();
            float get_stddev();
            float get_histogram();

            void calc_min(std::vector<float>* vector);
            void calc_max(std::vector<float>* vector);
            void calc_mean(std::vector<float>* vector);
            void calc_stddev(std::vector<float>* vector);
            void calc_histogram(std::vector<float>* vector);

        private:

            float min;
            float max;
            float mean;
            float stddev;
            float histogram;

    };
}

#endif