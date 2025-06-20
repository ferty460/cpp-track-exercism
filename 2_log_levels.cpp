#include <string>

namespace log_line {

    std::string message(std::string line) {
        int mess_index = line.find(": ");

        return line.substr(mess_index + 2, line.size() - 1);
    }

    std::string log_level(std::string line) {
        int mess_index = line.find(": ");

        return line.substr(1, mess_index - 2);
    }

    std::string reformat(std::string line) {
        return message(line) + " (" + log_level(line) + ")";
    }

}