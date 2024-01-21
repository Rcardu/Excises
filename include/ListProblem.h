#pragma once
#include <iostream>
#include <sstream>
#include <vector>

namespace Ricardo {

// 结点
struct Node {
  int val;
  Node* next;
  Node() : val(0), next(nullptr){};
  Node(int x) : val(x), next(nullptr){};
  Node(int x, Node* next) : val(x), next(next){};
};
class ListNode {
 public:
  ListNode();
  // 从数组生成链表
  ListNode(const std::vector<int>& nums);
  ListNode(const ListNode& head);
  ~ListNode();

 public:
  // 获取头结点
  const Node* getHead() const { return _head; }
  // 获取当前结点的下一个结点
  const Node* getNext(const Node* node) const { return node->next; }
  // 获取结点长度
  const int getLen() const { return _len; }
  // 获取最后一个结点
  Node* getLastNode() const;
  // 获取当前结点的前一个结点
  Node* getNodeFront(Node* node) const;
  // 添加结点（尾部添加）
  void AddNode(int val);
  // 添加结点到当前结点的后面
  void AddNode(int val, Node* node);
  // 将数组中的数作为结点添加到当前结点的后面
  void AddNode(const std::vector<int>& nums);
  // 将数组中的数作为结点添加到当前结点的后面
  void AddNode(const std::vector<int>& nums, Node* node);
  // 删除最后一个结点
  Node* removeLastNode();
  // 删除当前结点
  Node* removeThisNode(Node* node);
  // 删除链表
  void removeList();

  std::string toString();

 private:
  // 结点长度
  int _len = 0;
  Node* _head = nullptr;
};
}  // namespace Ricardo
