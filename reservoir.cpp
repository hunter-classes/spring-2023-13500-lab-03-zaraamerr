#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>
#include "reservoir.h"

double get_east_storage(std::string userdate){
  //Open and read data file

  std::ifstream fin("Current_Reservoir_Levels.tsv"); 
  if (fin.fail()) { 
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }

  //The first line in the file is a header line. 
  //We have to skip it before we get to process the actual data. 
  //We can do that by reading that line into a temporary variable 
  //that we can call junk:

  std::string junk;        // new string variable
  getline(fin, junk);     // read one line from the file 

  //Read file line by line and store the east storage values in an array/vector
  
  std::vector < std::pair < std::string, double >> storage; //create vector that can store a pair of values: date string and east storage double
  std::string extracted_date; //the dates extracted from the tsv file
  double eastSt = 0.0; 

  while(fin >> extracted_date >> eastSt) { 
    // this loop reads the file line-by-line
    storage.push_back(std::make_pair(extracted_date, eastSt)); //adds date and east storage level as pair values to vector
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, //ignoring the remaining columns 
  }
  // Loop through the array to find the match between user date and date extracted from table
  for (const auto& s : storage) { //iterate thru the elements of the vector
    if (s.first == userdate) { //checks to see if date matches user date
      return s.second; //if true, print east storage thats associated w that date
    }
  }

  // If the date is not found, output an error message
  std::cerr << "Error: Invalid date." << std::endl;

  fin.close(); //close tsv file

  return 0; //end

}
double get_min_east() {
  // Open and read data file
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // Exit if failed to open the file
  }

  // Skip the header line
  std::string junk;
  getline(fin, junk);

  // Store east storage data for 2018 in a vector
  std::vector<double> east_storage_2018;
  double eastSt = 0.0;
  while (fin >> junk >> eastSt) {
    east_storage_2018.push_back(eastSt);
    fin.ignore(INT_MAX, '\n');
  }

  fin.close();

  if (east_storage_2018.empty()) { // Check if any data was found for 2018
    std::cerr << "Error: No data found for 2018." << std::endl;
    return 0;
  }

  // Find the minimum east storage in 2018
  double min_east_storage = east_storage_2018[0];
  for (const auto& storage : east_storage_2018) {
    if (storage < min_east_storage) {
      min_east_storage = storage;
    }
  }

  return min_east_storage;
}
