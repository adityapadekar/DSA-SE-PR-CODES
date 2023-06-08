/*

Consider a scenario for Hospital to cater services to different
kinds of patients as Serious (top priority), b) non-serious (medium priority),
c) General Checkup (Least priority). Implement the priority queue
to cater services to the patients.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class patient
{
public:
    string name;
    int priority;
    patient(int prio, string name) : priority(prio), name(name) {}
};

void swap(vector<patient *> &heap, int u, int v)
{
    patient *temp = heap[u];
    heap[u] = heap[v];
    heap[v] = temp;
}

patient *getData()
{
    string name;
    int prio;
    cout << "Enter the patients name : ";
    cin >> name;
    cout << "Enter priority : ";
    cin >> prio;
    return new patient(prio, name);
}

void push(vector<patient *> &heap, int &n)
{
    patient *temp = getData();
    heap.push_back(temp);
    n++;
    int i = n;
    while (i > 1)
    {
        int parent = i / 2;
        if (heap[parent]->priority < heap[i]->priority)
        {
            swap(heap, parent, i);
            i = parent;
        }
        else
        {
            return;
        }
    }
}

void popUtil(vector<patient*>&heap,int n,int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && heap[left]->priority > heap[largest]->priority){
        largest = left;
    }
    if (right <= n && heap[right]->priority > heap[largest]->priority)
    {
        largest = right;
    }
    if(largest != i){
        swap(heap, i, largest);
        popUtil(heap, n, largest);
    }
}

patient* pop(vector<patient *> &heap, int &n)
{
    // int n = heap.size() - 1;
    patient *temp = heap[n];
    heap.pop_back();
    heap[1] = temp;
    n--;
    popUtil(heap, n, 1);
    return temp;
}

int main()
{
    vector<patient *> heap;
    heap.push_back(new patient(-99999, ""));
    int n = 0;
    push(heap, n);
    push(heap, n);
    push(heap, n);
    push(heap, n);
    push(heap, n);
    cout << n << endl;
    for (int i{1}; i <= n; i++)
    {
        cout << heap[i]->name << endl;
    }
    patient*temp = pop(heap, n);
    cout << "----------------" << endl;
    for (int i{1}; i <= n; i++)
    {
        cout << heap[i]->name << endl;
    }
    return 0;
}