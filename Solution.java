import java.util.*;

class Node {
    int data;
    int idx;
    Node left, right;

    Node(int data, int idx) {
        this.data = data;
        this.idx = idx;
        this.left = null;
        this.right = null;
    }
}

class Compare implements Comparator<Node> {
    public int compare(Node a, Node b) {
        if (a.data == b.data) {
            return a.idx - b.idx; // smaller idx first
        }
        return a.data - b.data; // smaller freq first
    }
}

class Solution {
    private void solve(Node root, String s, List<String> ans) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            if (s.equals("")) s = "0";
            ans.add(s);
            return;
        }
        solve(root.left, s + "0", ans);
        solve(root.right, s + "1", ans);
    }

    public List<String> huffmanCodes(String S, int[] f) {
        PriorityQueue<Node> minHeap = new PriorityQueue<>(new Compare());
        for (int i = 0; i < f.length; i++) {
            minHeap.add(new Node(f[i], i));
        }

        while (minHeap.size() > 1) {
            Node left = minHeap.poll();
            Node right = minHeap.poll();
            Node node = new Node(left.data + right.data, Math.min(left.idx, right.idx));
            node.left = left;
            node.right = right;
            minHeap.add(node);
        }

        Node root = minHeap.peek();
        List<String> ans = new ArrayList<>();
        solve(root, "", ans);
        return ans;
    }
}
