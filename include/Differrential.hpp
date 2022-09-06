#pragma once

#include<iostream>
#include<vector>
#include<tuple>
#include "Polynomial.hpp"

class Differrential : public Polynomial {
  public:
    Differrential(std::string expr) : Polynomial(expr){};
    std::tuple<std::vector<std::string>, std::vector<std::string>> Get_Operator_and_Parse(std::string &);
    std::vector<std::string> Differ_each_parse(std::vector<std::string>);
    std::string Parsed_Diff_to_Expr(std::vector<std::string>, std::vector<std::string>);
    std::vector<std::tuple<std::string, std::vector<double>>> Process(int, std::string);
};
