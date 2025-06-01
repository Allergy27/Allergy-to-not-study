/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace template/segment_tree.cpp
 * @date      2025-05-31 14:32:51
 *
 *   ▄████████  ▄█        ▄█          ▄████████    ▄████████    ▄██████▄  ▄██   ▄   
 *  ███    ███ ███       ███         ███    ███   ███    ███   ███    ███ ███   ██▄ 
 *  ███    ███ ███       ███         ███    █▀    ███    ███   ███    █▀  ███▄▄▄███ 
 *  ███    ███ ███       ███        ▄███▄▄▄      ▄███▄▄▄▄██▀  ▄███        ▀▀▀▀▀▀███ 
 *▀███████████ ███       ███       ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ▀▀███ ████▄  ▄██   ███ 
 *  ███    ███ ███       ███         ███    █▄  ▀███████████   ███    ███ ███   ███ 
 *  ███    ███ ███▌    ▄ ███▌    ▄   ███    ███   ███    ███   ███    ███ ███   ███ 
 *  ███    █▀  █████▄▄██ █████▄▄██   ██████████   ███    ███   ████████▀   ▀█████▀  
 *             ▀         ▀                        ███    ███                        
 */
#include<bits/stdc++.h>

template<class T>
struct Info {
    T sum = 0;
    T max = 0;  // Could be initialized to -INF depending on the minimum value needed
    int cnt = 0;
    explicit Info() {}
    explicit Info(T x) : sum(x), max(x), cnt(1) {}
};

Info operator+(const Info &a, const Info &b) {  // Merge operation for combining two Info objects
    Info c;
    c.sum = a.sum + b.sum;
    c.max = std::max(a.max, b.max);
    c.cnt = a.cnt + b.cnt;
    return c;
}

template<class T>
struct SegmentTree {
    int n;
    std::vector<T> tag;
    std::vector<Info> info;

    explicit SegmentTree(int n_) : n(n_), tag(4 * n_), info(4 * n_) {}

    void pull(int p) {  // Update parent node's info from its children
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void add(int p, T v) {              // Apply an update to a node
        tag[p] += v;                    // Accumulate the lazy tag
        info[p].sum += v * info[p].cnt; // Update sum with the value multiplied by count
        info[p].max += v;               // Update max by adding the value
    }

    void push(int p) {            // Propagate lazy tag to children
        add(p << 1, tag[p]);      
        add(p << 1 | 1, tag[p]);
        tag[p] = 0;               // Clear the tag after propagation
    }

    Info query(int p, int l, int r, int tl, int tr) {
        if (l >= tr || r <= tl) return Info();    // No overlap with query range
        if (l >= tl && r <= tr) return info[p];   // Complete overlap with query range
        int m = l + r >> 1;

        push(p);  // Ensure children are up-to-date before querying
        return query(p << 1, l, m, tl, tr) + query(p << 1 | 1, m, r, tl, tr);
    }

    void range_add(int p, int l, int r, int tl, int tr, T v) {
        if (l >= tr || r <= tl) return;           // No overlap with update range
        if (l >= tl && r <= tr) return add(p, v); // Complete overlap with update range
        int m = l + r >> 1;

        push(p);  // Ensure children are up-to-date before updating
        range_add(p << 1, l, m, tl, tr, v);
        range_add(p << 1 | 1, m, r, tl, tr, v);
        pull(p);  // Update current node after children are updated
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {  // Leaf node reached
            info[p] = v;
            return;
        }
        int m = l + r >> 1;
        
        push(p);  // Ensure children are up-to-date before modification
        if (x < m) modify(p << 1, l, m, x, v);
        else modify(p << 1 | 1, m, r, x, v);
        pull(p);   // Update current node after modification
    }

    // Convenience methods for external use
    Info query(int tl, int tr) {
        return query(1, 0, n, tl, tr);
    }
    void range_add(int tl, int tr, T v) {
        range_add(1, 0, n, tl, tr, v);
    }
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }
};

