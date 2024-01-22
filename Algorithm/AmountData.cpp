#include "AmountData.h"

namespace Ricardo {

AmountData::AmountData() {
  // T组测试数据
  int T;
  std::cout << "要进行几组测试数据： ";
  std::cin >> T;
  while (T--) {
    // n = 技能个数, m = 怪物血量
    int n;
    int m;
    std::cout << "输入技能个数与怪物血量： ";
    std::cin >> n;
    std::cin >> m;
    for (int i = 0; i < n; i++) {
      // 技能伤害，技能双倍伤害阈值
      int kil, blo;
      std::cout << "输入技能伤害与当怪物血量剩余多少时触发当前技能的双倍伤害：";
      std::cin >> kil;
      std::cin >> blo;
      kill.push_back(kil);
      blood.push_back(blo);
    }
    int ans = KillMonsterEverySkillUseOnce_f_(n, 0, m);
    std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;
  }
}

AmountData::AmountData(int n, int m, std::vector<int> &kill,
                       std::vector<int> &blood)
    : kill(kill), blood(blood) {
  int ans = KillMonsterEverySkillUseOnce_f_(n, 0, m);
  std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;
}
int AmountData::KillMonsterEverySkillUseOnce_f_(int n, int i, int r) {
  // 之前的决策让怪兽死了，直接返回使用了多少个技能
  if (r <= 0) return i;
  // 没打死，此条线路不通
  if (i == n) return INT_MAX;
  int ans = INT_MAX;
  for (int j = i; j < n; j++) {
    // 交换当前技能的先后顺序，枚举每一种情况
    KillMonsterEverySkillUseOnce_Swap_(i, j);
    ans = std::min(
        ans,
        KillMonsterEverySkillUseOnce_f_(
            // 当怪物剩余血量大于当前技能双倍伤害时下次剩余血量取原伤害，小于等于则取双倍技能伤害
            n, i + 1, r - (r > blood[i] ? kill[i] : kill[i] * 2)));
    // 还原当前技能的先后顺序，枚举每一种情况
    KillMonsterEverySkillUseOnce_Swap_(i, j);
  }
  return ans;
}
void AmountData::KillMonsterEverySkillUseOnce_Swap_(int i, int j) {
  int temp = kill[j];
  kill[j] = kill[i];
  kill[i] = temp;
  temp = blood[j];
  blood[j] = blood[i];
  blood[i] = temp;
}

SuperPalindRomesInRange::SuperPalindRomesInRange() {
  std::cout << "输入第一个数L： ";
  std::string L, R;
  std::cin >> L;
  std::cout << "输入第二个数R： ";
  std::cin >> R;
  std::cout << superRange_f1(L, R) << std::endl;
}
SuperPalindRomesInRange::SuperPalindRomesInRange(std::string L, std::string R) {
  std::cout << "start" << std::endl;
  std::cout << superRange_f2(L, R) << std::endl;
}
int SuperPalindRomesInRange::superRange_f1(const std::string &left,
                                           const std::string &right) {
  // 先将字符串转换位long类型
  long l = stol(left);
  long r = stol(right);
  // x根号，范围limit
  long limit = (long)sqrt((double)r);
  // seed：枚举量很小 10^18->10^9->10^5
  // seed：奇数长度的回文、偶数长度的回文
  long seed = 1;
  // num：根号x，num^2->x
  long num = 0;
  int ans = 0;
  do {
    // seed：偶数长度的回文数字
    num = superRange_evenEnlarge(seed);
    if (superRange_inRand((unsigned long long)num * num, l, r)) ans++;
    num = superRange_oddEnlarge(seed);
    if (superRange_inRand((unsigned long long)num * num, l, r)) ans++;
    seed++;
    // 如果奇数长度的回文已经超过了范围，那么接下来的回文也肯定不在范围内了
  } while (num < limit);
  return ans;
}
int SuperPalindRomesInRange::superRange_f2(const std::string &left,
                                           const std::string &right) {
  long long l = stoll(left);
  long long r = stoll(right);
  int i = 0;
  for (; i < record.size(); i++) {
    if (record[i] >= l) break;
  }
  int j = record.size() - 1;
  for (; j >= 0; j--) {
    if (record[j] <= r) break;
  }
  return j - i + 1;
}
std::vector<long long> SuperPalindRomesInRange::superRange_outAll(
    long long left, long long right) {
  long long l = left;
  long long r = right;
  // x根号，范围limit
  long long limit = (long long)sqrt((double)r);
  // seed：枚举量很小 10^18->10^9->10^5
  // seed：奇数长度的回文、偶数长度的回文
  long long seed = 1;
  // num：根号x，num^2->x
  long long num = 0;
  int size = 0;
  std::vector<long long> ans;
  do {
    // seed：偶数长度的回文数字
    num = superRange_evenEnlarge(seed);
    if (superRange_inRand((unsigned long long)num * num, l, r)) {
      ans.push_back(num * num);
      size++;
    }
    num = superRange_oddEnlarge(seed);
    if (superRange_inRand((unsigned long long)num * num, l, r)) {
      ans.push_back(num * num);
      size++;
    }
    seed++;
    // 如果奇数长度的回文已经超过了范围，那么接下来的回文也肯定不在范围内了
  } while (num < limit);
  return ans;
}
long long SuperPalindRomesInRange::superRange_evenEnlarge(long long seed) {
  long long ans = seed;
  while (seed) {
    ans = ans * 10 + (seed % 10);
    seed /= 10;
  }
  return ans;
}
long long SuperPalindRomesInRange::superRange_oddEnlarge(long long seed) {
  long long ans = seed;
  seed /= 10;
  while (seed) {
    ans = ans * 10 + (seed % 10);
    seed /= 10;
  }
  return ans;
}
bool SuperPalindRomesInRange::superRange_inRand(unsigned long long num,
                                                long long l, long long r) {
  return num >= l && num <= r && superRange_isPalindrome(num);
}
bool SuperPalindRomesInRange::superRange_isPalindrome(long long num) {
  // 有多少位
  long long offset = 1;
  while (num / offset >= 10) {
    offset *= 10;
  }
  // 首位判断
  while (num != 0) {
    if (num / offset != num % 10) return false;
    // 消掉首位的数字
    num = (num % offset) / 10;
    // 消掉了两位，offset同时消掉两位
    offset /= 100;
  }
  return true;
}

}  // namespace Ricardo
