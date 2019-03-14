#include "trie.hpp"
bool Trie::insert(const char* word, int len){
    Node* cur = root;
    Node* p = cur;
    for(int i = 0; i < len; i++){
        char c = word[i];
        if(cur->child == nullptr){
            cur->child = new Node[26];
        }
        cur = &cur->child[c - 'a'];
    }
    if(cur->end) return true;
    cur->end = true;
    return false;
}
void Trie::freeMem(Node* node){
    if(node == nullptr) return;
    if(node->child == nullptr) return;
    for(int i = 0; i < 26; i++){
        freeMem(&node->child[i]);
    }
    delete[] node->child;
}