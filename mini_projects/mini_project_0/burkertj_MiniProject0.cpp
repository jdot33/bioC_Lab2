

#include "burkertj_MiniProject0.hpp"

hackToTheFuture::TimeHacking::TimeHacking(std::string objectToHack){
    this->time_to_hack = 0;
    this->objectToHack = objectToHack;
}

/*Sets the time to hack in seconds*/
void hackToTheFuture::TimeHacking::setTimeToHack(int seconds){
    this->time_to_hack = seconds;
}

/*Gets the time to hack in seconds*/
int hackToTheFuture::TimeHacking::getTimeToHack(){
    return this->time_to_hack;
}

/*Gets the string name of the hacking target*/
std::string hackToTheFuture::TimeHacking::getObjectToHack(){
    return this->objectToHack;
}

/*Hacks time by sleeping for the number of seconds defined in time_to_hack*/
void hackToTheFuture::TimeHacking::hackTime(){
    sleep(this->time_to_hack);
    std::cout << "Time has been hacked!\n";
}

void hackToTheFuture::TimeHacking::hackTimeWithBar(){
    float progress = 0.0; 
    int barWidth = 50;
    int pos = barWidth * progress;
    for(int i = 0; i <= this->getTimeToHack(); i++){
        progress = (float)(i/this->getTimeToHack());
        pos = barWidth * progress;
        
        std::system("clear");
        std::cout << "Hacking\t:\t" << this->getObjectToHack() << "\n";
        std::cout << "For\t:\t" << this->getTimeToHack() << " seconds\n";
        std::cout << "Hack in progress\n";



        std::cout << "[";
        for (int j = 0; j < barWidth; j++) {
            if (j <= pos) std::cout << "|";
            else std::cout << "-";
        }
        std::cout << "]" << int(progress * 100.0) << " %\r";
        sleep(1);

        //std::cout.flush();
        // int barWidth = 30;
        // int pos = barWidth * progress;

    }
}

int main(int argc, char* argv[]){
    std::string object;
    int time;
    std::cout << "Which object do you want to hack?\n";
    std::cin >> object;
    std::cout << "How many seconds do you want to hack for?\n";
    std::cin >> time;

    hackToTheFuture::TimeHacking hack(object);
    hack.setTimeToHack(time);
    std::cout << "Hacking\t:\t" << hack.getObjectToHack() << "\n";
    std::cout << "For\t:\t" << hack.getTimeToHack() << " seconds\n";
    std::cout << "Hack in progress\n";
    //hack.hackTimeWithBar();
    hack.hackTime();

}