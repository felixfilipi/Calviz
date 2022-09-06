#include<iostream>
#include<vector>
#include<tuple>
#include "../include/Polynomial.hpp"
#include "../include/Differrential.hpp"
#include "../include/Utility.hpp"
#include "../libs/tinyexpr.h"

std::tuple<std::vector<std::string>, std::vector<std::string>> Differrential::Get_Operator_and_Parse(std::string &s){
  
  std::vector<std::string> tmp, oper, parse_expr, clean_parse;
  size_t pos = 0;

  parse_expr = util::split(s, '+');
  for(int i = 0; i <= parse_expr.size() - 1; i++){
    if((parse_expr[i].find('-', pos)) != std::string::npos){
      tmp = util::split(parse_expr[i], '-');
      for(int j = 0; j <= tmp.size() - 1; j++){
        clean_parse.push_back(tmp[j]); 
        
        if(j != tmp.size() - 1){
          oper.push_back("-");
        };        
      };

    }else{ 
      clean_parse.push_back(parse_expr[i]);
    };

    if(i <= parse_expr.size() - 2){
      oper.push_back("+");
    };

  };
  
  return std::make_tuple(oper, clean_parse);
};

std::vector<std::string> Differrential::Differ_each_parse(std::vector<std::string> Parsed_expr){
  std::vector<std::string> diff_each;
  std::string tmp_str, tmp_coeff, tmp_pow, cf;
  bool found;
  
  for(std::string c : Parsed_expr){
    c = util::trim(c);
    c.find("*x^") != std::string::npos ? found = true : found = false;
    tmp_coeff = c.substr(0, c.find("*x^"));
    
    try{
      tmp_pow = c.substr(c.find("*x^") + 3, c.length());
    }catch(...){
      tmp_pow = "0";
    };
   
    if(util::is_number(tmp_coeff) == true && found == true){
      cf = std::to_string(std::stoi(tmp_coeff) * std::stoi(tmp_pow)) + "*x^" + std::to_string(std::stoi(tmp_pow) - 1);
      diff_each.push_back(cf);
    }else if(util::is_number(tmp_coeff) == true && found == false){
      diff_each.push_back("0");
    }else{
      tmp_str = util::replace_all(c, "x", "1");
      diff_each.push_back(std::to_string((int) te_interp(tmp_str.c_str(), 0)));
    };
  };
  return diff_each;
};

std::string Differrential::Parsed_Diff_to_Expr(std::vector<std::string> Parsed_Diff, std::vector<std::string> Operator){
  
  std::string Expr_Result;
  
  for(int x = 0; x <= Parsed_Diff.size() - 1; x++){
    if(x != Parsed_Diff.size() - 1){
      Expr_Result += Parsed_Diff[x] + " " + Operator[x] + " "; 
    }else{
      Expr_Result += Parsed_Diff[x];
    };
  };

  return Expr_Result;
};

std::vector<std::tuple<std::string, std::vector<double>>> Differrential::Process(int times, std::string x_str){
  std::vector<std::string> Operator, Parse, Diff_Parse, Differ_Expr;
  std::vector<std::tuple<std::string, std::vector<double>>> res_vec;
  std::string Result, curr_expr;

  // Preprocess 
  curr_expr = preprocessing(expression);

  for(int i = 1; i <= times; i++){
    
    tie(Operator, Parse) = Get_Operator_and_Parse(curr_expr); 
    Diff_Parse = Differ_each_parse(Parse);
    Result = Parsed_Diff_to_Expr(Diff_Parse, Operator);
    Differ_Expr.push_back(Result);
    curr_expr = Result;
  };

  for(std::string e : Differ_Expr){
    res_vec.push_back(getResult(x_str, e));
  };

  return res_vec;
};
