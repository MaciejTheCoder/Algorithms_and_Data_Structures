/*
Implement a max heap and the following operations:
+ v
add a number to the heap v
-
remove the maximum from the max heap (minimum from the min heap respectively) and write it
p
write all elements of the heap in the order in which they are stored in an array
r n v1 ...vn
remove all elements from the heap and create a heap out of n new elements, of the values given by v1 ...vn
s
change the orientation of the heap – from max to min; when the the orientation is min, the heap yields the minimal element; next s instruction should return the max order
q
exit the program

Example input:
+ 1
+ 2
+ 3
+ 4
+ 5
+ 6
+ 7
+ 8
p
-
-
-
-
-
-
-
-
p
r 8 1 2 3 4 5 6 7 8
p
-
-
-
-
-
-
-
-
p
r 8 1 2 3 4 5 6 7 8
s
p
-
-
-
-
-
-
-
-
p
q
*/

#include <iostream>
#include <string>

using namespace std;

int arr[65536];

void maxheapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
  
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxheapify(arr, n, largest);
    }
}

void minheapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minheapify(arr, n, smallest);
    }
}

void Sort(int arr[], int n, int k)
{
    if (k == 0) {
        for (int i = n / 2 - 1; i >= 0; i--)
            minheapify(arr, n, i);
    }
    if (k == 1) {
        for (int i = n / 2 - 1; i >= 0; i--)
            maxheapify(arr, n, i);
    }
}

void SimpleSort(int arr[], int n, int k)
{
    if (k == 0) {
        int x = n - 1;
        int i = x;
        while (i != 0) {
            if (arr[(i - 1) / 2] > arr[x]) {
                swap(arr[(i - 1) / 2], arr[x]);
                x = (x - 1) / 2;
            }
            i = (i - 1) / 2;
        }
    }
    if (k == 1) {
        int x = n - 1;
        int i = x;
        while (i != 0) {
            if (arr[(i - 1) / 2] < arr[x]) {
                swap(arr[(i - 1) / 2], arr[x]);
                x = (x - 1) / 2;
            }
            i = (i - 1) / 2;
        }
    }
}

int main()
{
    char input;
    int a = 0, q = 0;
    int p = 1;

    while (q != 1) {
        cin >> input;
        switch (input)
        {
        case '+':
            cin >> arr[a];
            a++;
            SimpleSort(arr, a, p);
            break;
        case '-':
            cout << arr[0] << endl;
            swap(arr[0], arr[a - 1]);
            arr[a - 1] = NULL;
            a--;
            Sort(arr, a, p);
            break;
        case 'p':
            for (int i = 0; i < a; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 'r':
            for (int i = a - 1; i >= 0; i--)
            {
                arr[i] = NULL;
            }
            cin >> a;
            for (int i = 0; i < a; i++)
            {
                cin >> arr[i];
            }
            Sort(arr, a, p);
            break;
        case 's':
            if (p == 1) {p = 0;} else p = 1;
            Sort(arr, a, p);
            break;
        case 'q':
            q = 1;
            break;
        }
    }
}
