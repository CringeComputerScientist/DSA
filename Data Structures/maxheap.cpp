#include <iostream>
#include <climits>
using namespace std;

class maxheap
{
        int *arr;
        int m;
        int s;

public:
        maxheap(int ma)
        {
                m = ma;
                s = 0;
                arr = new int[ma];
        }

        int parent(int n)
        {
                return (n - 1) / 2;
        }

        int leftchild(int n)
        {
                return (2 * n) + 1;
        }
        
        int rightchild(int n)
        {
                return (2 * n) + 2;
        }
        
        int maximum()
        {
                return arr[0];
        }
        
        int size()
        {
                return s;
        }
        
        void check(int i)
        {
                while (i != 0 && arr[parent(i)] < arr[i])
                {
                        swap(arr[i], arr[parent(i)]);
                        i = parent(i);
                }
        }
        
        void insert(int x)
        {
                if (s == m)
                {
                        cout << "overflow error";
                        return;
                }
                int i = s++;
                arr[i] = x;
                check(i);
        }
        
        void delet(int x)
        {
                if (s == 0)
                {
                        cout << "underflow error";
                        return;
                }
                arr[x] = INT_MAX;
                check(x);
        }
        
        void heapify(int i)
        {
                int l = leftchild(i);
                int r = rightchild(i);
                int large = i;
                if (l < m && arr[l] > arr[large])
                {
                        large = l;
                }
                if (r < m && arr[r] > arr[large])
                {
                        large = r;
                }
                if (large != i)
                {
                        swap(arr[i], arr[large]);
                        heapify(large);
                }
        }
        
        int top()
        {
                if (s <= 0)
                {
                        return INT_MIN;
                }
                if (s == 1)
                {
                        return arr[0];
                }
                int temp = arr[0];
                arr[0] = arr[--s];
                heapify(0);
                return temp;
        }
};
