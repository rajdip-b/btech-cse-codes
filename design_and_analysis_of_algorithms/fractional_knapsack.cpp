#include <iostream>
#include <map>
#include <vector>
using namespace std;

pair<double, double> fractional_knapsack(vector<int> weights, vector<int> values, int items, int size) {
    map<double, pair<double, double>> data; // <fraction, <value, weight>> 
    cout<<"Value\tWeight\tFraction"<<endl;
    for (int x=0;x<items;x++) {
        double value = values[x];
        double weight = weights[x];
        double fraction = value/weight;
        cout<<value<<"\t"<<weight<<"\t"<<fraction<<endl;
        data.insert(make_pair(fraction, make_pair(value, weight)));
    }
    double ansValue = 0.0, ansWeight = 0.0;
    for (auto itr = data.rbegin(); itr != data.rend(); itr++) {
        if (size == 0)
            break;

        double value = itr->second.first;
        double weight = itr->second.second;

        if (size >= weight) {
            ansValue += value*(size/(int)weight);
            ansWeight += weight*(size/(int)weight);
            size %= (int)weight;
        }else {
            ansValue += value*((double)size/weight);
            ansWeight += weight*((double)size/weight);
            break;
        }
    }
    return make_pair(ansValue, ansWeight);
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
    auto ans = fractional_knapsack(weights, values, items, size);
    cout<<"\nMax value: "<<ans.first<<"\tMax weight: "<<ans.second<<endl;
    return 0;
}