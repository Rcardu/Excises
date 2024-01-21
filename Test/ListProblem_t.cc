#include <iostream>

#include "ListProblem.h"

void test_list() {
  Ricardo::ListNode l({1, 2, 5, 3, 8, 7});
  std::cout << "len =" << l.getLen() << std::endl;
  l.AddNode(12);
  std::cout << l.toString() << std::endl;
  l.AddNode({22, 14, 67, 99});
  std::cout << l.toString() << std::endl;
}

int main(int argc, char** argv) {
  test_list();
  return 0;
}
