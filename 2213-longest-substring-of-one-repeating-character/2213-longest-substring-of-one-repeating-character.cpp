#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    char first_char, last_char;
    int pref, suff, mx;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right, int len_left, int len_right) {
        Node parent;
        parent.first_char = left.first_char;
        parent.last_char = right.last_char;

        // Base max from both children
        parent.mx = max(left.mx, right.mx);
        
        // Base prefix and suffix
        parent.pref = left.pref;
        parent.suff = right.suff;

        // If boundary characters match, attempt to merge across mid
        if (left.last_char == right.first_char) {
            parent.mx = max(parent.mx, left.suff + right.pref);

            if (left.pref == len_left) {
                parent.pref = len_left + right.pref;
            }
            if (right.suff == len_right) {
                parent.suff = len_right + left.suff;
            }
        }

        return parent;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {ch, ch, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void updatePoint(int idx, char ch) {
        update(1, 0, n - 1, idx, ch);
    }

    int getMax() {
        return tree[1].mx;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            st.updatePoint(queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMax();
        }

        return ans;
    }
};