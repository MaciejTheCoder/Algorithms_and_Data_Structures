/*
Calculate the value of an expression in postfix notation (RPN). Three operators are used: N (negation),
K (conjunction), A (alternative) and two logic values: t (true) and f (false).

Example input:
2
tttfKKK
tfAN
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int n; // liczba działań 
char Tab[1024];
char result[100];
char znak;
#define M 500

class Stack {
        int top;
public:
        int a[M];
        Stack() { top = -1; }
        bool push(int x);
        int pop();
        int last();
};

bool Stack::push(int x)
{
        if (top >= (M - 1)) {
                return false;
        }
        else {
                a[++top] = x;
                return true;
        }
}

int Stack::pop()
{
        if (top < 0) {
                return 0;
        }
        else {
                int x = a[top--];
                return x;
        }
}

int Stack::last()
{
        if (top < 0) {
                return 0;
        }
        else {
                int x = a[top];
                return x;
        }
}

int main()
{
        cin >> n;
        getchar();

        for (int i = 0; i < n; i++) {
                gets_s(Tab);
                class Stack stos;
                int j = 0;
                char a, b;
                char c;
                while (Tab[j]>0) {
                        znak = Tab[j];
                        switch (znak) 
                        {
                        case 't':
                                stos.push(znak);
                                break;
                        case 'f':
                                stos.push(znak);
                                break;
                        case 'K': 
                                a = stos.pop();
                                b = stos.pop();
                                if (a == 't' && b == 't') {
                                        c = 't';
                                }
                                else { c = 'f'; }
                                stos.push(c);
                                break;
                        case 'A':
                                a = stos.pop();
                                b = stos.pop();
                                if (a == 'f' && b == 'f') {
                                        c = 'f';
                                }
                                else { c = 't'; }
                                stos.push(c);
                                break;
                        case 'N':
                                a = stos.pop();
                                if (a == 'f') {
                                        c = 't';
                                }
                                else { c = 'f'; }
                                stos.push(c);
                                break;
                        default:
                                break;
                        }
                        j++;
                }
                result[i]= stos.last();
        }
        for (int i = 0; i < n; i++) {
                cout << result[i] << endl;
        }
}
