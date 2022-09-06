#pragma once

#include "Processing.hpp"
#include<vector>

class RSD : public Processing{
  private:
    std::vector<std::vector<double>> rsd_res;
    std::vector<std::vector<std::vector<double>>> all_rsd_res;
    std::vector<std::vector<double>> Process(int &, std::vector<double>);

  public:
    void Diff_and_RSD(int, int, std::string, std::string);
    void No_Diff_with_RSD(int, std::string, std::string);
    std::vector<std::vector<double>> get_RSD_result();
    std::vector<std::vector<std::vector<double>>> get_all_RSD_result();
};
