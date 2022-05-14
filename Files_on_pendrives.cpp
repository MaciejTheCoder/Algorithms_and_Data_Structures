/*
  There are files on your disk. You have to copy as many files as possible into two pendrives. Files 
cannot be divided. Write a program that will select files. Your answer can be different from optimal result by 1.
  In the first line there are two numbers n p - number of files and pendrives' size.
In the next n lines there are two numbers id r - file identifier and file size.
  In the first line write a number - total number of copied files. In the next two lines write '1:' or '2:' 
with lists of copied file's identifiers. The lists should be sorted in descending order.

Example input:
4 7
323 1 
10 2 
87438 5 
99 6
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, p; //files number, pendrives's size
int t1=0, t2=0; //number of copied files

struct File
{
    int no;
    int size;
};

int partition(File * tablica, int h, int r) 
{
    int x = tablica[h].size; 
    int i = h, j = r, w; 
    while (true) 
    {
        while (tablica[j].size > x) 
            j--;
        while (tablica[i].size < x) 
            i++;
        if (i < j) 
        {
            swap(tablica[i], tablica[j]);
            i++;
            j--;
        }
        else 
            return j;
    }
}
int partition2(int tablica[], int h, int r)
{
    int x = tablica[h];
    int i = h, j = r, w;
    while (true)
    {
        while (tablica[j] > x)
            j--;
        while (tablica[i] < x)
            i++;
        if (i < j)
        {
            swap(tablica[i], tablica[j]);
            i++;
            j--;
        }
        else
            return j;
    }
}

void quicksort(File * tablica, int h, int r) 
{
    int q;
    if (h < r)
    {
        q = partition(tablica, h, r); 
        quicksort(tablica, h, q); 
        quicksort(tablica, q + 1, r); 
    }
}
void quicksort2(int tablica[], int h, int r)
{
    int q;
    if (h < r)
    {
        q = partition2(tablica, h, r);
        quicksort2(tablica, h, q);
        quicksort2(tablica, q + 1, r);
    }
}

int main()
{
    cin >> n;
    int * Tab1 = new int[n / 2];
    int * Tab2 = new int[n / 2];
    cin >> p;
    File * files = new File[n];
    for (int i = 0; i < n; i++) {
        cin >> files[i].no;
        cin >> files[i].size;
    }
    quicksort(files, 0, n - 1);
    int taken1 = 0, taken2 = 0, a = 0, b = 0, c = 0;
   while (c<n) {
       if ((taken1 >= p) && (taken2 >= p)) {
           break;
       }
       if (c+3>n) {
           for (int i = 0; i < n; i++) {
               if (files[i].size == (p - taken1) && (files[i].size != 0)) {
                   Tab1[a] = files[i].no;
                   taken1 += files[i].size;
                   files[i].size = 0;
                   a++;
                   t1++;
               }
           }
       }
        while (taken1<p) {
            if ((files[c].size != 0)&&((taken1+files[c].size)<=p)) {
                Tab1[a] = files[c].no;
                taken1 += files[c].size;
                files[c].size = 0;
                a++;
                c++;
                t1++;
                break;
            }
            c++;
            if (c > n) {
                break;
            }
        }
        if (c + 3 > n) {
            for (int i = 0; i < n; i++) {
                if (files[i].size == (p - taken2) && (files[i].size != 0)) {
                    Tab2[b] = files[i].no;
                    taken2 += files[i].size;
                    files[i].size = 0;
                    b++;
                    t2++;
                }
            }
        }
        while (taken2<p) {
            if ((files[c].size != 0) && ((taken1 + files[c].size) <= p)) {
                Tab2[b] = files[c].no;
                taken2 += files[c].size;
                files[c].size = 0;
                b++; 
                c++;
                t2++;
                break;
            }
            c++;
            if (c > n) {
                break;
            }
        }
    } 
   quicksort2(Tab1, 0, t1 - 1);
   quicksort2(Tab2, 0, t2 - 1);
    cout << (t1+t2) << endl;
    cout << "1: ";
    int m = 0;
    while (Tab1[m] > 0) {
        m++;
    }
    m--;
    while (m >= 0) {
        cout << Tab1[m] << " ";
        m--;
    }
    cout << endl;
    m = 0;
    cout << "2: ";
    while (Tab2[m] > 0) {
        m++;
    }
    m--;
    while (m >= 0) {
        cout << Tab2[m] << " ";
        m--;
    }
}
