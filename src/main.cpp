#include "../include/RSD.hpp"
#include "../include/Utility.hpp"

int main() {

  std::vector<double> result;
  RSD *p = new RSD();
 
  p->Diff_and_RSD(2, 2, "3x^3 + 2x^2 + 2x", "1, 2, 3");


  std::vector<std::vector<double>> all_interval = p->get_All_Interval();
  std::vector<std::string> all_derivative_expr = p->get_All_Derivative_Expr();
  std::vector<std::vector<double>> all_derivative_result = p->get_All_Derivative_Result();
  std::vector<std::vector<std::vector<double>>> root_squared = p->get_all_RSD_result();

  std::cout << "Your Expression = " << p -> getCleanExpr() << std::endl;
  std::cout << "Your Result = ";
  util::print_vector(p->get_result_props());

  std::cout << "Your Difference = ";
  util::print_vector(p->getInterval());

  for(int i = 0; i <= all_derivative_expr.size() - 1; i++){
    std::cout << "Your " << i << " derivative expr = ";
    std::cout << all_derivative_expr[i] << std::endl;  
  };

  for(int i = 0; i <= all_derivative_expr.size() - 1; i++){
    std::cout << "Your " << i + 1 << " derivative result = ";
    util::print_vector(all_derivative_result[i]);
  };

  for(int i = 0; i <= all_interval.size() - 1; i++){
    std::cout << "Your " << i + 1 << " Derivative Interval = ";
    util::print_vector(all_interval[i]);  
  };

  int i = 1;
  for(std::vector<std::vector<double>> rsd_each_derivative : root_squared){
  
    int j = 1;
    for(std::vector<double> each_rsd : rsd_each_derivative){
      std::cout << "Your RSD for " << i << " Derivative & Round " << j << " = ";
      util::print_vector(each_rsd);  
      ++j;
    };
    ++i;
  };

  // cleaning
  delete p;
};

