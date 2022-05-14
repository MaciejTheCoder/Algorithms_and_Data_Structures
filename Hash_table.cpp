/*
Write a program tracking the amount of transferred money. Commands are given in the following format:
+ from to amount - from pays to the specified amount
? from to - display the amount transferred by from to to's account

Note: do not calculate a state of the account, track the sum of transfers:
+ A B 10
+ A B 10
+ B A 5
? A B
? B A
should display:
20
5
*/

#include <iostream>
#include <string>
#include<cmath>


using namespace std;

struct Hash {
    string person1;
    string person2;
    int value1 = 0; // person1 - > person2 
    int value2 = 0; // person2 - > person1
};

int count_string(string one, string two) {
    int count = 0, count2 = 0;
    for (int i = 0; i < one.length(); i++) {
        count += (int)one[i] * (int)two[0] * (i + 1);
    }
    for (int i = 0; i < two.length(); i++) {
        count2 += (int)two[i] * (int)one[0] * (i + 1);
    }
    count2 = count2 % 100;
    count = count % 100;
    count = count * count2;
    //cout << count << endl;
    return count % 10000;
}

int main()
{
    Hash hash[10000];
    char parameter;
    string first = "";
    string second = "";
    int number;
    int count;

    while (cin >> parameter) {
        if (parameter == '+')
        {
            cin >> first >> second >> number;
            count = count_string(first, second);
            if ((hash[count].value1 == 0) && (hash[count].value2 == 0)) {
                hash[count].value1 = number;
                hash[count].person1 = first;
                hash[count].person2 = second;
            }
            else if (hash[count].person1 == first) {
                hash[count].value1 += number;
            }
            else if (hash[count].person1 == second) {
                hash[count].value2 += number;
            }
        }
        else if (parameter == '?')
        {
            cin >> first >> second;
            count = count_string(first, second);
            if (hash[count].person1 == first) {
                cout << hash[count].value1 << endl;
            }
            else if (hash[count].person1 == second) {
                cout << hash[count].value2 << endl;
            }
            else {
                cout << "0" << endl;
            }
        }
    }
}
