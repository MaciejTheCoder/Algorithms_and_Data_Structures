/*
Sort a given collection of large natural numbers using a given algorithm.

Example input:
5
13
27
328
111
25

*/

#include  <iostream>
#include  <string>

using namespace std;

int compare(string A, string B)
{
    if (A.size() < B.size()) return 1;
    else if (B.size() < A.size()) return 0;
    else
    {
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > B[i]) return 0;
            else if (A[i] < B[i]) return 1;
        }
    }
    return 1;
}


void shellSort(string *A, int n)
{
    for (int k = n / 2; k > 0; k/=2)
    {
        for (int i = k; i < n; i++)
        {
            string x = A[i];
            int j;
            for (j = i; (j >= k && compare(x, A[j - k]) == 1); j -= k) {
                A[j] = A[j - k];
            }
            A[j] = x;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    string *tab; 
    tab = new string[n];


    for (int i = 0; i < n; i++) 
    {
        getline(cin >> std::ws, tab[i]);
    }

    shellSort(tab, n);

    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << endl;
    }

    delete[] tab;

    return 0;
}
