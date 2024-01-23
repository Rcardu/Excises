#include "ArithmeticProgression.h"

namespace Ricardo {
Arithmetic::Arithmetic(std::vector<std::vector<int>> bookings) {
  arr.resize(MAXN, 0);
  Random<int> cle;
  toString(corpFlightBookings(bookings, 5));
}
std::vector<int> Arithmetic::corpFlightBookings(
    std::vector<std::vector<int>>& bookings, int n) {
  std::vector<int> cnt(n + 2);
  for (std::vector<int> book : bookings) {
    /*每组的前缀加上boo[2]*/
    cnt[book[0]] += book[2];
    /*每组的后缀减去book[2]*/
    cnt[book[1] + 1] -= book[2];
  }
  // 对差分数组求前缀和
  for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
  // 生成结果数组
  std::vector<int> ans(n);
  for (int i = 0; i < n; i++) ans[i] = cnt[i + 1];
  return ans;
}

Seqence::Seqence() {
  arr.resize(MAXN, 0);
  std::cin >> n;
  std::cin >> m;
  while (m--) {
    int l, r, s, e;
    std::cin >> l;
    std::cin >> r;
    std::cin >> s;
    std::cin >> e;
    setOut(l, r, s, e, (e - s) / (r - l));
  }
  build(n);
  int Max = INT_MIN, Xor = 0;
  for (int i = 1; i <= n; i++) {
    Max = std::max(Max, arr[i]);
    Xor ^= arr[i];
  }
  std::cout << Xor << " " << Max << std::endl;
}
void Seqence::build(int n) {
  for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
  for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
}
void Seqence::setOut(int l, int r, int s, int e, int d) {
  arr[l] += s;
  arr[l + 1] += (d - s);
  arr[r + 1] -= (d + e);
  arr[r + 2] += e;
}

LycanthropyInBack::LycanthropyInBack() {
  arr.resize(MAXN + 2 * OFFSET, 0);
  std::cin >> n;
  std::cin >> m;
  while (n--) {
    int v, x;
    std::cin >> v;
    std::cin >> x;
    fall(v, x);
  }
  build(m);
  int start = OFFSET + 1;
  std::cout << arr[start++] << " ";
  for (int i = 2; i <= m; i++) std::cout << arr[start++] << " ";
  std::cout << std::endl;
}
void LycanthropyInBack::setOut(int l, int r, int s, int e, int d) {
  arr[l + OFFSET] += s;
  arr[l + OFFSET + 1] += (d - s);
  arr[r + OFFSET + 1] -= (d + e);
  arr[r + OFFSET + 2] += e;
}
void LycanthropyInBack::fall(int v, int x) {
  setOut(x - 3 * v + 1, x - 2 * v, 1, v, 1);
  setOut(x - 2 * v + 1, x, v - 1, -v, -1);
  setOut(x + 1, x + 2 * v, -v + 1, v, 1);
  setOut(x + v * 2 + 1, x + 3 * v - 1, v - 1, 1, -1);
}
void LycanthropyInBack::build(int m) {
  for (int i = 1; i <= m + OFFSET; i++) arr[i] += arr[i - 1];
  for (int i = 1; i <= m + OFFSET; i++) arr[i] += arr[i - 1];
}

PossibleStamp::PossibleStamp(std::vector<std::vector<int>> grid) {
  std::cout << possibleToStamp(grid, 2, 2) << std::endl;
}
bool PossibleStamp::possibleToStamp(std::vector<std::vector<int>>& grid,
                                    int stampHeight, int stampWidth) {
  int n = grid.size();
  int m = grid[0].size();
  // 当前网格的前缀和
  std::vector<std::vector<int>> sum(n + 1, std::vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum[i + 1][j + 1] = grid[i][j];
    }
  }
  Build(sum);
  std::vector<std::vector<int>> diff(n + 2, std::vector<int>(m + 2, 0));
  for (int a = 1, c = a + stampHeight - 1; c <= n; a++, c++) {
    for (int b = 1, d = b + stampWidth - 1; d <= m; b++, d++) {
      // 判断从(a,b)到(c,d)范围内能不能贴邮票
      // c=a+hight-1   d=b+Width-1
      // 即，(a,b)到(c,d)范围内的前缀和是否为0
      if (sumRegion(sum, a, b, c, d) == 0) {
        Add(diff, a, b, c, d);
      }
    }
  }
  Build(diff);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (diff[i + 1][j + 1] == 0 && grid[i][j] == 0) return false;
    }
  }
  return true;
}
void PossibleStamp::Build(std::vector<std::vector<int>>& sum) {
  for (int i = 1; i < sum.size(); i++)
    for (int j = 1; j < sum[i].size(); j++)
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
}
int PossibleStamp::sumRegion(std::vector<std::vector<int>> sum, int a, int b,
                             int c, int d) {
  return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
}
void PossibleStamp::Add(std::vector<std::vector<int>>& diff, int a, int b,
                        int c, int d) {
  diff[a][b] += 1;
  diff[a][d + 1] -= 1;
  diff[c + 1][b] -= 1;
  diff[c + 1][d + 1] += 1;
}

FieldOfGreatestBlessing ::FieldOfGreatestBlessing(
    std::vector<std::vector<int>> grid) {
  std::cout << fieldOfGreatestBlessing(grid) << std::endl;
}
int FieldOfGreatestBlessing ::fieldOfGreatestBlessing(
    std::vector<std::vector<int>>& forceField) {
  int n = forceField.size();
  std::vector<long> xs(2 * n, 0);
  std::vector<long> ys(2 * n, 0);
  for (int i = 0, p = 0, k = 0; i < n; i++) {
    long x = forceField[i][0];
    long y = forceField[i][1];
    long r = forceField[i][2];
    xs[p++] = (x << 1) - r;
    xs[p++] = (x << 1) + r;
    ys[k++] = (y << 1) - r;
    ys[k++] = (y << 1) + r;
  }
  int Sizex = Sort(xs);
  int Sizey = Sort(ys);
  std::vector<std::vector<int>> diff(Sizex + 2, std::vector<int>(Sizey + 2, 0));
  for (int i = 0, a, b, c, d; i < n; i++) {
    long x = forceField[i][0];
    long y = forceField[i][1];
    long r = forceField[i][2];
    a = Rank(xs, (x << 1) - r, Sizex);
    b = Rank(ys, (y << 1) - r, Sizey);
    c = Rank(xs, (x << 1) + r, Sizex);
    d = Rank(ys, (y << 1) + r, Sizey);
    Add(diff, a, b, c, d);
  }
  int ans = 0;
  for (int i = 1; i < diff.size(); i++) {
    for (int j = 1; j < diff[0].size(); j++) {
      diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
      ans = std::max(ans, diff[i][j]);
    }
  }
  return ans;
}
void FieldOfGreatestBlessing ::Add(std::vector<std::vector<int>>& diff, int a,
                                   int b, int c, int d) {
  diff[a][b] += 1;
  diff[a][d + 1] -= 1;
  diff[c + 1][b] -= 1;
  diff[c + 1][d + 1] += 1;
}
int FieldOfGreatestBlessing ::Rank(std::vector<long>& nums, long v, int size) {
  int l = 0;
  int r = size - 1;
  int m, ans = 0;
  while (l <= r) {
    m = (l + r) / 2;
    if (nums[m] >= v) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return ans;
}
int FieldOfGreatestBlessing ::Sort(std::vector<long>& nums) {
  sort(nums.begin(), nums.end());
  int size = 1;
  for (int i = 1; i < nums.size(); i++)
    if (nums[i] != nums[i - 1]) nums[size++] = nums[i];
  return size;
}

NumMatrix::NumMatrix(std::vector<std::vector<int>> martix) {
  n = martix.size();
  m = martix[0].size();
  sum.resize(n + 1, std::vector<int>(m + 1, 0));
  for (int i = 1; i < sum.size(); i++) {
    for (int j = 1; j < sum[i].size(); j++) {
      sum[i][j] = martix[i - 1][j - 1];
    }
  }
  for (int i = 1; i < sum.size(); i++) {
    for (int j = 1; j < sum[i].size(); j++) {
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }

  std::cout << sumRegion(2, 1, 4, 3) << std::endl;
  std::cout << sumRegion(1, 1, 2, 2) << std::endl;
  std::cout << sumRegion(1, 2, 2, 4) << std::endl;
}
int NumMatrix::sumRegion(int row1, int col1, int row2, int col2) {
  return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] +
         sum[row1][col1];
}

LargestBorderedSquare ::LargestBorderedSquare(
    std::vector<std::vector<int>> grid) {
  std::cout << largestBorderedSquare(grid) << std::endl;
}
int LargestBorderedSquare::Get(std::vector<std::vector<int>>& martix, int i,
                               int j) {
  return (i < 0 || j < 0) ? 0 : martix[i][j];
}
void LargestBorderedSquare::Build(std::vector<std::vector<int>>& martix, int n,
                                  int m) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      martix[i][j] += Get(martix, i - 1, j) + Get(martix, i, j - 1) -
                      Get(martix, i - 1, j - 1);
}
int LargestBorderedSquare::Sum(std::vector<std::vector<int>>& martix, int a,
                               int b, int c, int d) {
  return a > c ? 0
               : (martix[c][d] - Get(martix, c, b - 1) - Get(martix, a - 1, d) +
                  Get(martix, a - 1, b - 1));
}
int LargestBorderedSquare::largestBorderedSquare(
    std::vector<std::vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  Build(grid, n, m);
  if (Sum(grid, 0, 0, n - 1, m - 1) == 0) return 0;
  int ans = 1;
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < m; b++) {
      for (int c = a + ans, d = b + ans, k = ans + 1; c < n && d < m;
           c++, d++, k++) {
        if (Sum(grid, a, b, c, d) - Sum(grid, a + 1, b + 1, c - 1, d - 1) ==
            (k - 1) << 2) {
          ans = k;
        }
      }
    }
  }
  return ans * ans;
}

LGP3397::LGP3397() {
  std::cin >> n;
  std::cin >> m;
  std::vector<std::vector<int>> grid(n + 2, std::vector<int>(n + 2, 0));
  while (m--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    LG_Set(grid, a, b, c, d);
  }
  LG_Add(grid, n, n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << grid[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void LGP3397::LG_Set(std::vector<std::vector<int>>& grid, int a, int b, int c,
                     int d) {
  grid[a][b] += 1;
  grid[a][d + 1] -= 1;
  grid[c + 1][b] -= 1;
  grid[c + 1][d + 1] += 1;
}
void LGP3397::LG_Add(std::vector<std::vector<int>>& grid, int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
    }
  }
}

}  // namespace Ricardo
