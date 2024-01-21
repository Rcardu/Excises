#pragma once
#include <memory.h>

#include <algorithm>
#include <climits>
#include <cstddef>
#include <list>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace Ricardo {
// 结点结构
struct TreeNode {
  int _val;
  TreeNode *_left;
  TreeNode *_right;
  TreeNode() : _val(0), _left(nullptr), _right(nullptr) {}
  TreeNode(int val) : _val(val), _left(nullptr), _right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : _val(val), _left(left), _right(right) {}
};

class BinaryTree {
 private:
  TreeNode *_root = nullptr;
  int _size = 0;

 public:
  BinaryTree(int val = 0);
  // 从序列化字符串构造树
  BinaryTree(const std::string &data);
  //  从先中序数组构造树
  BinaryTree(std::vector<int> preorder, std::vector<int> midorder);
  ~BinaryTree();

 private:
  // 建立根节点
  void CreatRoot(int val);

  // 先中序数组构建树算法
  TreeNode *buildTree_(const std::vector<int> &pre, int l1, int r1,
                       const std::vector<int> &in, int l2, int r2,
                       const std::unordered_map<int, int> &map);

  // 反序列化
  TreeNode *deserialize(const std::string &data);
  // 反序列化算法
  TreeNode *redeserialize(std::list<std::string> &Arrardata);

  // 序列化算法
  void redeserialize(const TreeNode *node, std::string &data);

  // 最小深度算法
  int MinLen(TreeNode *node);
  // 最大深度算法
  int MaxLen(TreeNode *node);
  //  判断树是否平衡算法
  bool Banace(TreeNode *node);

  // 是否为完全二叉树算法
  bool isCompleteTree(TreeNode *head);
  // 是否为完全二叉树算法
  int countNodes_f(TreeNode *cur, int level, int h);
  // 左子树深度s
  int mostleft(TreeNode *cur, int level);

  // 最近公共祖先算法
  TreeNode *lowestCommonAncestor_(TreeNode *node, TreeNode *p, TreeNode *q);

 public:
  // 序列化树
  std::string TreetoString(TreeNode *node = nullptr) {
    std::string data;
    node = node ? node : _root;
    redeserialize(node, data);
    return data;
  }
  // ·´反序列化树
  void StringtoTree(const std::string &data) { _root = deserialize(data); }
  // 反序列化返回树
  TreeNode *StringtoTree_val(const std::string &data) {
    return deserialize(data);
  }
  // ´先序中序构建树
  TreeNode *buildTree(const std::vector<int> &preorder,
                      const std::vector<int> &midorder);

  // 插入左结点
  bool Insert_left(TreeNode *node, int val);

  // 插入右结点
  bool Insert_right(TreeNode *node, int val);

  // 删除当前结点及其字树
  bool remove(TreeNode *node);

  // 获取根结点
  const TreeNode *getRoot() const { return _root; }

  // 过去当前结点的值
  const int getNodeVal(TreeNode *node) const {
    return node ? node->_val : INT_MIN;
  }

  // 获取当前结点的左结点
  const TreeNode *getLeft(TreeNode *node) const {
    return node ? node->_left : nullptr;
  }

  // 获取当前结点的右结点
  const TreeNode *getRight(TreeNode *node) const {
    return node ? node->_right : nullptr;
  }

  // 获取当前树的大小
  const int getSize() const { return _size; }

  // 获取树的最小深度
  const int GetMinLen(TreeNode *node = nullptr) {
    return node ? MinLen(node) : MinLen(_root);
  }
  // 获取树的最大深度
  int GetMaxLen(TreeNode *node = nullptr) {
    return node ? MaxLen(node) : MaxLen(_root);
  }
  // 判断树是否平衡
  bool Isbanace(TreeNode *node = nullptr) {
    return node ? Banace(node) : Banace(_root);
  }
  // 左子树的深度
  int countNodes(TreeNode *node = nullptr) {
    return countNodes_f(node ? node : _root, 1, mostleft(node, 1));
  }
  // 最近公共祖先
  TreeNode *lowestCommonAncestor_other(TreeNode *p, TreeNode *q,
                                       TreeNode *node = nullptr) {
    return lowestCommonAncestor_(node ? node : _root, p, q);
  }
};
}  // namespace Ricardo
