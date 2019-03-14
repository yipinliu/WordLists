#pragma once
///note: this Trie class write only for this program, not for general purpose
class Trie{
    struct Node{
        Node *child;
        bool end;
        Node():child(nullptr),end(false){}
    };
public:
    Trie():root(new Node){}
    bool insert(const char* word, int len);
    ~Trie(){
        freeMem(root);
        delete root;
    }
private:
    void freeMem(Node* node);
private:
    Node *root;
};