#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    bool val;
    vector<TrieNode *> nextchar;
    TrieNode(bool value = false) : val(value), nextchar(26, nullptr) {}
};

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *cur = root;
        for (auto x : word)
        {
            if (cur->nextchar[x - 'a'] == nullptr)
                cur->nextchar[x - 'a'] = new TrieNode();

            cur = cur->nextchar[x - 'a'];
        }
        cur->val = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return search(word, root);
    }

private:
    TrieNode *root;

    bool search(string word, TrieNode *node)
    {
        for (int i = 0; word[i] && node; i++)
        {
            if (word[i] != '.')
            {
                node = node->nextchar[word[i] - 'a'];
            }
            else
            {
                TrieNode *tmp = node;
                for (int j = 0; j < 26; j++)
                {
                    node = tmp->nextchar[j];
                    if (search(word.substr(i + 1), node))
                        return true;
                }
            }
        }
        return node && node->val;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */