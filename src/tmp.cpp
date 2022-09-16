////NO DIFF WITH RSD

//  std::vector<double> result;
//  RSD *p = new RSD();
 
//  p->No_Diff_with_RSD(3, "3x^3 + 2x^2 + 2x", "1, 2, 3");

//  std::vector<std::vector<double>> root_squared = p->get_RSD_result();
//  std::vector<std::vector<double>> all_interval = p->get_All_Interval();

//  std::cout << "Your Expression = " << p -> getCleanExpr() << std::endl;
//  std::cout << "Your Result = ";
//  util::print_vector(p->get_result_props());

//  std::cout << "Your Difference = ";
//  util::print_vector(p->getInterval());

//  int i = 1;
//  for(std::vector<double> rsd : root_squared){
//    std::cout << "Your " << i << " RSD = ";
//    util::print_vector(rsd);
//    ++i;
//  };

//  // cleaning
//  delete p;

//// Diff no RSD
//  p->Diff_no_RSD(1, "3x^3 + 2x^2 + 2x", "1, 2, 3");

//  std::vector<std::vector<double>> all_interval = p->get_All_Interval();
//  std::vector<std::string> all_derivative_expr = p->get_All_Derivative_Expr();
//  std::vector<std::vector<double>> all_derivative_result = p->get_All_Derivative_Result();

//  std::cout << "Your Expression = " << p -> getCleanExpr() << std::endl;
//  std::cout << "Your Result = ";
//  util::print_vector(p->get_result_props());

//  std::cout << "Your Difference = ";
//  util::print_vector(p->getInterval());

//  std::cout << "Your derivative expr = ";
//  util::print_vector(all_derivative_expr);

//  for(int i = 0; i <= all_interval.size() - 1; i++){
//    std::cout << "Your " << i + 1 << " Derivative Interval = ";
//    util::print_vector(all_interval[i]);
//  };

//  for(int i = 0; i <= all_derivative_expr.size() - 1; i++){
//    std::cout << "Your " << i + 1 << " derivative result = ";
//    util::print_vector(all_derivative_result[i]);
//  };

