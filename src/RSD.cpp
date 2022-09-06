#include<vector>
#include<cmath>
#include "../include/RSD.hpp"
#include "../include/Polynomial.hpp"
#include "../include/Differrential.hpp"

std::vector<std::vector<double>> RSD::Process(int &times, std::vector<double> val_in) {
  std::vector<std::vector<double>> result;
  std::vector<double> tmp_in;

  // To interval_res props
  tmp_in = interval(val_in);
  
  for(int i = 1; i <= times ; i++){
    
    std::vector<double> tmp_res;  
    for (double x : tmp_in) {
      tmp_res.push_back(std::sqrt(x));
    };
    result.push_back(tmp_res);
    tmp_in = result[i - 1];
  };

  return result;
};

void RSD::Diff_and_RSD(int times, int times_rsd, std::string expr, std::string x_str){
  
  std::vector<std::tuple<std::string, std::vector<double>>> diff_res;
  std::vector<std::vector<double>> rsd_processed;
  std::vector<double> derivative_result, tmp_interval;
  std::string tmp_expr;
  Differrential *d = new Differrential(expr);

  tie(clean_expr, x_result) = d->getResult(x_str);
  interval_res = interval(x_result);

  diff_res = d->Process(times, x_str);  
  for(auto&& tuple : diff_res){
    std::tie(tmp_expr, derivative_result) = tuple;
    all_derivative_expr.push_back(tmp_expr);
    all_derivative_result.push_back(derivative_result);
    rsd_processed = Process(times_rsd, derivative_result);
    all_rsd_res.push_back(rsd_processed);
    tmp_interval = interval(derivative_result);
    multiple_interval.push_back(tmp_interval);

  };

  delete d;
};

void RSD::No_Diff_with_RSD(int times_rsd, std::string expr, std::string x_str){
  
  Polynomial *poly = new Polynomial(expr);
  tie(clean_expr, x_result) = poly->getResult(x_str);
  rsd_res = Process(times_rsd, x_result);

  delete poly;
};

std::vector<std::vector<double>> RSD::get_RSD_result(){
  return rsd_res;
};

std::vector<std::vector<std::vector<double>>> RSD::get_all_RSD_result(){
  return all_rsd_res;
}
