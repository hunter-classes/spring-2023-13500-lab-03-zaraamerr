// add your code as appropriate 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>
#include "reservoir.h"

int main(){
    // Test trial
    std::string userdate = "04/27/2018"; //userdate
    double storage = get_east_storage(userdate); //east storage
    std::cout << "East Basin storage on " << userdate << ": " << storage << " billion gallons" << std::endl;
    return 0;
}