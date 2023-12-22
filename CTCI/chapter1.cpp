#include <iostream>
#include <unordered_map>

// 1.1 Implement algo to determine if a string has all unique characters 

bool isUnique(std::string &str) {
  std::unordered_map<char, int> map; 

  for (int i = 0; i < str.length(); i++) {
    map[str[i]]++; 
  };

  //print
  for (auto j = map.begin(); j != map.end(); j++) {
    if (j->second > 1) {
      return false;
    }
  }
  return true;
}


int main () {
  std::string str = "unique"; 

  if (isUnique(str)) {
      std::cout << "Is unique!" << std::endl; 
  } else {
    std::cout << "Is NOT unique :(" << std::endl;
  }

}


