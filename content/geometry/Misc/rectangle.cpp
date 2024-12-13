class Solution {
public:
    // consider every two opposite vertices of a rectangle
    int maxRectangleArea(vector<vector<int>>& pts) {
        int n = size(pts);
        if (n < 4) return -1;
        set<pair<int, int>> s;
        for (const auto& p : pts)
            s.insert({p[0], p[1]});
        int res = -1;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (pts[i][0] != pts[j][0] && pts[i][1] != pts[j][1]) {
                    auto p3 = make_pair(pts[i][0], pts[j][1]);
                    auto p4 = make_pair(pts[j][0], pts[i][1]);
                    if (s.count(p3) && s.count(p4)) {
                        int minx = min(pts[i][0], pts[j][0]);
                        int maxx = max(pts[i][0], pts[j][0]);
                        int miny = min(pts[i][1], pts[j][1]);
                        int maxy = max(pts[i][1], pts[j][1]);
                        bool ok = true;
                        for (auto& p : pts)
                            if (minx <= p[0] && p[0] <= maxx && miny <= p[1] && p[1] <= maxy)
                                if (p != pts[i] && p != pts[j] && p != vector<int>{p3.first, p3.second} && p != vector<int>{p4.first, p4.second}) {
                                    ok = false;
                                    break;
                                }
                        if (ok)
                            res = max(res, (maxx - minx) * (maxy - miny));
                    }
                }
        return res;
    }
};