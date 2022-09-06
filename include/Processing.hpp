#pragma once

#include<iostream>
#include<vector>
#include<tuple>

class Processing{
  protected:
    std::string clean_expr;
    std::vector<double> interval_res, x_result;
    std::vector<std::string> all_derivative_expr;
    std::vector<std::vector<double>> multiple_interval, all_derivative_result;
    std::vector<double> interval(std::vector<double> &);

  public:
    void Diff_no_RSD(int, std::string, std::string);
    void No_Diff_No_RSD(std::string, std::string);
    std::vector<double> get_result_props();
    std::vector<double> getInterval();
    std::string getCleanExpr();
    std::vector<std::string> get_All_Derivative_Expr();
    std::vector<std::vector<double>> get_All_Interval();
    std::vector<std::vector<double>> get_All_Derivative_Result();
};

