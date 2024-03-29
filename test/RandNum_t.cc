#include <iostream>
#include <vector>

#include "RandomNum.h"

void test_random() {
  Ricardo::Random<int> ra;
  std::vector<int> rv1 = ra.RandVector(10, 1.0, 20.0, 0);
  std::vector<int> rv2 = ra.RandVector(10, 2.0, 23.0, 0);
  std::cout << Ricardo::toString(rv1) << std::endl;
  std::cout << Ricardo::toString(rv2) << std::endl;

  Ricardo::Random<double> rs;
  std::vector<double> rd1 = rs.RandVectorDifferent(10, 1, 20, 0);
  std::vector<double> rd2 = rs.RandVectorDifferent(10, 2, 23, 0);
  std::cout << Ricardo::toString(rd1) << std::endl;
  std::cout << Ricardo::toString(rd2) << std::endl;

  Ricardo::Random<char> rc;
  std::string rs1 = rc.RandStringa(10, 'a', 'h', 0);
  std::string rs2 = rc.RandStringa(10, 'a', 'z', 0);
  std::cout << rs1 << std::endl;
  std::cout << rs2 << std::endl;

  Ricardo::Random<char> rC;
  std::string rS1 = rC.RandStringa(10, 'A', 'H', 0);
  std::string rS2 = rC.RandStringa(10, 'A', 'Z', 0);
  std::cout << rS1 << std::endl;
  std::cout << rS2 << std::endl;
}

int main(int argc, char** argv) {
  test_random();
  return 0;
}
