/**
 * Definition of a  singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/** Below is th function to delete node */
void deleteNode(struct ListNode* node) {

node->val = node->next->val;

struct ListNode* temp = node->next;
node->next = node->next->next;

temp->next = NULL;
free(temp);
}