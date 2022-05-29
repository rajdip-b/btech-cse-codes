#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sortActivity (const pair<int, int> &a, const pair<int, int> &b){
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int main() {
    int n, q;
    vector<pair<int, int>> courses;
    cin>>n>>q;
    while (n--){
        int a, b;
        cin>>a>>b;
        courses.push_back(make_pair(a,b));
    }
    sort(courses.begin(), courses.end(), sortActivity);
    while (q--){
        int start, end, delimEnd, count = 0;
        cin>>start>>end;
        delimEnd = start;
        for (pair<int, int> activity : courses) {
            if (activity.first >= start && activity.second <= end && activity.second >= delimEnd && activity.first >= delimEnd){
                ++count;
                delimEnd = activity.second;
            }
        }
        cout<<count<<endl;
    }
}