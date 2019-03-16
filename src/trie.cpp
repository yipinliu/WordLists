#include "trie.hpp"
bool Trie::insert(const char* word, int len){
    Trie::Node* cur = root;
    Trie::Node* p = cur;
    for(int i = 0; i < len; i++){
        char c = word[i];
        if(cur->child == nullptr){
            cur->child = new Node[26];
        }
        int index = 0;
        if(c>='a'&&c<='z') index = c - 'a';
        else index = c - 'A';
        cur = &cur->child[index];
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