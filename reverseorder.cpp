#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

const int MAX_DATA_POINTS = 365; // Maximum number of data points that can be stored

void reverse_order(std::string date1, std::string date2)
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

    std::string date_array[MAX_DATA_POINTS];  // Array to store dates
    double westElArray[MAX_DATA_POINTS];   // Array to store west basin elevation data
    int index = 0;
    bool startWrite = false; //initialize bool as false until it comes across date1

    while (index < MAX_DATA_POINTS && fin >> date_array[index] >> junk >> junk >> junk >> westElArray[index]) //runs while loop as long as index is within max data points range and stores dates and west elevation data into their respective arrays while storing the rest of the data into junk
    {
        if (date_array[index] == date1) //if the hardcoded date1 equals a date in the file
        {
            startWrite = true; //once it comes across a date equal to date1, bool is true
        }

        if (startWrite) //if startwrite is true
        {
            index++; //start indexing
        }

        if (date_array[index-1] == date2) //if it comes across a date equal to date2
        {
            break; //break out of loop
        }
        // Discard the rest of the columns
        std::getline(fin, junk);
    }

    fin.close();

    for (int i = index - 1; i >= 0; i--)
    {
        std::cout << date_array[i] << " " << westElArray[i] << std::endl; //print in reverse order
    }
}
