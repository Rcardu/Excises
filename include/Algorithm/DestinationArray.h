#include "../unltle.h"
class DestinationArray {
 private:
  int NumberPatternSymbol_(int num);

 public:
  void TestNumberPatternSymbol();

 private:
  std::string longestPalindrome_(std::string s);
  std::string longestPalindrome_fll_(std::string s, int n);

 public:
  void TestlongestPalindrome();

 private:
  long long WaysToBuyPensPencils_(int total, int cost1, int cost2);

 public:
  void TestWaysToBuyPensPencils();

 private:
  int captureForts_(std::vector<int>& forts);

 public:
  void TestCaptureForts();
};
