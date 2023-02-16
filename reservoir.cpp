#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

//task A
double get_east_storage(std::string date)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv"); //read file
    if (fin.fail()) //if file cannot be opened or is unreadable
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); //output error and terminate program
    }
    //Remember that the first line in the file is a header line. We have to skip it before we
    //get to process the actual data. We can do that by reading that line into a temporary variable
    //that we can call junk:
    std::string junk;
    std::getline(fin, junk); 

    std::string extracted_date; //string that will store dates from file
    double eastSt; //double that will store east storage values from file

    while (fin >> extracted_date >> eastSt) //reads file line by line and stores dates and east storage into their respective variables
    {
        if (date == extracted_date) //if the hardcoded date equals a date in the file
        {
            return eastSt; //return the value of east basin storage associated with that particular date
        }

        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns 
    }

    fin.close(); //close file
    return 0; //end 
}

 //task B part 1
double get_min_east()
{
    std::ifstream fin("Current_Reservoir_Levels.tsv"); //read file
    if (fin.fail()) //if file cannot be opened or is unreadable
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); //output error and terminate program
    }

    //Remember that the first line in the file is a header line. We have to skip it before we
    //get to process the actual data. We can do that by reading that line into a temporary variable
    //that we can call junk:
    std::string junk;
    std::getline(fin, junk);

    std::string extracted_date; //string that will store dates from file
    double eastSt = 0.0; //double that will store east basin storage values from file, initially set as 0.0 and will be determined later in the program
    double minstor = 100.0; //double that will store the minimum value of the east basin storage, initially set as 100.0 and will be determined later in the program

    while (fin >> extracted_date >> eastSt) //reads the file line by line and stores dates and east storage values into their respective variables
    {
        if (eastSt < minstor) //if the current value of the east basin storage is less than the current minimum value of the east basin storage
        {
            minstor = eastSt; //set the minimum east basin storage value to the current value of east basin storage
        }

        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns 
    }

    fin.close(); //close file
    return minstor; //return the minimum east basin storage value
}

//task b part 2
double get_max_east()
{
    std::ifstream fin("Current_Reservoir_Levels.tsv"); //read file
    if (fin.fail()) //if file cannot be opened or is unreadable
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); //output error and terminate the program
    }

    //Remember that the first line in the file is a header line. We have to skip it before we
    //get to process the actual data. We can do that by reading that line into a temporary variable
    //that we can call junk:
    std::string junk;
    std::getline(fin, junk);

    std::string extracted_date; //string that will store dates from the file
    double eastSt = 0.0; //double that will store east basin storage values from file, initially set as 0.0 and will be determined later in the program
    double maxstor= 0.0; //double that will store the maximum east basin storage values from file, initially set as 0.0 and will be determined later in the program

    while (fin >> extracted_date >> eastSt) //reads the file line by line and stores dates and east storage basin values into their respective variables
    {
        if (eastSt > maxstor) //if the current value of the east basin storage is greater than the current maximum east basin storage value
        {
            maxstor = eastSt; //set the maximum east basin storage value to the current value of east basin storage
        }

        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns 
    }

    fin.close(); // close file
    return maxstor; //return maximum east basin storage value
}

std::string compare_basins(std::string date)
{
   std::ifstream fin("Current_Reservoir_Levels.tsv"); //read file
    if (fin.fail()) //if file cannot be opened or is unreadable
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); //output error and terminate the program
    }

    //Remember that the first line in the file is a header line. We have to skip it before we
    //get to process the actual data. We can do that by reading that line into a temporary variable
    //that we can call junk:
    std::string junk;
    std::getline(fin, junk);

    std::string extracted_date; //string that will store dates from the file
    double eastSt; //double that will store east basin storage values from file
    double eastEl; //double that will store east elevation values from file
    double westSt; //double that will store west basin storage values from the file
    double westEl; //double that will store west elevation values from the file

    while (fin >> extracted_date >> eastSt >> eastEl >> westSt >> westEl) //reads the file line by line and stores dates, east storage values, east elevation values, west storage values, and west elevation values into their respective variables
    {
        if (date == extracted_date) //if the hardcoded date matches a date in the file
        {
            if (eastEl > westEl) //if the east elevation is greater than the west elevation
            {
                return "East";
            }
            else if (westEl > eastEl) //if the west elevation is greater than the east elevation
            {
                return "West";
            }
            else //otherwise, if both values are equal
            {
                return "Equal";
            }
        }

        fin.ignore(INT_MAX, '\n');  //skips to the end of line, ignoring the remaining columns 
    }

    fin.close(); //close file
    return 0; //end
}