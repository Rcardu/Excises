#include "ListProblem.h"

namespace Ricardo {

Node* ListNode::getLastNode() const {
  Node* ptr = _head;
  while (ptr->next) ptr = ptr->next;
  return ptr;
}
// 获取当前结点的前一个结点
Node* ListNode::getNodeFront(Node* node) const {
  Node* ptr = _head;
  while (ptr->next != node) {
    ptr = ptr->next;
  }
  return ptr;
}
// 添加结点（尾部添加）
void ListNode::AddNode(int val) {
  Node* ptr = getLastNode();
  ptr->next = new Node(val);
  _len++;
}
// 添加结点到当前结点的后面
void ListNode::AddNode(int val, Node* node) {
  Node* ptr = node->next;
  node->next = new Node(val);
  node->next->next = ptr;
  _len++;
}
// 将数组中的数作为结点添加到当前结点的后面
void ListNode::AddNode(const std::vector<int>& nums) {
  Node* ptr = getLastNode();
  for (int num : nums) {
    ptr->next = new Node(num);
    ptr = ptr->next;
    _len++;
  }
}
// 将数组中的数作为结点添加到当前结点的后面
void ListNode::AddNode(const std::vector<int>& nums, Node* node) {
  Node* ptr = node->next;
  Node* cur;
  for (int num : nums) {
    node->next = new Node(num);
    cur = node;
    node = node->next;
    _len++;
  }
  cur->next = ptr;
}
// 删除最后一个结点
Node* ListNode::removeLastNode() {
  // 获取最后一个结点的前一个结点
  Node* ptr = getNodeFront(getLastNode());
  Node* cur = ptr->next;
  ptr->next = cur->next;
  return cur;
}
// 删除当前结点
Node* ListNode::removeThisNode(Node* node) {
  Node* ptr = getNodeFront(node);
  Node* cur = ptr->next;
  ptr->next = cur->next;
  return cur;
}
// 删除链表
void ListNode::removeList() {
  Node* ptr = _head->next;
  while (ptr) {
    Node* cur = removeThisNode(ptr);
    ptr = ptr->next;
    delete cur;
    cur = nullptr;
  }
}

ListNode::ListNode() : _len(0) { _head = new Node(); }
// 从数组生成链表
ListNode::ListNode(const std::vector<int>& nums) : _len(0), _head(nullptr) {
  _head = new Node();
  AddNode(nums);
}
ListNode::~ListNode() {
  removeList();
  delete _head;
  _head = nullptr;
}
ListNode::ListNode(const ListNode& head) {
  Node* ptr = head._head;
  _head = new Node();
  Node* cur = this->_head;
  while (ptr->next) {
    cur->next = new Node(ptr->next->val);
    cur = cur->next;
    ptr = ptr->next;
    this->_len++;
  }
}

std::string ListNode::toString() {
  std::stringstream ss;
  Node* ptr = _head->next;
  while (ptr->next) {
    ss << std::to_string(ptr->val) << " -> ";
    ptr = ptr->next;
  }
  ss << std::to_string(ptr->val) << std::endl;
  return ss.str();
}
}  // namespace Ricardo
