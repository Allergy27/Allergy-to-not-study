// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_15\9_2_Convex3D_2287.cpp
 * @date      2025/05/15 14:20:26
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
#define double long double
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

constexpr int N = 2010;
constexpr double eps = 1e-9;

struct Node {
    double x, y, z;
    void shake() {
        auto rand_dbl = [] { return std::rand() / static_cast<double>(RAND_MAX); };
        x += (rand_dbl() - 0.5) * eps;
        y += (rand_dbl() - 0.5) * eps;
        z += (rand_dbl() - 0.5) * eps;
    }
    double len() const { return std::sqrt(x * x + y * y + z * z); }
    Node operator-(const Node& o) const { return {x - o.x, y - o.y, z - o.z}; }
    Node operator*(const Node& o) const { return {y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x}; }
    double dot(const Node& o) const { return x * o.x + y * o.y + z * o.z; }
};

struct Face {
    int v[3];
    Node normal(const std::vector<Node>& A) const { return (A[v[1]] - A[v[0]]) * (A[v[2]] - A[v[0]]); }
    double area(const std::vector<Node>& A) const { return normal(A).len() / 2.0; }
};

void convex_hull_3d(std::vector<Node>& A, double& result) {
    int n = A.size();
    if (n < 3) {
        result = 0.0;
        return;
    }

    std::vector<Face> f = {{0, 1, 2}, {2, 1, 0}};
    std::vector<std::vector<int>> vis(n, std::vector<int>(n, 0));

    auto is_visible = [&A](const Face& face, const Node& point) {
        return (point - A[face.v[0]]).dot(face.normal(A)) > 0;
    };

    for (int i = 3; i < n; ++i) {
        std::vector<Face> new_faces;
        for (auto& face : f) {
            if (!is_visible(face, A[i])) new_faces.push_back(face);
            for (int k = 0; k < 3; ++k) {
                int a = face.v[k], b = face.v[(k + 1) % 3];
                vis[a][b] = is_visible(face, A[i]);
            }
        }

        for (auto& face : f) {
            for (int k = 0; k < 3; ++k) {
                int a = face.v[k], b = face.v[(k + 1) % 3];
                if (vis[a][b] && !vis[b][a]) new_faces.push_back({a, b, i});
            }
        }

        f = std::move(new_faces);
    }

    result = 0.0;
    for (auto& face : f) result += face.area(A);
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n;
        std::cin >> n;
        std::vector<Node> qwq(n);
        for (auto& node : qwq) {
            double x, y, z;
            std::cin >> x >> y >> z;
            node = Node{x, y, z};
            node.shake();
        }
        double ans = 0.0;
        convex_hull_3d(qwq, ans);
        std::cout << std::fixed << std::setprecision(6) << ans << ln;
    };
    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
