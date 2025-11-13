#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include<unordered_map>

using namespace std;

static string trim_lower(const string &s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    string t = s.substr(a, b - a + 1);
    for (size_t i = 0; i < t.size(); i++)
        t[i] = tolower(t[i]);
    return t;
}

string vec_key(const vector<int>& v) {
    string k;
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) k.push_back(',');
        k += to_string(v[i]);
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;

    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        lines.push_back(line);
    }

    int p = 0;
    while (p < lines.size() && trim_lower(lines[p]) == "") p++;
    if (p >= lines.size()) return 0;

    int N = stoi(lines[p]);
    p++;

    while (p < lines.size() && trim_lower(lines[p]) != "shuffled") p++;
    if (p >= lines.size()) return 0;
    p++;

    auto readN = [&](vector<string> &out) {
        out.clear();
        while (out.size() < N && p < lines.size()) {
            if (trim_lower(lines[p]) != "")
                out.push_back(lines[p]);
            p++;
        }
    };

    vector<string> shuffled, original;
    readN(shuffled);

    while (p < lines.size() && trim_lower(lines[p]) != "original") p++;
    if (p >= lines.size()) return 0;
    p++;

    readN(original);

    unordered_map<string,int> id;
    for (int i = 0; i < N; i++)
        id[original[i]] = i;

    vector<int> start(N), target(N);
    for (int i = 0; i < N; i++) {
        start[i] = id[shuffled[i]];
        target[i] = i;
    }

    if (start == target) {
        cout << 0 << "\n";
        return 0;
    }

    unordered_set<string> vis;
    queue<pair<vector<int>,int> > q;

    vis.insert(vec_key(start));
    q.push(make_pair(start, 0));

    while (!q.empty()) {
        pair<vector<int>,int> cur = q.front();
        q.pop();

        vector<int> seq = cur.first;
        int dist = cur.second;

        int n = seq.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                vector<int> rem;
                for (int t = 0; t < i; t++) rem.push_back(seq[t]);
                for (int t = j + 1; t < n; t++) rem.push_back(seq[t]);

                for (int k = 0; k <= rem.size(); k++) {
                    vector<int> nxt;

                    for (int t = 0; t < k; t++) nxt.push_back(rem[t]);
                    for (int t = i; t <= j; t++) nxt.push_back(seq[t]);
                    for (int t = k; t < rem.size(); t++) nxt.push_back(rem[t]);

                    if (nxt == seq) continue;

                    if (nxt == target) {
                        cout << (dist + 1) << "\n";
                        return 0;
                    }

                    string key = vec_key(nxt);
                    if (vis.count(key)) continue;

                    vis.insert(key);
                    q.push(make_pair(nxt, dist + 1));
                }
            }
        }
    }

    return 0;
}
