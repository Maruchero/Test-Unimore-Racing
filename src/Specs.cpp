#include "Specs.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <numeric>

void Specs::parseFromFile(std::filesystem::path filepath) {
  std::fstream file(filepath);

  if (!file.is_open()) {
    std::cerr << "Unable to open file " << filepath << std::endl;
    exit(1);
  }

  // Skip useless lines
  std::string line;
  while (std::getline(file, line) && (line != "begin")) {
  }

  // Parse widths and heights until it reached end
  while (std::getline(file, line) && (line != "end")) {
    int begin = line.find("~~");
    if (begin != -1) {
      // Has begin
      int sep = line.find("!-!");
      if (sep != -1) {
        // Has separator
        int end = line.find("??");
        if (end != -1) {
          // Has end -> CORRECT FORMAT
          int width = std::stoi(line.substr(begin + 2, sep - begin - 2));
          int height = std::stoi(line.substr(sep + 3, end - sep - 3));
          widths.push_back(width);
          heights.push_back(height);
        }
      }
    }
  }
}

int Specs::getMaxWidth() {
  return *std::max_element(widths.begin(), widths.end());
}

int Specs::getMaxHeight() {
  return *std::max_element(heights.begin(), heights.end());
}

int Specs::getAvgWidth() {
  return std::reduce(widths.begin(), widths.end()) / widths.size();
}

int Specs::getAvgHeight() {
  return std::reduce(heights.begin(), heights.end()) / heights.size();
}
