// 211. Add and Search Word - Data structure design
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/* declaration of trie node */
class TrieNode {
private:
    int R = 26;// 26 children at most
    vector<TrieNode*> link;// links to children
    bool is_end = false;

public:
    TrieNode() {
        link = vector<TrieNode*>(R, NULL);
    }

    void set_end() {
        is_end = true;
    }

    bool End() {
        return is_end;
    }

    bool is_contain_key(char ch) {
        return link[ch - 'a'] != NULL;
    }
    TrieNode* put_char(char ch) {
        TrieNode *node = new TrieNode();
        link[ch - 'a'] = node;
        return node;
    }

    TrieNode* get(char ch) {
        return link[ch - 'a'];
    }

    vector<TrieNode*> get_all_links() {
        vector<TrieNode*> not_null_links;
        for (TrieNode* node : link)
            if (node) not_null_links.push_back(node);
        return not_null_links;
    }
};

/* declaration of trie */
class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        assert(word.empty() == false);
        TrieNode *curr = root;
        for (char ch : word) {
            if (curr->is_contain_key(ch))
                curr = curr->get(ch);  
            else
                curr = curr->put_char(ch);     
        }
        curr->set_end();
    }
    
    /** Returns if the word is in the trie. 
     * "." is wildcard
    */
    bool search(string word, TrieNode* node) {
        if (word.empty()) return node->End();
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                vector<TrieNode*> not_null_links = node->get_all_links();
                bool flag = false;
                for (auto chid : not_null_links)
                    flag = flag || search(word.substr(i+1, word.size() - i - 1), chid);
                return flag;
            }
            else if (node->is_contain_key(word[i]))
                node = node->get(word[i]);
            else return false;
        }
        return node->End();
    }

    bool search(string word) {
        assert(!word.empty());
        return search(word, root);       
    }
};

int main() {
    Trie trie;
    trie.insert("baa");
    cout << trie.search("ba.") << endl;   
    system("pause");
    return 0;
}