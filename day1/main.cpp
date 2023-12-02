#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

bool isOneFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 'o') 
        && (line[offset + 1] == 'n') 
        && (line[offset + 2] == 'e');
}

bool isTwoFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 't') 
        && (line[offset + 1] == 'w') 
        && (line[offset + 2] == 'o');
}

bool isThreeFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 't') 
        && (line[offset + 1] == 'h') 
        && (line[offset + 2] == 'r') 
        && (line[offset + 3] == 'e') 
        && (line[offset + 4] == 'e');
}

bool isFourFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 'f') 
        && (line[offset + 1] == 'o') 
        && (line[offset + 2] == 'u') 
        && (line[offset + 3] == 'r');
}

bool isFiveFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 'f') 
        && (line[offset + 1] == 'i') 
        && (line[offset + 2] == 'v') 
        && (line[offset + 3] == 'e');
}

bool isSixFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 's') 
        && (line[offset + 1] == 'i') 
        && (line[offset + 2] == 'x');
}

bool isSevenFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 's') 
        && (line[offset + 1] == 'e') 
        && (line[offset + 2] == 'v') 
        && (line[offset + 3] == 'e') 
        && (line[offset + 4] == 'n');
}

bool isEightFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 'e') 
        && (line[offset + 1] == 'i') 
        && (line[offset + 2] == 'g') 
        && (line[offset + 3] == 'h') 
        && (line[offset + 4] == 't');
}

bool isNineFrom(std::string const& line, size_t const offset) {
    return (line[offset] == 'n') 
        && (line[offset + 1] == 'i') 
        && (line[offset + 2] == 'n') 
        && (line[offset + 3] == 'e');
}

uint32_t getCorrectionFromLine(std::string const & line) {
    // Extract numeric characters from the line
    std::vector<int> digitsFromString;
    size_t strSize = line.length();

    for (size_t c = 0; c < strSize; ++c) {
        char ch = line[c];
        if (std::isdigit(ch)) {
            digitsFromString.push_back(std::atoi(&ch));
        } else {
            if (isOneFrom(line, c)) {
                digitsFromString.push_back(1);
            } else if (isTwoFrom(line, c)) {
                digitsFromString.push_back(2);
            } else if (isThreeFrom(line, c)) {
                digitsFromString.push_back(3);
            } else if (isFourFrom(line, c)) {
                digitsFromString.push_back(4);
            } else if (isFiveFrom(line, c)) {
                digitsFromString.push_back(5);
            } else if (isSixFrom(line, c)) {
                digitsFromString.push_back(6);
            } else if (isSevenFrom(line, c)) {
                digitsFromString.push_back(7);
            } else if (isEightFrom(line, c)) {
                digitsFromString.push_back(8);
            } else if (isNineFrom(line, c)) {
                digitsFromString.push_back(9);
            }
        }
    }

    std::cout << "From " << line << ": " << std::endl;
    std::cout << "Size is " << strSize << std::endl;

    std::cout << "First is " << digitsFromString.front() << " and last is " << digitsFromString.back() << std::endl;

    return (digitsFromString.front() * 10) + digitsFromString.back();
}

int main() {
    std::ifstream infile("input.txt");
    std::string line;

    uint32_t total = 0;

    while (std::getline(infile, line))
    {
        uint32_t lineTotal = getCorrectionFromLine(line);
        std::cout << lineTotal << std::endl;
        total += lineTotal;
    }

    std::cout << total << std::endl;
}