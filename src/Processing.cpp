#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include "../include/Utility.hpp"
#include "../include/Processing.hpp"
#include "../include/Differrential.hpp"

std::vector<double> Processing::interval(std::vector<double> &vec_in){
  double y;
  std::vector<double> res;
  for(int i = 0; i <= vec_in.size() - 2; i++){
    y = vec_in[i + 1] - vec_in[i];
    res.push_back(std::abs(y));
  };
  return res;
}
    

void Processing::Diff_no_RSD(int times, std::string expr, std::string x_str){
 
  std::vector<std::tuple<std::string, std::vector<double>>> diff_res;
  std::vector<double> tmp_interval, derivative_result;
  std::string tmp_expr;
  Differrential *d = new Differrential(expr); 

  tie(clean_expr, x_result) = d->getResult(x_str);
  interval_res = interval(x_result);
  diff_res = d->Process(times, x_str);

  for(auto&& tuple : diff_res){
    std::tie(tmp_expr, derivative_result) = tuple;
    all_derivative_expr.push_back(tmp_expr);
    all_derivative_result.push_back(derivative_result);
    tmp_interval = interval(derivative_result);
    multiple_interval.push_back(tmp_interval);
  };

  delete d;
}

void Processing::No_Diff_No_RSD(std::string expr, std::string x_str){

  Polynomial *poly = new Polynomial(expr);
  tie(clean_expr, x_result) = poly->getResult(x_str);
  interval_res = interval(x_result);
  delete poly;
}

std::vector<double> Processing::get_result_props(){
  return x_result;
}

std::vector<double> Processing::getInterval(){
  return interval_res;
}

std::string Processing::getCleanExpr(){
  return clean_expr;
}

std::vector<std::string> Processing::get_All_Derivative_Expr(){
  return all_derivative_expr;
}

std::vector<std::vector<double>> Processing::get_All_Interval(){
  return multiple_interval;
}

std::vector<std::vector<double>> Processing::get_All_Derivative_Result(){
  return all_derivative_result;
}
