#include "BinaryTree.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  using namespace std;

  cout << "start test" << endl;
  Ricardo::BinaryTree tree1(0);
  cout << tree1.getNodeVal(tree1.getRoot()) << endl;

  return 0;
}