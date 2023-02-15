// add your code as appropriate 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>
#include "reservoir.h"

int main(){
    // Test trial A
    std::string userdate = "04/27/2018"; //userdate
    double storage = get_east_storage(userdate); //east storage
    std::cout << "East Basin storage on " << userdate << ": " << storage << " billion gallons" << std::endl;
    //Test Trial B
    double minstor = get_min_east();
    std::cout << "Minimum East Basin storage in 2018: " << minstor << " billion gallons" << std::endl;
    return 0;
}