#include <iostream>
#include <unordered_map>

int N = 4;
int W = 5;

struct Item {
    Item(int w, int v) {
        this->w = w;
        this->v = v;
    }

    int w;
    int v;
};

Item items[] = {{2, 3},
                {1, 2},
                {3, 4},
                {2, 2}};

int V = 0;
std::unordered_map<std::string, int> m;

int dfs(int i, int w) {
    std::string key = std::to_string(i) + "," + std::to_string(w);
    if (m.find(key) != m.end()) {
        return m[key];
    }

    int res;
    if (i == N) {
        res = 0;
    } else if (w < items[i].w) {
        res = dfs(i + 1, w);
    } else {
        res = std::max(dfs(i + 1, w - items[i].w) + items[i].v, dfs(i + 1, w));
    }
    m[key] = res;
    return res;
}


int main() {
    int v = dfs(0, W);

    std::cout << v;
    return 0;
}

