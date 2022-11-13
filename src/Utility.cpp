#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include "../include/Utility.hpp"

std::string util::replace_all(std::string words, std::string src, std::string dest){
  if(src.empty()){
    return words;
  };
  
  size_t pos = 0;
  while((pos = words.find(src, pos)) != std::string::npos){
    words.replace(pos, src.length(), dest);
    pos += dest.length();
  };
  return words;
};

std::string util::replace(std::string &s, std::string src, std::string dest){
  size_t pos;
  pos = s.find(src, 0);
  return s.replace(pos, src.length(), dest);
};

std::string util::ltrim(std::string s){
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
};
  
std::string util::rtrim(std::string s){
  s.erase(std::find_if(s.rbegin(), s.rend(),
        std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
};

std::string util::trim(std::string s){
  return util::ltrim(util::rtrim(s));
}

std::string util::clean_space(const std::string &s){
  std::string res;
  for(char const &c : s){
    if(c != ' '){
      res += c;
    };
  };
  return res;
};

std::string util::spacing(const std::string &s) {
  std::string res;
  for (int i = 0; i < s.length(); ++i) {
    if(s[i+1] == '+' || s[i+1] == '-' || s[i] == '+' || s[i] == '-'){
      res += s.substr(i, 1) + " ";
    }else{
      res += s.substr(i, 1);
    };
  };
  
  return res;
};

std::vector<std::string> util::split(const std::string s, char sym){
  std::vector<std::string> res;
  std::string clean_str;
  clean_str = clean_space(s);
  std::stringstream ss(clean_str);
  std::string word;
  while(!ss.eof()){
    getline(ss, word, sym);
    res.push_back(word);
  };
  return res;
};

std::string util::remove(std::string &s, std::string rm){
  return replace_all(s, rm, "");
};

bool util::is_number(const std::string &s){
  std::string::const_iterator it = s.begin();
  while(it != s.end()){
    if(std::isdigit(*it) == true || *it == '.'){
      ++it;
    }else{
      return false;
    };
  };
  return !s.empty() && it == s.end();
};

std::vector<double> util::parse_to_number(const std::string s){
    std::vector<double> res;
    std::string clean_str;
    clean_str = util::clean_space(s);
    std::stringstream ss(clean_str);
    std::string word;
    while(!ss.eof()){
      getline(ss, word, ',');
      res.push_back(std::stoi(word));
    };
    return res;
}

/* 
   -- Not optimized code for learning purposes. Don't use!!
   -- Should use range-based for loop or iterator.

int util::find_element(std::string& words, std::string target) {
	for (size_t i = 0; i <= words.length() - 1; i++) {
		if (words[i] == target[0]) {
			for (size_t j = 0; j <= target.length() - 1; j++) {
				if (words[i + j] == target[j]) {
					if (j == target.length() - 1) {
						return i;
					}
					continue;
				}
				else {
					break;
				};
			};
		};
	};
	return -1;
};

std::vector<int> util::find_all(std::string& words, std::string target) {
	std::vector<int> res_idx;
	for (size_t i = 0; i <= words.length() - 1; i++) {
		if (words[i] == target[0]) {
			for (size_t j = 0; j <= target.length() - 1; j++) {
				if (words[i + j] == target[j]) {
					if (j == target.length() - 1) {
						res_idx.push_back(i);
					};
					continue;
				}
				else {
					break;
				};
			};
		};
	};

	if (res_idx.empty() == 1) {
		res_idx.push_back(-1);
	};
	
	return res_idx;
};

std::string util::replace(std::string& words, std::string src, std::string dest) {
	std::vector<int> pos;
	std::vector<std::string> tmp;
	std::string res, out;
	int curr = 0;
	pos = find_all(words, src);

	if (pos[0] == -1) {
		return words;
	}
	else {
		for (int i : pos) {
			tmp.push_back(words.substr(curr, i));
			curr = i + src.length() - 1;
			if (i == pos.back()) {
				tmp.push_back(words.substr(curr + 1, words.length() - 1));
			};
		};

		if (src.length() == 1) {
			for (std::string words : tmp) {

				res += words;
				if (words != tmp.back()) {
					res += dest;
				};
			};
			for (int i = 0; i <= res.length(); i++) {
				if (res[i] != src[0]) {
					out += res[i];
				};
			};
			return out;
		}
		else {
			for (std::string words : tmp) {
				res += words;
				if (words != tmp.back()) {
					res += dest;
				};
			};
		};

		return res;
	};
};

std::string util::trim(std::string& s) {
	std::vector<int> pos = util::find_all(s, " ");
	for (int i : pos) {
		s.erase(i, 1);
	};
	return s;
};

*/
