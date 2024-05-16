
#include "unordered_map"
#include "unordered_set"
#include "iostream"
#include "string"

using namespace std;

int main() {
   //创建hash对象
   std::unordered_map<int,std::string> hashTable;
   //添加元素
   hashTable[0]="False";
   hashTable[1]="True";
   //迭代并打印
   for(const auto&node :hashTable){
      std::cout<<"Key="<<node.first<<"Value="<<node.second<<std::endl;
   }
   return 0;

}