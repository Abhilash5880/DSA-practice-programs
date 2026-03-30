class TrieNode {
public:
    TrieNode* children[26];
    int idx;
    int refs;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        idx = -1;
        refs = 0;
    }

    void addWord(const string& word, int i) {
        TrieNode* cur = this;
        cur->refs++;
        for (char c : word) {
            int index = c - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
            cur->refs++;
        }
        cur->idx = i;
    }
};

class Solution {
public:
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            root->addWord(words[i], i);
        }

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                dfs(board, root, r, c, words);
            }
        }

        return res;
    }

    void dfs(auto& board, TrieNode* node, int r, int c, auto& words) {
        if (r < 0 || c < 0 || r >= board.size() ||
            c >= board[0].size() || board[r][c] == '*' ||
            !node->children[board[r][c] - 'a']) {
            return;
        }

        char temp = board[r][c];
        board[r][c] = '*';
        TrieNode* prev = node;
        node = node->children[temp - 'a'];
        if (node->idx != -1) {
            res.push_back(words[node->idx]);
            node->idx = -1;
            node->refs--;
            if (!node->refs) {
                prev->children[temp - 'a'] = nullptr;
                node = nullptr;
                board[r][c] = temp;
                return;
            }
        }

        dfs(board, node, r + 1, c, words);
        dfs(board, node, r - 1, c, words);
        dfs(board, node, r, c + 1, words);
        dfs(board, node, r, c - 1, words);

        board[r][c] = temp;
    }
};