/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattened(Node* head, Node* rest = nullptr) {
  if (!head) return rest;
  head->next = flattened(head->child, flattened(head->next, rest));
  if (head->next) head->next->prev = head;
  head->child = nullptr;
  return head;
}
    Node* flatten(Node* head) {
        Node* temp=head;
        flattened(temp);
        return temp;
    }
};