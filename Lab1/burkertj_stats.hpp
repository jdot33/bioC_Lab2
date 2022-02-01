//header for primerClasses_cpp.cpp


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//NAMESPACES - std::string is a namespace::class combo. std is namespace, string is class. 
namespace jStats{

    //CLASSES
    class stats{
        public:

            stats(float, float, float);
            //stats(std::string name, float init_num_students); //construct myclass with an initial name and number of stuedents
            //stats(std::string name);

            float get_min();
            float get_max();
            float get_mean();
            //float get_stddev();
            //float get_histogram();


            //std::string get_name();
            //void set_num_student(float num);

            void calc_min(std::vector<float> vector);
            void calc_max(std::vector<float> vector);
            void calc_mean(std::vector<float> vector);
            void calc_stddev(std::vector<float> vector);
            void calc_histogram(std::vector<float> vector);

        private:
            float min;
            float max;
            float mean;
            //float stddev;
            //float histogram;
    };
}