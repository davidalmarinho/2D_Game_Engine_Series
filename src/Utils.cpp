#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

namespace Utils 
{
  string readFile(string fileName)
  {
    // Open the file if it exists.
    std::ifstream file;
    file.open(fileName);
    if (file.fail()) {
      std::cerr << "Error: Couldn't open the file '" << fileName << "'.\n";

      string emptyString = "";
      return emptyString;
    }

    // Read the file.
    std::stringstream buffer;
    buffer << file.rdbuf();
    string fileContent = buffer.str();
    file.close();

    return fileContent;
  }
}