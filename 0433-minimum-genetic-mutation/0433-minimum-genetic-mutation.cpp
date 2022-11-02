class Solution {
public:
    bool edge(const string& a, const string& b) {
        if (a.size() != b.size()) {
            return false;
        }
        int d = 0;
        for (int i = 0; i < a.size(); ++i) {
            d += a[i] != b[i];
        }
        return d == 1;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> genes(bank.begin(), bank.end());
        genes.insert(start);
        
        unordered_map<string, vector<string>> graph;
        for (auto i = genes.begin(); i != genes.end(); ++i) {
            auto j = i;
            for (++j; j != genes.end(); ++j) {
                if (edge(*i, *j)) {
                    graph[*i].push_back(*j);
                    graph[*j].push_back(*i);
                }
            }
        }


        queue<string> q;
        q.push(start);

        int step = 0;
        unordered_set<string> seen;
        seen.insert(start);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                if (q.front() == end) {
                    return step;
                }
                
                for (auto &n : graph[q.front()]) {
                    if (!seen.count(n)) {
                        seen.insert(n);
                        q.push(n);
                    }
                }
                q.pop();
            }
            ++step;
        }
        return -1;
    }
};