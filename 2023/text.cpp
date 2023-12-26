#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> spelledOutToNum = {
    {"one", "1"},
    {"two", "2"},
    {"three", "3"},
    {"four", "4"},
    {"five", "5"},
    {"six", "6"},
    {"seven", "7"},
    {"eight", "8"},
    {"nine", "9"}
};

std::string replaceSpelledOutNumbers(const std::string& line) {
    std::string result;
    std::string currentSpelledOut;

    for (char c : line) {
        if (std::isalpha(c)) {
            currentSpelledOut += std::tolower(c);  // Collect characters to form spelled-out number
        } else {
            if (!currentSpelledOut.empty()) {
                auto it = spelledOutToNum.find(currentSpelledOut);
                if (it != spelledOutToNum.end()) {
                    result += it->second;  // Replace spelled-out number with its numeric counterpart
                } else {
                    result += currentSpelledOut;  // Keep non-matching substrings as is
                }
                currentSpelledOut.clear();  // Reset for the next spelled-out number
            }
            result += c;  // Add numeric characters directly to the result
        }
    }

    // Handle the case where the string ends with a spelled-out number
    if (!currentSpelledOut.empty()) {
        auto it = spelledOutToNum.find(currentSpelledOut);
        if (it != spelledOutToNum.end()) {
            result += it->second;
        } else {
            result += currentSpelledOut;
        }
    }

    return result;
}

int main() {
    std::string line = "one2five8six";

    std::string result = replaceSpelledOutNumbers(line);

    std::cout << "Original: " << line << std::endl;
    std::cout << "Modified: " << result << std::endl;

    return 0;
}
