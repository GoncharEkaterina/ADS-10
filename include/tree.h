// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#endif  // INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 public:
  std::string operator[](int x) const {
  if (x >= cell.size()) {
    return "";
  }
  return cell[x];
  }
    explicit Tree(std::vector<char> item) {
      root = new Node;
      root->item = '*';
      buildTr(root, item);
      newTr(root);
    }

 private:
  std::vector<std::string> cell;
  struct Node {
    char item;
    std::vector<Node*> des;
  };
  Node* root;
  void newTr(Node* root, std::string len) {
    if (!root->des.size()) {
      len = len + (root->item);
      Perm.push_back(len);
      return;
    }
    if (root->item != '*') {
      len = len + (root->item);
    }
    for (unsigned int x = 0; x < (root->des.size()); x++) {
      newTr(root->des[x], len);
    }
  }
  void buildTr(Node* root, std::vector<char> vctr) {
    if (!vctr.size()) {
      return;
    }
    if (root->item != '*') {
      for (auto x = vctr.begin(); x != vctr.end(); x++) {
        if (*x == root->item) {
          vctr.erase(x);
        }
      }
    }
    for (int x = 0; x < vctr.size(); x++) {
      root->des.push_back(new Node);
    }
    for (int x = 0; x < root->des.size(); x++) {
      root->des[x]->item = vctr[x];
    }
    for (unsigned int x = 0; x < root->des.size(); x++) {
      buildTr(root->des[x], vctr);
    }
  }
};
