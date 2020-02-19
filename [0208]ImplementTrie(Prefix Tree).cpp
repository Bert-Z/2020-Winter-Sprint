#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> next;
    bool is_word;

    // Initialize your data structure here.
    TrieNode(bool b = false) : is_word(b), next(26, nullptr) {}
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for (int i = 0; i < s.size(); ++i)
        {
            if (p->next[s[i] - 'a'] == nullptr)
                p->next[s[i] - 'a'] = new TrieNode();
            p = p->next[s[i] - 'a'];
        }
        p->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != nullptr && p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != nullptr;
    }

private:
    TrieNode *find(string key)
    {
        TrieNode *p = root;
        for (int i = 0; i < key.size() && p != nullptr; ++i)
            p = p->next[key[i] - 'a'];
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */