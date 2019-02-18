/*
ID: yaagnto2
LANG: C++14
TASK: wormhole
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct point_t {
    int64_t x, y;

    bool operator==(point_t o) {
        return x == o.x && y == o.y;
    }
};

typedef pair<point_t, point_t> pair_t;
int times = 0;

bool pairs_check(const vector<pair_t> &pairs) {

    return true;
}

void rec_fun(vector<point_t> &points, vector<pair_t> &pairs) {
    auto p1 = points.back();
    points.pop_back();

    if (!pairs_check(pairs)) return;
    else if (points.empty()) {
        times++;
        return;
    }

    for (point_t &p2:points) {
        if (p2.y == p1.y) continue;
        pair_t _pair{p1, p2};

        vector<point_t> _points{};
        remove_copy(points.begin(), points.end(), back_inserter(_points), p2);

        vector<pair_t> _pairs{};
        copy(pairs.begin(), pairs.end(), back_inserter(_pairs));

        _pairs.push_back(_pair);
        rec_fun(_points, _pairs);
    }
}

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    size_t n;
    fin >> n;
    vector<point_t> points(n);
    for (size_t i = 0; i < n; i++)
        fin >> points[i].x >> points[i].y;

    vector<pair_t> _{};
    rec_fun(points, _);
    return 0;
}

