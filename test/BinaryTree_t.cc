#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;
void test_creat() {
  vector<int> pro = {0, 1, 3, 7, 10, 4, 2, 5, 8, 6, 9};
  vector<int> inm = {7, 10, 3, 1, 4, 0, 8, 5, 2, 6, 9};
  Ricardo::BinaryTree tree2(pro, inm);
  std::string ss = tree2.TreetoString();
  cout << ss << endl;

  Ricardo::BinaryTree tree3(tree2.TreetoString());
  std::string sss = tree3.TreetoString();
  cout << sss << endl;

  cout << tree3.GetMaxLen() << " " << tree3.GetMinLen() << " " << boolalpha
       << tree3.Isbanace() << endl;
}
int main(int argc, char **argv) {
  test_creat();

  return 0;
}
