//
// Created by 赵巍 on 2018/7/30.
//

#include <iostream>

void main()
{

}

void staticArg() {
  static double ext = 10.0;
}

void exeStatic() {
  std::cout << ext << std::endl;
}
