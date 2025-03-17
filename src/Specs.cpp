#include "Specs.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>

Specs::Specs() {}

Specs::Specs(const std::filesystem::path& filepath) { parseFromFile(filepath); }

void Specs::parseFromFile(const std::filesystem::path& filepath) {
  std::fstream file(filepath);

  if (!file.is_open()) {
    std::cerr << "Unable to open file " << filepath << std::endl;
    exit(1);
  }

  // Skip useless lines
  std::string line;
  while (std::getline(file, line) && (line != "begin")) {}

  // Parse widths and heights until it reached end
  int begin, sep, end, width, height;
  while (std::getline(file, line) && (line != "end")) {
    if ((begin = line.find("~~")) == -1) continue;
    if ((sep = line.find("!-!")) == -1) continue;
    if ((end = line.find("??")) == -1) continue;

    // Has begin, has separator, has end -> CORRECT FORMAT
    width = std::stoi(line.substr(begin + 2, sep - begin - 2));
    height = std::stoi(line.substr(sep + 3, end - sep - 3));
    widths.push_back(width);
    heights.push_back(height);
  }

  if (widths.size() == 0 || heights.size() == 0) {
    std::cerr << "Nothing valid to parse found in " << filepath << std::endl;
    exit(1);
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
