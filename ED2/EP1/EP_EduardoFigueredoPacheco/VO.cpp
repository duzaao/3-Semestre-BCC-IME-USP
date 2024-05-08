#include "VO.h"

int VO::InsereBB(std::vector<Pair>& v, const Pair& x) {
    int l = 0;
    int r = v.size() - 1;
    int m;

    while (l <= r) {
        m = (l + r) / 2;
        if (v[m].first == x.first) {
            v.insert(v.begin() + m, x);
            return m;
        }
        else if (v[m].first < x.first) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    v.insert(v.begin() + l, x);
    return l;
}

Pair* VO::BuscaBB(std::vector<Pair>& v, const std::string& x) {
    int l = 0;
    int r = v.size() - 1;
    int m;

    while (l <= r) {
        m = (l + r) / 2;
        if (v[m].first == x) {
            return &v[m];
        }
        else if (v[m].first < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return nullptr;
}
