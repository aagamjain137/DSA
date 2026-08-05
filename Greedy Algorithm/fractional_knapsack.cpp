#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value, weight;
};
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].weight <= W)
        {
            totalValue += items[i].value;
            W -= items[i].weight;
        }
        else
        {
            double fraction = (double)W / items[i].weight;
            totalValue += items[i].value * fraction;
            break;
        }
    }
    return totalValue;
}
int main()
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    cout << "Maximum value = "
         << fractionalKnapsack(W, items);
    return 0;
}