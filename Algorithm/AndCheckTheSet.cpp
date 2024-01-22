#include "AndCheckTheSet.h"

namespace Ricardo {
namespace CheckSet {
int Cheack::Check_find(int i) {
  // 沿途收集的点的个数
  int size = 0;
  // 查找i的代表节点
  while (i != _father[i]) {
    // 当前节点的代表节点不是i，那么就将此节点入栈，用来使并查集扁平化
    _stack[size++] = i;
    i = _father[i];
  }
  // 将栈中记录的节点直接放在代表节点i的下面，实现并查集的扁平化
  while (size > 0) _father[_stack[--size]] = i;
  return i;
}
bool Cheack::Check_isSameSet(int x, int y) {
  // 看查x的代表节点是否与y的代表节点是否相同
  return Check_find(x) == Check_find(y);
}
void Cheack::Check_union(int x, int y) {
  // 分别查询两个节点的代表节点
  int fx = Check_find(x);
  int fy = Check_find(y);
  // 如果两个节点的代表节点不一样就进行合并
  if (fx != fy) {
    // fx,fy代表两个集合的代表元素
    // 将小的集合合并入大的集合下面
    if (_size[fx] >= _size[fy]) {
      _size[fx] += _size[fy];
      _father[fy] = fx;
    } else {
      _size[fy] += _size[fx];
      _father[fx] = fy;
    }
  }
}
void Cheack::Test_Check() {}

Couple::Couple(vector<int> num) : _size(0) {
  _father.resize(31, 0);
  cout << minSwapsCouples(num) << endl;
}
int Couple::minSwapsCouples(vector<int>& row) {
  // 一共n个人n必为偶数
  int n = row.size();
  // 初始化并查集大小为n/2
  build(n / 2);
  for (int i = 0; i < n; i += 2) {
    // 因为n（n为偶数）与n+1是一对情侣
    // 所以n/2 == (n+1)/2 使之在同一个并查集中
    Union(row[i] / 2, row[i + 1] / 2);
  }
  // 最后返回原来的并查集大小减去交换后的并查集大小，就是总交换次数
  return n / 2 - _size;
}
void Couple::build(int n) {
  for (int i = 0; i < n; i++) {
    _father[i] = i;
  }
  _size = n;
}
int Couple::find(int i) {
  // 递归查找i的代表节点
  if (i != _father[i]) _father[i] = find(_father[i]);
  return _father[i];
}
void Couple::Union(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  // 当两个节点不在同一个集合中，说明需要进行一次交换
  if (fx != fy) {
    // 将其进行合并
    _father[fx] = fy;
    // 并查集大小减1表示交换了一次
    _size--;
  }
}

SimilarStrings::SimilarStrings(vector<string> strs) : _size(0) {
  _father.resize(301, 0);
  cout << numSimilarGroups(strs) << endl;
}

void SimilarStrings::build(int n) {
  for (int i = 0; i < n; i++) {
    _father[i] = i;
  }
  _size = n;
}
int SimilarStrings::find(int i) {
  if (i != _father[i]) i = find(_father[i]);
  return _father[i];
}
void SimilarStrings::Union(int x, int y) {
  int fx = find(x);
  int fy = find(y);
}
int SimilarStrings::numSimilarGroups(vector<string>& strs) {
  int n = strs.size();
  int m = strs[0].size();
  build(n);
  // 枚举每一个单词
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // 先查看这两个单词是否为同一个集合
      if (find(i) != find(j)) {
        int diff = 0;
        // 不在同一个集合就开始统计字母不相同的次数
        for (int k = 0; k < m && diff < 3; k++) {
          // 不相同的次数大于3时，必然不能通过交换两个字母的位置来达到相同
          if (strs[i][k] != strs[j][k]) diff++;
        }
        // 完成后检查不相同的的字母个数，0个表示本身相等，2个表示相似，都进行合并
        // 因为都是字母异位词，所以当两个字母不同时，交换这两个字母必然可以使这两个单词一样
        if (diff == 0 || diff == 2) Union(i, j);
      }
    }
  }
  // 返回并查集的大小就是这个相似字符串组的个数
  return _size;
}

void AllPeople::build(int n, int first) {
  // 先将所有专家初始化在以自己为代表节点的集合中
  for (int i = 0; i < n; i++) father[i] = i;
  // 装甲fitst刚开始是知道专家0的秘密的
  father[first] = 0;
  // 将专家0所在的集合的标记位设置为true表示知道
  secret[0] = true;
}
int AllPeople::find(int i) {
  if (i != father[i]) father[i] = find(father[i]);
  return father[i];
}
void AllPeople::Union(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx != fy) {
    // 将fy集合并入fx集合中
    father[fy] = fx;
    // 改变fx集合知道秘密的情况
    secret[fx] = secret[fx] | secret[fy];
  }
}
vector<int> AllPeople::findAllPeople(int n, vector<vector<int>>& meeting,
                                     int first) {
  build(n, first);
  // 先将会议以开会时间进行升序排序
  sort(meeting.begin(), meeting.end(),
       [](vector<int>& a, vector<int>& b) -> bool { return a[2] < b[2]; });
  // 一共有m场会议
  int m = meeting.size();
  for (int l = 0, r; l < m;) {
    // 找出同一时间的会议
    r = l;
    while (r + 1 < m && meeting[l][2] == meeting[r + 1][2]) r++;
    // 将会议中的专家进行合并
    for (int i = l; i <= r; i++) Union(meeting[i][0], meeting[i][1]);

    for (int i = l, a, b; i <= r; i++) {
      a = meeting[i][0];
      b = meeting[i][1];
      // 如果专家a不知道秘密，那么就将其回复到初始的集合
      if (!secret[find(a)]) father[a] = a;
      if (!secret[find(b)]) father[b] = b;
    }
    // 进行下一个时间点的会议
    l = r + 1;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    // 查询知道秘密的专家
    if (secret[find(i)]) ans.push_back(i);
  }
  return ans;
}

GoodPaths::GoodPaths(vector<int> vals, vector<vector<int>> edges) {
  _father.resize(10001, 0);
  _maxcnt.resize(10001, 0);
  cout << numberOfGoodPaths(vals, edges) << endl;
}

void GoodPaths::build(int n) {
  for (int i = 0; i < n; i++) {
    // 初始，每个结点自己为一个集合，最大值为自己
    _father[i] = i;
    // 当前集合最大值个数为1
    _maxcnt[i] = 1;
  }
}
int GoodPaths::find(int i) {
  // 查询当前集合的代表节点（也就是最大值节点）
  if (i != _father[i]) _father[i] = find(_father[i]);
  return _father[i];
}
int CheckSet::GoodPaths::unoin(int x, int y, const vector<int>& vals) {
  // 查找当前两个结点所在集合的代表结点
  int fx = find(x);
  int fy = find(y);
  // 好路径的个数
  int path = 0;
  // 如果两个结点的最大值不相等，则没有好路径
  // 将较小的一个挂在较大的底下
  if (vals[fx] > vals[fy])
    _father[fy] = fx;
  else if (vals[fx] < vals[fy])
    _father[fx] = fy;
  // 如果一样大，说明可以形成好路径，就记录好路径个数并返回
  else {
    /*
     * 假如x所在的集合有2个最大值
     * y所在的集合有1个最大值
     * 那么，x所在的集合的好路径个数在之前就已经被记录过了
     * 那么，x所在的集合与y所在的集合进行合并的时候其好路径个数就是
     * 集合x的最大值个数乘以集合y的最大值个数，也就是2条好路径*/
    path = _maxcnt[fx] * _maxcnt[fy];
    _father[fx] = fy;
    // 将集合x并入集合y中（谁并谁无所谓）
    _maxcnt[fy] += _maxcnt[fx];
  }
  // 返回得到的好路径个数
  return path;
}
int GoodPaths::numberOfGoodPaths(const vector<int>& vals,
                                 vector<vector<int>>& edges) {
  int n = vals.size();
  /*将edge进行排序，依于每条边中的最大结点值，即取出两条边中各自最大的结点值进行升序*/
  sort(edges.begin(), edges.end(),
       [&vals](vector<int>& a, vector<int>& b) -> bool {
         return std::max(vals[a[0]], vals[a[1]]) <
                std::max(vals[b[0]], vals[b[1]]);
       });
  // 每个节点自己就是一条好路径
  int ans = n;
  // 遍历每条边进行合并
  for (const vector<int>& edge : edges) {
    ans += unoin(edge[0], edge[1], vals);
  }
  return ans;
}

MalwareSpread::MalwareSpread(vector<vector<int>> graph, vector<int> inital) {
  _father.resize(301, 0);
  _cnts.resize(301, 0);
  _infect.resize(301, -1);
  _virus.resize(301, false);
  _size.resize(301, 1);
  cout << minMalwareSpread(graph, inital) << endl;
}
int CheckSet::MalwareSpread::minMalwareSpread(const vector<vector<int>>& graph,
                                              vector<int>& initial) {
  int n = graph.size();
  build(n, initial);
  // 合并非感染源为一个集合
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 如果节点i与节点j之间可以联通，且都没有被感染，就合并为一个集合
      if (graph[i][j] == 1 && !_virus[i] && !_virus[j]) unoin(i, j);
    }
  }
  // 查询感染源附近的结点，并处理感染
  for (int sick : initial) {
    // 遍历每个节点
    for (int neighbor = 0; neighbor < n; neighbor++) {
      // 当前neighbor节点是除sick节点外的另一个节点，且当前neighbor节点不是感染源，且sick节点与neighbor节点之间联通
      if (sick != neighbor && !_virus[neighbor] && graph[sick][neighbor] == 1) {
        // 找到neighbor节点的集合代表元素
        int fn = find(neighbor);
        // 如果此集合没有被感染
        if (_infect[fn] == -1)
          // 那么就设置此集合被一个感染源感染
          _infect[fn] = sick;
        // 否则，如果此集合没有被多个感染源感染，且感染当前集合的感染源与当前感染源不同
        else if (_infect[fn] != -2 && _infect[fn] != sick)
          // 设置当前集合已被多个感染源感染
          _infect[fn] = -2;
      }
    }
  }
  // 遍历每个集合的代表结点
  for (int i = 0; i < n; i++) {
    // 查询只被一个感染源所感染的集合，那么删除这个感染源所能拯救的数据就是加上这个集合的大小
    if (i == find(i) && _infect[i] >= 0) _cnts[_infect[i]] += _size[i];
  }
  // 排序感染源
  sort(initial.begin(), initial.end());
  // 取此感染源能感染的最大的集合的大小
  int ans = initial[0];
  int max = _cnts[ans];
  for (int i : initial) {
    if (_cnts[i] > max) {
      ans = i;
      max = _cnts[i];
    }
  }
  return ans;
}
void MalwareSpread::build(int n, const vector<int>& initial) {
  for (int i = 0; i < n; i++) _father[i] = i;
  // 开始时将感染源所在的集合标记设置为true
  for (int i : initial) _virus[i] = true;
}
int MalwareSpread::find(int i) {
  if (i != _father[i]) _father[i] = find(_father[i]);
  return _father[i];
}
void MalwareSpread::unoin(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx != fy) {
    _father[fx] = fy;
    _size[fy] += _size[fx];
  }
}

Islands::Islands(vector<vector<char>> grid) : sets(0) {
  father.resize(90001, 0);
  cout << numIslands2(grid) << endl;
}
int Islands::numIslands1(vector<vector<char>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  build(n, m, grid);
  // 遍历每个单独的点，将其合并到一个集合中
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0 && grid[i][j] == '1' && grid[i][j - 1] == '1')
        unoin(index(i, j), index(i, j - 1));
      if (i > 0 && grid[i][j] == '1' && grid[i - 1][j] == '1')
        unoin(index(i, j), index(i - 1, j));
    }
  }
  return sets;
}
void Islands::build(int n, int m, vector<vector<char>>& grid) {
  cols = m;
  for (int i = 0; i < n; i++)
    for (int j = 0, idx; j < m; j++)
      if (grid[i][j] == '1') {
        idx = index(i, j);
        father[idx] = idx;
        sets++;
      }
}
int Islands::find(int i) {
  if (i != father[i]) father[i] = find(father[i]);
  return father[i];
}
void Islands::unoin(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  // 合并两个集合，集合总数减1
  if (fx != fy) {
    father[fy] = fx;
    sets--;
  }
}
int Islands::index(int i, int j) { return i * cols + j; }
int Islands::numIslands2(vector<vector<char>>& grid) {
  int n = grid.size(), m = grid[0].size();
  int land = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '1') {
        land++;
        numIslands2_DFS(grid, i, j);
      }
    }
  }
  return land;
}
void Islands::numIslands2_DFS(vector<vector<char>>& grid, int i, int j) {
  if (i < 0 || i == grid.size() || j < 0 && j == grid[0].size() ||
      grid[i][j] != '1')
    return;
  grid[i][j] = '2';
  numIslands2_DFS(grid, i, j - 1);
  numIslands2_DFS(grid, i, j + 1);
  numIslands2_DFS(grid, i - 1, j);
  numIslands2_DFS(grid, i + 1, j);
}

Solve::Solve(vector<vector<char>> grid) { solve(grid); }
void Solve::solve(vector<vector<char>>& board) {
  int n = board.size(), m = board[0].size();
  for (int j = 0; j < m; j++) {
    if (board[0][j] == 'O') dfs(board, n, m, 0, j);
    if (board[n - 1][j] == 'O') dfs(board, n, m, n - 1, j);
  }
  for (int i = 0; i < n; i++) {
    if (board[i][0] == 'O') dfs(board, n, m, i, 0);
    if (board[i][m - 1] == 'O') dfs(board, n, m, i, m - 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'O') board[i][j] = 'X';
      if (board[i][j] == 'F') board[i][j] = 'O';
    }
  }
}
void Solve::dfs(vector<vector<char>>& board, int n, int m, int i, int j) {
  if (i < 0 || i == n || j < 0 || j < m || board[i][j] != 'O') return;
  board[i][j] = 'F';
  dfs(board, n, m, i, j - 1);
  dfs(board, n, m, i, j + 1);
  dfs(board, n, m, i - 1, j);
  dfs(board, n, m, i + 1, j);
}

LargeLand::LargeLand(vector<vector<int>> grid) : sets(0) {
  father.resize(250001, 0);
  size.resize(250001, 0);
  cout << largestIsland(grid) << endl;
}

int LargeLand::largestIsland(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        if (j > 0 && grid[i][j - 1] == 1) Unoin(Index(i, j), Index(i, j - 1));
        if (i > 0 && grid[i - 1][j] == 1) Unoin(Index(i, j), Index(i - 1, j));
        ans = std::max(ans, size[Index(i, j)]);
      }
    }
  }
  std::unordered_map<int, bool> visited;
  int up, down, left, right, merge;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        merge = 0;
        if (i > 0 && grid[i - 1][j] == 1)
          up = Find(Index(i - 1, j));
        else
          up = -1;
        if (i + 1 < n && grid[i + 1][j] == 1)
          down = Find(Index(i + 1, j));
        else
          down = -1;
        if (j > 0 && grid[i][j - 1] == 1)
          left = Find(Index(i, j - 1));
        else
          left = -1;
        if (j + 1 < m && grid[i][j + 1] == 1)
          right = Find(Index(i, j + 1));
        else
          right = -1;
        visited[up] = false;
        visited[down] = false;
        visited[left] = false;
        visited[right] = false;
        if (up != -1) merge += size[up];
        if (down != -1 && !visited[down]) {
          merge += size[down];
          visited[down] = true;
        }
        if (left != -1 && !visited[left]) {
          merge += size[left];
          visited[left] = true;
        }
        if (right != -1 && !visited[right]) {
          merge += size[right];
          visited[right] = true;
        }
        ans = std::max(ans, merge + 1);
      }
    }
  }
  return ans;
}
void LargeLand::Build(int n, int m, vector<vector<int>>& grid) {
  cols = m;
  for (int i = 0; i < n; i++) {
    for (int j = 0, index; j < m; j++) {
      if (grid[i][j] == 1) {
        index = Index(i, j);
        father[index] = index;
        sets++;
        size[index] = 1;
      }
    }
  }
}
int LargeLand::Index(int i, int j) { return i * cols + j; }
int LargeLand::Find(int i) {
  if (i != father[i]) father[i] = Find(father[i]);
  return father[i];
}
void CheckSet::LargeLand::Unoin(int x, int y) {
  int fx = Find(x);
  int fy = Find(y);
  if (fx != fy) {
    father[fy] = fx;
    size[fx] += size[fy];
    sets--;
  }
}
int LargeLand::largestIsland2(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size(), id = 2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (grid[i][j] == 1) largestIsland2_DFS(grid, n, m, i, j, id++);
  vector<int> size(id, 0);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (grid[i][j] > 1) ans = std::max(ans, ++size[grid[i][j]]);
  vector<bool> visited(id, false);
  int up, down, left, right, merge;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (grid[i][j] == 0) {
        up = i > 0 ? grid[i - 1][j] : 0;
        down = i + 1 < n ? grid[i + 1][j] : 0;
        left = j > 0 ? grid[i][j - 1] : 0;
        right = j + 1 < m ? grid[i][j + 1] : 0;
        visited[up] = true;
        merge = 1 + size[up];
        if (!visited[down]) {
          merge += size[down];
          visited[down] = true;
        }
        if (!visited[left]) {
          merge += size[left];
          visited[left] = true;
        }
        if (!visited[right]) {
          merge += size[right];
          visited[right] = true;
        }
        ans = std::max(ans, merge);
        visited[up] = false;
        visited[down] = false;
        visited[left] = false;
        visited[right] = false;
      }
  return ans;
}
void LargeLand::largestIsland2_DFS(vector<vector<int>>& grid, int n, int m,
                                   int i, int j, int id) {
  if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1) return;
  grid[i][j] = id;
  largestIsland2_DFS(grid, n, m, i - 1, j, id);
  largestIsland2_DFS(grid, n, m, i + 1, j, id);
  largestIsland2_DFS(grid, n, m, i, j - 1, id);
  largestIsland2_DFS(grid, n, m, i, j + 1, id);
}

Bricks::Bricks(vector<vector<int>> grid, vector<vector<int>> hits)
    : grid(grid), hits(hits) {
  n = grid.size();
  m = grid[0].size();
  Ricardo::toString(hitBricks(grid, hits));
}

vector<int> Bricks::hitBricks(vector<vector<int>>& grid,
                              vector<vector<int>>& hits) {
  // 1)炮弹所在的位置-1
  // 2)对天花板进行洪水填充
  // 3)时光倒流(逆向处理炮弹)如果炮弹位置+1不为1跳过，此次掉落为0
  // 如果为1，查询上下左右是否有2，将此位置+1，继续洪水填充，计算新增的2，其个数再减1
  // 如果本身在天花板上就直接洪水填充
  int n = grid.size(), m = grid[0].size();
  vector<int> ans(hits.size());
  if (n == 1) return ans;
  for (auto h : hits) grid[h[0]][h[1]]--;
  for (int j = 0; j < m; j++) hitBricks_DFS(0, j);
  for (int i = hits.size() - 1, row, col; i >= 0; i--) {
    row = hits[i][0];
    col = hits[i][1];
    grid[row][col]++;
    if (hitBricks_worth(row, col)) {
      ans[i] = hitBricks_DFS(row, col);
    }
  }
  return ans;
}
int CheckSet::Bricks::hitBricks_DFS(int i, int j) {
  if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1) return 0;
  grid[i][j] = 2;
  return 1 + hitBricks_DFS(i - 1, j) + hitBricks_DFS(i + 1, j) +
         hitBricks_DFS(i, j - 1) + hitBricks_DFS(i, j + 1);
}
bool CheckSet::Bricks::hitBricks_worth(int i, int j) {
  return grid[i][j] == 1 &&
         (i == 0 || (i > 0 && grid[i - 1][j] == 2) ||
          (i + 1 < n && grid[i + 1][j] == 2) ||
          (j > 0 && grid[i][j - 1] == 2) || (j + 1 < m && grid[i][j + 1] == 2));
}

}  // namespace CheckSet
}  // namespace Ricardo
