#include <cstdio>
#include <cassert>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * This solution should solve all test groups and get 100 points.
 */

int tshirt(int N, int L[], int H[], int T[]) {
    vector<pair<int,int> > ev;
    for (int i = 0; i < N; i++) {
        ev.push_back(make_pair(L[i], -H[i]));
        ev.push_back(make_pair(T[i], 1));
    }
    sort(ev.begin(), ev.end());
    priority_queue<int, vector<int>, greater<int> > pq;
    int ans = 0;
    for (size_t i = 0; i < ev.size(); i++) {
        if (ev[i].second == 1) {
            while (!pq.empty() && pq.top() < ev[i].first) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans++;
                pq.pop();
            }
        } else {
            pq.push(-ev[i].second);
        }
    }
    return ans;
}

int inputL[100000],
    inputH[100000],
    inputT[100000];

int main() {
    int N;
    ignore = scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        ignore = scanf("%d", &inputL[i]);
    }
    for (int i = 0; i < N; ++i) {
        ignore = scanf("%d", &inputH[i]);
    }
    for (int i = 0; i < N; ++i) {
        ignore = scanf("%d", &inputT[i]);
    }
    printf("%d\n", tshirt(N, inputL, inputH, inputT));
}
