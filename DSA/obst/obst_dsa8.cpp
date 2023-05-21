/*

Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each key ki . 
Build the Binary search tree that has the least search cost given the access probability for each key?

*/

#include <iostream>
using namespace std;

int sum(int freq[], int low, int high)
{ // sum of frequency from low to high range
    int sum = 0;
    for (int k = low; k <= high; k++)
        sum += freq[k];
    return sum;
}

int minCostBST(int keys[], int freq[], int n)
{
    int cost[n][n];

    for (int i = 0; i < n; i++) // when only one key, move along diagonal elements
        cost[i][i] = freq[i];

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i <= n - length + 1; i++)
        { // from 0th row to n-length+1 row as i
            int j = i + length - 1;
            cost[i][j] = INT_MAX; // initially store to infinity

            for (int r = i; r <= j; r++)
            {
                // find cost when r is root of subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main()
{
    int keys[] = {10, 12, 20,12};
    int freq[] = {34, 8, 50,9};
    int n = 4;
    cout << "Cost of Optimal BST is: " << minCostBST(keys,freq,n);
}