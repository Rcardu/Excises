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
// ���������ṹ
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
  // �����л�������
  BinaryTree(const std::string &data);
  // ��ǰ�������������
  BinaryTree(std::vector<int> preorder, std::vector<int> midorder);
  ~BinaryTree();

private:
  // �������
  void CreatRoot(int val);

  // ����
  TreeNode *buildTree_(const std::vector<int> &pre, int l1, int r1,
                       const std::vector<int> &in, int l2, int r2,
                       const std::unordered_map<int, int> &map);

  // �������л�����ת��Ϊ��
  TreeNode *deserialize(const std::string &data);
  // ����  1,2,5,#,#.....
  TreeNode *redeserialize(std::list<std::string> &Arrardata);

  /*�������л�*/
  void redeserialize(TreeNode *node, std::string &data);

  // ��ȡ������С���
  int MinLen(TreeNode *node);
  // ��ȡ����������
  int MaxLen(TreeNode *node);
  // �ж����Ƿ�ƽ��
  bool Banace(TreeNode *node);

  // �ж��Ƿ�Ϊ��ȫ������
  bool isCompleteTree(TreeNode *head);
  // ��ȫ�������Ľ�����
  int countNodes_f(TreeNode *cur, int level, int h);
  // ������ȫ��������ǰ����������
  int mostleft(TreeNode *cur, int level);

  // �������������������
  TreeNode *lowestCommonAncestor_(TreeNode *node, TreeNode *p, TreeNode *q);

public:
  // ���л���
  std::string TreetoString(TreeNode *node = nullptr) {
    std::string data;
    redeserialize(node ? node : _root, data);
    return data;
  }
  // �����л�����������
  void StringtoTree(const std::string &data) { _root = deserialize(data); }
  TreeNode *StringtoTree_val(std::string &data) { return deserialize(data); }
  // �������������������
  TreeNode *buildTree(const std::vector<int> &preorder,
                      const std::vector<int> &midorder);

  // ��������
  bool Insert_left(TreeNode *node, int val);

  // �����ҽ��
  bool Insert_right(TreeNode *node, int val);

  // ɾ����nodeΪ���ڵ�Ľ�㼰������
  bool remove(TreeNode *node);

  // ���ͷ���
  TreeNode *getRoot() { return _root; }

  // ��ý���ϵ�ֵ
  int getNodeVal(TreeNode *node) { return node ? node->_val : INT_MIN; }

  // �������
  TreeNode *getLeft(TreeNode *node) { return node ? node->_left : nullptr; }

  // ����ҽ��
  TreeNode *getRight(TreeNode *node) { return node ? node->_right : nullptr; }

  // �������������
  int getSize() { return _size; }

  // �����С���
  int GetMinLen(TreeNode *node = nullptr) {
    return node ? MinLen(node) : MinLen(_root);
  }
  // ���������
  int GetMaxLen(TreeNode *node = nullptr) {
    return node ? MaxLen(node) : MaxLen(_root);
  }
  // �ж����Ƿ�ƽ��
  bool Isbanace(TreeNode *node = nullptr) {
    return node ? Banace(node) : Banace(_root);
  }
  // ��ȫ�������Ľ�����
  int countNodes(TreeNode *node = nullptr) {
    return countNodes_f(node ? node : _root, 1, mostleft(node, 1));
  }
  // �������������������
  TreeNode *lowestCommonAncestor_other(TreeNode *p, TreeNode *q,
                                       TreeNode *node = nullptr) {
    return lowestCommonAncestor_(node ? node : _root, p, q);
  }
};
} // namespace Ricardo