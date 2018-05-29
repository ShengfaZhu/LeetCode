// A linked list is given such that each node contains an additional 
// random pointer which could point to any node in the list or null.
// Return a deep copy of the list.
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode *copyRandomList(RandomListNode *head, unordered_map<int, RandomListNode*>& map) {
    if (head == NULL) return NULL;
    if (map.find(head->label) != map.end()) return map[head->label];
    RandomListNode *node = new RandomListNode(head->label);
    map[head->label] = node;
    node->next = copyRandomList(head->next, map);
    node->random = copyRandomList(head->random, map);
    return node;
}
RandomListNode *copyRandomList(RandomListNode *head) {
    unordered_map<int, RandomListNode*> map;
    return copyRandomList(head, map);
}