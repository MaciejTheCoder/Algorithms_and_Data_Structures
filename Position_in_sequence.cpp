/*
Position in sequence

Write and use a function (iterative or recursive, the teacher will decide) which finds a given element
in the monotonically increasing OR decreasing sequence of (signed) integers. The function should
return the index of the found element, or −1 if it doesn’t exist in the sequence.
(Indices in the sequence should be counted starting from 0)
*/

#include <iostream>
using namespace std;

int main()
{
        int m; //number of test scenario
        int n; //number of elements int the sequence
        int p; //number of elements to be found
        int elements=0; //ho many elements do we finding in whole function
        int sequence[20000];
        int tofound[20000];
        int answer[20000];
        int l = 0;

        for (int i = 0; i < 100; i++) {
                answer[i] = -1;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
                cin >> n;
                for (int j = 0; j < n; j++) {
                        cin >> sequence[j];
                }
                cin >> p;
                elements+=p;
                for (int j = 0; j < p; j++) {
                        cin >> tofound[j];
                }
                if (sequence[1] > sequence[0]) {
                        for (int j = 0; j < p; j++) {
                                if (tofound[j] < sequence[0]) {
                                        l++;
                                }
                                else {
                                        for (int h = 0; h < n; h++) {
                                                if (tofound[j] == sequence[h]) {
                                                        answer[l] = h;
                                                        break;
                                                }
                                        }
                                        l++;
                                }
                        }
                }
                else if (sequence[1] < sequence[0]) {    
                        for (int j = 0; j < p; j++) {
                                if (tofound[j] > sequence[0]) {
                                        l++;
                                }
                                else {
                                        for (int h = 0; h < n; h++) {
                                                if (tofound[j] == sequence[h]) {
                                                        answer[l] = h;
                                                        break;
                                                }
                                        }
                                        l++;
                                }
                        }
                }
        }

        for (int j = 0; j < elements; j++)
        {
                cout << answer[j] << endl;;
        }
        
}
