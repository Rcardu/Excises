#include "BinaryTree.h"

#include <iostream>
#include <unordered_map>

namespace Ricardo {
BinaryTree::BinaryTree(int val) : _size(0) { CreatRoot(val); }
BinaryTree::BinaryTree(const std::string &data) { StringtoTree(data); }
BinaryTree::BinaryTree(std::vector<int> preorder, std::vector<int> midorder)
    : _size(preorder.size()) {
  _root = buildTree(preorder, midorder);
}
BinaryTree::~BinaryTree() { remove(_root); }

void BinaryTree::CreatRoot(int val) {
  if (_root == nullptr)
    _root = new TreeNode(val);
  else
    _root->_val = val;
  _size = 1;
}

TreeNode *BinaryTree::buildTree_(const std::vector<int> &pre, int l1, int r1,
                                 const std::vector<int> &in, int l2, int r2,
                                 const std::unordered_map<int, int> &map) {
  // 如果索引越界表示当前已达最后一个结点
  if (l1 > r1) return nullptr;
  // 否则从先序表的l1索引取出结点
  TreeNode *head = new TreeNode(pre[l1]);
  // 是最后一个结点
  if (l1 == r1) return head;
  // 取出当前结点在中序表中的位置，以此位置将中序表分开
  auto find = map.find(pre[l1]);
  int index = 0;
  if (find == map.end())
    return nullptr;
  else
    index = find->second;
  // 递归建立左右子树
  // 其左子树索引为(l1+1....index-l2+l1)，计算出左子树的大小再加上当前结点的索引位置就是左子树的最后一个结点的位置
  // 其右子树索引为(find-l2+1+l1....r1)
  head->_left =
      buildTree_(pre, l1 + 1, index - l2 + l1, in, l2, index - 1, map);
  head->_right =
      buildTree_(pre, index - l2 + 1 + l1, r1, in, index + 1, r2, map);
  return head;
}
TreeNode *BinaryTree::buildTree(const std::vector<int> &preorder,
                                const std::vector<int> &midorder) {
  if (preorder.empty() || midorder.empty() ||
      preorder.size() != midorder.size())
    return nullptr;
  std::unordered_map<int, int> map;
  for (int i = 0; i < midorder.size(); i++) map[midorder[i]] = i;
  return buildTree_(preorder, 0, preorder.size() - 1, midorder, 0,
                    midorder.size() - 1, map);
}
bool BinaryTree::Insert_left(TreeNode *node, int val) {
  if (node == nullptr) {
    CreatRoot(val);
    _size = 1;
    return true;
  }
  if (node->_left) {
    node->_left->_val = val;
  } else {
    node->_left = new TreeNode(val);
  }
  _size++;
  return true;
}

bool BinaryTree::Insert_right(TreeNode *node, int val) {
  if (node == nullptr) {
    CreatRoot(val);
    _size = 1;
    return true;
  }
  if (node->_right) {
    node->_right->_val = val;
  } else {
    node->_right = new TreeNode(val);
  }
  _size++;
  return true;
}
bool BinaryTree::remove(TreeNode *node) {
  if (node == nullptr) return true;
  if (remove(node->_left) && remove(node->_right)) {
    delete node;
    node = nullptr;
    return true;
  }
  return false;
}
TreeNode *BinaryTree::deserialize(const std::string &data) {
  std::list<std::string> Arraydata;
  std::string str;

  // 分别取出每个结点
  for (const char &ch : data) {
    if (ch == ',') {
      Arraydata.push_back(str);
      _size++;
      str.clear();
    } else {
      str.push_back(ch);
    }
  }
  // str里剩下的也放进去
  if (!str.empty()) {
    Arraydata.push_back(str);
    _size++;
    str.clear();
  }
  return redeserialize(Arraydata);
}
TreeNode *BinaryTree::redeserialize(std::list<std::string> &Arrardata) {
  // 空结点
  if (Arrardata.front() == "#") {
    Arrardata.erase(Arrardata.begin());
    return nullptr;
  }
  // 将当前结点转成数字
  TreeNode *root = new TreeNode(std::stoi(Arrardata.front()));
  Arrardata.erase(Arrardata.begin());

  // 递归左右子树
  root->_left = redeserialize(Arrardata);
  root->_right = redeserialize(Arrardata);
  return root;
}
void BinaryTree::redeserialize(const TreeNode *node, std::string &data) {
  if (node == nullptr)
    data += "#,";
  else {
    data += std::to_string(node->_val) + ",";
    redeserialize(node->_left, data);
    redeserialize(node->_right, data);
  }
}
int BinaryTree::MinLen(TreeNode *node) {
  if (node == nullptr) return 0;
  if (!node->_left || !node->_right)
    return MinLen(node->_left) + MinLen(node->_right) + 1;
  else
    return std::min(MinLen(node->_left), MinLen(node->_right)) + 1;
}
int BinaryTree::MaxLen(TreeNode *node) {
  if (node == nullptr) return 0;
  return std::max(MaxLen(node->_left), MaxLen(node->_right)) + 1;
}
bool BinaryTree::Banace(TreeNode *node) {
  if (node == nullptr) return true;
  bool ans = Banace(node->_left) && Banace(node->_right);
  if (abs(MaxLen(node->_left) - MaxLen(node->_right)) > 1) return false;
  return ans;
}
bool BinaryTree::isCompleteTree(TreeNode *head) {
  if (head == nullptr) return true;
  int l = 0, r = 0;
  std::queue<TreeNode *> que;
  que.push(head);
  // 当前结点的左边不为空
  bool leaf = false;
  while (!que.empty()) {
    TreeNode *ptr = que.front();
    que.pop();
    // 当前结点的左孩子不在右孩子在，或者当前结点的左边没有结点,并且左孩子或者右孩子不为空，就不是完全二叉树
    if ((ptr->_left == nullptr && ptr->_right != nullptr) ||
        (leaf && (ptr->_left != nullptr || ptr->_right != nullptr))) {
      return false;
    }
    // 左右孩子入队
    if (ptr->_left) {
      que.push(ptr->_left);
    }
    if (ptr->_right) {
      que.push(ptr->_right);
    }
    // 当前结点的左右孩子有一个为空，设置标记true
    if (ptr->_left == nullptr || ptr->_right == nullptr) {
      leaf = true;
    }
  }
  return true;
}
int BinaryTree::countNodes_f(TreeNode *cur, int level, int h) {
  if (level == h) return 1;
  if (mostleft(cur->_right, level + 1) == h) {
    int num = ((1 << (h - level)) + countNodes_f(cur->_right, level + 1, h));
    return num;
  } else {
    int num = ((1 << (h - level - 1)) + countNodes_f(cur->_left, level + 1, h));
    return num;
  }
}
int BinaryTree::mostleft(TreeNode *cur, int level) {
  while (cur != nullptr) {
    level++;
    cur = cur->_left;
  }
  return level - 1;
}
TreeNode *BinaryTree::lowestCommonAncestor_(TreeNode *node, TreeNode *p,
                                            TreeNode *q) {
  // 如果为空或者找到了，直接返回当前结点为最近公共祖先
  if (node == nullptr || node == p || node == q) return node;
  // 去左右子树递归寻找
  TreeNode *l = lowestCommonAncestor_(node->_left, p, q);
  TreeNode *r = lowestCommonAncestor_(node->_right, p, q);
  // 如果左右子树的返回结点都不为空，返回当前结点为当前子树的结果
  if (l != nullptr && r != nullptr) return node;
  // 如果都为空返回空
  if (l == nullptr && r == nullptr) return nullptr;
  // 有一个不为空返回不为空的那个
  if (l != nullptr)
    return l;
  else
    return r;
}

}  // namespace Ricardo
