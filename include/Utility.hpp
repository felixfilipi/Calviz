#ifndef UTILITY_H
#define UTILITY_H

#include<iostream>
#include<vector>

namespace util {

	std::string replace_all(std::string, std::string, std::string);
  std::string replace(std::string&, std::string, std::string);
  std::string ltrim(std::string);
  std::string rtrim(std::string);
	std::string trim(std::string);
  std::string clean_space(const std::string &);
	std::string spacing(const std::string &);
  std::vector<std::string> split(const std::string, char);
  std::string remove(std::string &, std::string);
  bool is_number(const std::string &);
  
  template<typename T>
  void print_vector(std::vector<T> vec, std::string delimiter = ", ")
  {
    for(int i = 0; i <= vec.size() - 1; i++){
      if(i != vec.size() - 1){
        std::cout << vec[i] << delimiter;
      }else{
        std::cout << vec[i];
      };
    };
    std::cout << std::endl;
  };

};

#endif
