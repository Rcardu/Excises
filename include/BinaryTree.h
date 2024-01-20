#pragma once
#include <algorithm>
#include <cstddef>
#include <list>
#include <memory.h>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace Ricardo {
// 二叉树结点结构
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
  TreeNode *_root;
  int _size;

public:
  BinaryTree() : _size(0) {}
  BinaryTree(int val);
  // 从序列化构造树
  BinaryTree(const std::string &data);
  // 从前中序遍历构造树
  BinaryTree(std::vector<int> preorder, std::vector<int> midorder);
  ~BinaryTree();

private:
  // 创建结点
  void CreatRoot(int val);

  // 建树
  TreeNode *buildTree_(const std::vector<int> &pre, int l1, int r1,
                       const std::vector<int> &in, int l2, int r2,
                       const std::unordered_map<int, int> &map);

  // 将反序列化的树转化为树
  TreeNode *deserialize(const std::string &data);
  // 形如  1,2,5,#,#.....
  TreeNode *redeserialize(std::list<std::string> &Arrardata);

  /*将树序列化*/
  void redeserialize(TreeNode *node, std::string &data);

  // 获取树的最小深度
  int MinLen(TreeNode *node);
  // 获取树的最大深度
  int MaxLen(TreeNode *node);
  // 判断树是否平衡
  bool Banace(TreeNode *node);

  // 判断是否为完全二叉树
  bool isCompleteTree(TreeNode *head);
  // 完全二叉树的结点个数
  int countNodes_f(TreeNode *cur, int level, int h);
  // 计算完全二叉树当前结点的最大深度
  int mostleft(TreeNode *cur, int level);

  // 二叉树的最近公共祖先
  TreeNode *lowestCommonAncestor_(TreeNode *node, TreeNode *p, TreeNode *q);

public:
  // 序列化树
  std::string TreetoString(TreeNode *node = nullptr) {
    std::string data;
    redeserialize(node ? node : _root, data);
    return data;
  }
  // 反序列化树（建树）
  void StringtoTree(const std::string &data) { _root = deserialize(data); }
  TreeNode *StringtoTree_val(std::string &data) { return deserialize(data); }
  // 从中序和先序建立二叉树
  TreeNode *buildTree(const std::vector<int> &preorder,
                      const std::vector<int> &midorder);

  // 插入左结点
  bool Insert_left(TreeNode *node, int val);

  // 插入右结点
  bool Insert_right(TreeNode *node, int val);

  // 删除以node为根节点的结点及其子树
  bool remove(TreeNode *node);

  // 获得头结点
  TreeNode *getRoot() { return _root; }

  // 获得结点上的值
  int getNodeVal(TreeNode *node) { return node ? node->_val : INT_MIN; }

  // 获得左结点
  TreeNode *getLeft(TreeNode *node) { return node ? node->_left : nullptr; }

  // 获得右结点
  TreeNode *getRight(TreeNode *node) { return node ? node->_right : nullptr; }

  // 获得子树结点个数
  int getSize() { return _size; }

  // 获得最小深度
  int GetMinLen(TreeNode *node = nullptr) {
    return node ? MinLen(node) : MinLen(_root);
  }
  // 获得最大深度
  int GetMaxLen(TreeNode *node = nullptr) {
    return node ? MaxLen(node) : MaxLen(_root);
  }
  // 判断树是否平衡
  bool Isbanace(TreeNode *node = nullptr) {
    return node ? Banace(node) : Banace(_root);
  }
  // 完全二叉树的结点个数
  int countNodes(TreeNode *node = nullptr) {
    return countNodes_f(node ? node : _root, 1, mostleft(node, 1));
  }
  // 二叉树的最近公共祖先
  TreeNode *lowestCommonAncestor_other(TreeNode *p, TreeNode *q,
                                       TreeNode *node = nullptr) {
    return lowestCommonAncestor_(node ? node : _root, p, q);
  }
};
} // namespace Ricardo