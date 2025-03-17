/*

Implement here the Specs class. It is supposed to have the following methods:
- parseFromFile
- getMaxWidth
- getMaxHeight
- getAvgWidth
- getAvgHeight

*/
#ifndef SPECS_H
#define SPECS_H

#include <filesystem>
#include <vector>

class Specs {
  std::vector<int> widths;
  std::vector<int> heights;

public:
  Specs();
  Specs(const std::filesystem::path& filepath);

  void parseFromFile(const std::filesystem::path& filename);
  int getMaxWidth();
  int getMaxHeight();
  int getAvgWidth();
  int getAvgHeight();
};

#endif  // SPECS_H