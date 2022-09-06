#include<iostream>
#include<vector>
#include<tuple>
#include "../include/Polynomial.hpp"
#include "../include/Utility.hpp"
#include "../libs/tinyexpr.h"

Polynomial::Polynomial(std::string expr){
  expression = expr;
};

std::string Polynomial::preprocessing(std::string expr) {
	std::string res, tmp;
	res = util::trim(expr);
  res = util::clean_space(res);

  for(int i = 0; i <= res.length(); i++){
    if(res[i] == 'x' && std::isdigit(res[i-1])){
      tmp += '*';
    };

    tmp += res[i];
  };
  
  res = util::replace_all(tmp, "**", "^");
  res = util::replace_all(res, "X", "x");
	res = util::replace_all(res, "+0", "");
	res = util::replace_all(res, "-0", "");
	res = util::replace_all(res, "+-", "-");
	res = util::replace_all(res, "*x^0", "");
	res = util::replace_all(res, "-+", "-");
	res = util::replace_all(res, "--", "+");
  res = util::spacing(res);
	return res;
};

std::tuple<std::string, std::vector<double>> Polynomial::getResult(std::string x_str) {
  std::string clean, clean_expr;
  std::vector<double> res;
  
  x_in = util::split(x_str, ',');
  clean_expr = preprocessing(expression);
  for(std::string x : x_in){
    clean = util::replace_all(clean_expr, "x", x);
    res.push_back(te_interp(clean.c_str(), 0));
  };

  return std::make_tuple(clean_expr, res);
};

std::tuple<std::string, std::vector<double>> Polynomial::getResult(std::string x_str, std::string expr) {
  std::string clean, clean_expr;
  std::vector<double> res;
  
  x_in = util::split(x_str, ',');
  clean_expr = preprocessing(expr);
  for(std::string x : x_in){
    clean = util::replace_all(clean_expr, "x", x);
    res.push_back(te_interp(clean.c_str(), 0));
  };

  return std::make_tuple(clean_expr, res);
};

