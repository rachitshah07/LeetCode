#include <bits/stdc++.h>
using namespace std;

void multi(vector<pair<int, int>> v)
{
    multiset<int> pq;
    for (auto i : v)
    {
        if (pq.empty())
        {
            pq.insert(i.second);
            continue;
        }
        if (*pq.begin() <= i.first)

            pq.erase(pq.begin());

        pq.insert(i.second);
    }
    cout << pq.size() << endl;
}
void priority(vector<pair<int, int>> v)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int c = 0;
    for (auto i : v)
    {
        c++;
        if (pq.empty())
        {
            pq.push(i.second);
            continue;
        }
        if (pq.top() <= i.first)
        {
            cout << pq.top() << " " << i.first << "\n";
            cout << "Accomodate meeting " << c << " in this room\n";
            pq.pop();
        }
        pq.push(i.second);
    }
    cout << pq.size() << endl;
}
int main()
{
    vector<pair<int, int>> v;
    while (1)
    {
        int x, y;
        cin >> x >> y;
        if (x == y && x == -1)
            break;
        v.push_back({x, y});
    }
    // Start time according sort
    sort(v.begin(), v.end());
    multi(v);
    priority(v);
    // for(auto i:pq) {cout<<i<<"\n";}
}
// 65 424
// 351 507
// 314 807 
// 387 722 
// 19 797 
// 259 722
// 165 221
// 136 897
// -1 -1
