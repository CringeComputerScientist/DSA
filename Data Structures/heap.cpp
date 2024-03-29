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

        void array()
        {
                for (int i = 0; i < s; i++)
                {
                        cout << arr[i] << " ";
                }
        }

        void heapifyUp(int i)
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
                heapifyUp(i);
        }

        void delet(int x)
        {
                if (s == 0)
                {
                        cout << "underflow error";
                        return;
                }
                arr[x] = arr[s - 1];
                arr[--s] = 0;
                heapifyDown(x);
        }

        void heapifyDown(int i)
        {
                int l = leftchild(i);
                int r = rightchild(i);
                int large = i;
                if (l < s && arr[l] > arr[large])
                {
                        large = l;
                }
                if (r < s && arr[r] > arr[large])
                {
                        large = r;
                }
                if (large != i)
                {
                        swap(arr[i], arr[large]);
                        heapifyDown(large);
                }
        }

        int top()
        {
                if (s <= 0)
                {
                        return NULL;
                }
                if (s == 1)
                {
                        return arr[--s];
                }
                int temp = arr[0];
                arr[0] = arr[--s];
                heapifyDown(0);
                return temp;
        }
};

class minheap
{
        int *arr;
        int m;
        int s;

public:
        minheap(int ma)
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

        void array()
        {
                for (int i = 0; i < s; i++)
                {
                        cout << arr[i] << " ";
                }
        }

        void heapifyUp(int i)
        {
                while (i != 0 && arr[parent(i)] > arr[i])
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
                heapifyUp(i);
        }

        void delet(int x)
        {
                if (s == 0)
                {
                        cout << "underflow error";
                        return;
                }
                arr[x] = arr[s - 1];
                arr[--s] = 0;
                heapifyDown(x);
        }

        void heapifyDown(int i)
        {
                int l = leftchild(i);
                int r = rightchild(i);
                int large = i;
                if (l < s && arr[l] < arr[large])
                {
                        large = l;
                }
                if (r < s && arr[r] < arr[large])
                {
                        large = r;
                }
                if (large != i)
                {
                        swap(arr[i], arr[large]);
                        heapifyDown(large);
                }
        }

        int top()
        {
                if (s <= 0)
                {
                        return NULL;
                }
                if (s == 1)
                {
                        return arr[--s];
                }
                int temp = arr[0];
                arr[0] = arr[--s];
                heapifyDown(0);
                return temp;
        }
};
