#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

std::string const red = "red";
std::string const green = "green";
std::string const blue = "blue";

constexpr uint32_t maxRedForGame = 12;
constexpr uint32_t maxGreenForGame = 13;
constexpr uint32_t maxBlueForGame = 14;

uint32_t getGameID(std::string const & line) {
    std::string id;
    size_t index = 5; // First game digit

    while (std::isdigit(line[index])) {
        id += line[index];
        index++;
    }

    return std::stoi(id);
}

uint32_t getMaxBlocks(std::string const & line, std::string const & match) {
    uint32_t maxValue = 0;
    std::string workingLine = line;

    // We want to have at least something like "3 red" in the line
    while (workingLine.length() >= 5) {
        // Find first occurence of match
        size_t firstMatch = workingLine.find(match, 0);
        if (firstMatch != std::string::npos) {
            // Find the numeric value
            size_t lastNumeric = firstMatch - 2;
            size_t firstNumeric = lastNumeric - 1;
            while (std::isdigit(workingLine[firstNumeric])) {
                firstNumeric--;
            }
            firstNumeric++;
            std::string blockCount = workingLine.substr(firstNumeric, lastNumeric - firstNumeric + 1);

            // Check against known max
            if (std::stoi(blockCount) > maxValue) {
                maxValue = std::stoi(blockCount);
            }

            // Strip the line from the data processed
            workingLine = workingLine.substr(firstMatch + match.length(), std::string::npos);
        } else {
            break;
        }
    }

    return maxValue;
}

uint32_t powerOfLine(std::string const & line) {
    return getMaxBlocks(line, red) * getMaxBlocks(line, green) * getMaxBlocks(line, blue);
}

int main() {
    std::ifstream infile("input.txt");
    std::string line;

    uint32_t total = 0;

    while (std::getline(infile, line))
    {
        total += powerOfLine(line);   
    }
    std::cout << total << std::endl;
}