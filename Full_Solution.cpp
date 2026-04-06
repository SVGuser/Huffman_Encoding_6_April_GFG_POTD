#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        if (l->freq == r->freq) return l->data > r->data;
        return l->freq > r->freq;
    }
};

class Solution {
  public:
    void getCodes(MinHeapNode* root, string str, vector<string>& ans) {
        if (!root) return;
        if (root->data != '$') ans.push_back(str.empty() ? "0" : str);
        getCodes(root->left, str + "0", ans);
        getCodes(root->right, str + "1", ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
        for (int i = 0; i < N; ++i) {
            minHeap.push(new MinHeapNode(S[i], f[i]));
        }
        if (minHeap.size() == 1) return {"0"};
        while (minHeap.size() > 1) {
            MinHeapNode* left = minHeap.top(); minHeap.pop();
            MinHeapNode* right = minHeap.top(); minHeap.pop();
            MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            minHeap.push(top);
        }
        vector<string> ans;
        getCodes(minHeap.top(), "", ans);
        return ans;
    }
};

int main() {
    // Example test case
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = f.size();

    Solution ob;
    vector<string> ans = ob.huffmanCodes(S, f, N);

    cout << "Huffman Codes:\n";
    for (auto &code : ans) {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}
