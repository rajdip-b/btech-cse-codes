#include <iostream>
#include <map>
#include <vector>
using namespace std;

double fractional_knapsack(vector<int> weights, vector<int> values, int items, int size) {
    map<double, pair<double, double>> data; // <fraction, <value, weight>> 
    cout<<"Value\tWeight\tFraction"<<endl;
    for (int x=0;x<items;x++) {
        double value = values[x];
        double weight = weights[x];
        double fraction = value/weight;
        cout<<value<<"\t"<<weight<<"\t"<<fraction<<endl;
        data.insert(make_pair(fraction, make_pair(value, weight)));
    }
    double ans = 0.0;
    for (auto itr = data.rbegin(); itr != data.rend(); itr++) {
        if (size == 0)
            return ans;

        double value = itr->second.first;
        double weight = itr->second.second;

        if (size >= weight) {
            ans += value*(size/(int)weight);
            size %= (int)weight;
        }else {
            ans += value*((double)size/weight);
            return ans;
        }
    }
    return ans;
}

int main() {
    int items, size;
    vector<int> weights, values;
    
    cin>>items>>size;
    for (int x=0;x<items;x++){
        int a, b;
        cin>>a>>b;
        values.push_back(a);
        weights.push_back(b);
    }
    double ans = fractional_knapsack(weights, values, items, size);
    cout<<"\nMax value: "<<ans<<endl;
    return 0;
}