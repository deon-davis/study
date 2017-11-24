#include <iostream>
#include <vector>
#include <map>
#include <string>

int main()
{

std::map<int, std::vector<std::string>> my_map = {
  { 1, { "ali", "Alice" }},
  { 2, { "boo", "Bob" }},
  { 3, { "cat", "Cathy" }}
};


std::map<int, std::vector<std::string>> :: iterator map_itr;
for(map_itr = my_map.begin(); map_itr != my_map.end(); ++map_itr)
{
std::vector<std::string> vect_itr;
vect_itr = map_itr->second;

std::cout<<"first "<<vect_itr[1]<<std::endl;
std::cout<<"zero "<<vect_itr[0]<<std::endl;
}

return 1;
}
