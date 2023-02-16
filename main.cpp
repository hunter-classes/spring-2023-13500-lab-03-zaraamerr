// add your code as appropriate 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"

int main(){
    // 3 test trials for task a
    std::cout << "The East Basin storage on 04/27/2018 is: " << get_east_storage("04/27/2018") << " billion gallons" << std::endl;
    std::cout << "The East Basin storage on 04/03/2018 is: " << get_east_storage("04/03/2018") << " billion gallons" << std::endl;
    std::cout << "The East Basin storage on 07/07/2018 is: " << get_east_storage("07/07/2018") << " billion gallons" << std::endl;
    // test trial for min
    std::cout << "The East Basin's minimum storage is: " << get_min_east() << " billion gallons" << std::endl;
    //test trial for max
    std::cout << "The East Basin's maximum storage is: " << get_max_east() << " billion gallons" << std::endl;
    // 3 test trials for task c
    std::cout << "On 01/07/2018 the " << compare_basins("01/07/2018") << " basin storage is greater." << std::endl;
    std::cout << "On 03/03/2018 the " << compare_basins("03/03/2018") << " basin storage is greater." << std::endl;
    std::cout << "On 09/25/2018 the " << compare_basins("09/25/2018") << " basin storage is greater." << std::endl;
    // 2 test trials for task d
    std::cout << "The West Basin elevation data printed in reverse chronological order during 04/03/2018 to 04/10/2018: " << std::endl;
    reverse_order("04/03/2018", "04/05/2018");
    std::cout << "The West Basin elevation data printed in reverse chronological order during 07/07/2018 to 07/14/2018: " << std::endl;
    reverse_order("07/07/2018", "07/09/2018");
}