/*Joel Burkert
** The function of this code will be to hack time
*/

#ifndef MINIPROJECT0_HPP
#define MINIPROJECT0_HPP

#include <iostream>
#include <unistd.h>

namespace hackToTheFuture{
    class TimeHacking{
        public:
            TimeHacking(std::string objectToHack);
            void setTimeToHack(int seconds);
            int getTimeToHack();
            std::string getObjectToHack();
            void hackTime();
            void hackTimeWithBar();

        private:
            int time_to_hack;
            std::string objectToHack;

    };
}
#endif