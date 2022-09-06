#pragma once

#include<iostream>
#include<tuple>
#include<vector>

class Polynomial {

protected:
	std::string preprocessing(std::string expr);
  std::vector<std::string> x_in;
  std::string expression;
public:
  Polynomial(std::string);
  std::tuple<std::string, std::vector<double>> getResult(std::string);
  std::tuple<std::string, std::vector<double>> getResult(std::string, std::string);
};
