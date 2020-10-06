#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <optional>

namespace kollision {

     std::optional<std::string> readFile(const std::string& fileName) {

        std::ifstream fileStream(fileName);

        std::stringstream stream;
        std::string line;
        while (getline(fileStream, line))
            stream << line << std::endl;

        std::string output = stream.str();
        return output;

    }

}