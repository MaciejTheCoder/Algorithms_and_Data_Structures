/*
THERE ARE SOME MISTAKES IN CODE

Implement a TRIE tree which contains translations of words. Word in original language and its translation will 
not be longer than 16 characters and will contain only lower case lettters.
The following commands should be supported:
+ s t
add a word s with the translation t
? s
query about a word s – write a translation of s or - (minus sign) if it has not been added
* s
Write all translations of words such that s is a prefix of the word (including word s, if its contained in the tree). 
Translations should be written in alphabetical order of original words (see * d in example). Write - (minus sign) if no such word exists.

Example input:
Input
+ dog pies
+ cat kot
+ do robic
+ doggie piesek
+ doggies pieski
+ dolphin delfin
+ ant mrowka
+ zzz xxx
? dog
? cat
? do
? doggie
? dolphin
? ant
? zzz
? d
? dot
? dom
? dogg
? dol
? dolp
? dolph
? dolphi
? dolphine
* a
* d
* do
* dog
* dogg
* doggie
* doggies
* z
* b
* dot
* dolphen
* doggiess

*/


#include <iostream>
#include <string>

using namespace std;

#define MAX 26

struct Node
{
        struct Node* children[MAX];
        bool isitend;
        string meaning;
};

struct Node* newNode(void)
{
        struct Node* pNode = new Node;
        pNode->isitend = false;
        for (int i = 0; i < MAX; i++)
                pNode->children[i] = NULL;
        return pNode;
}

void add(struct Node* root, string word, string meaning)
{
        struct Node* newword = root; //zaczynamy od korzenia
        for (int i = 0; i < word.length(); i++) //tyle razy jaką długość ma litera
        {
                int index = word[i] - 'a';
                if (!newword->children[index]) // jeśli nie mamy takiej litery
                        newword->children[index] = newNode(); //tworzymy nową literę 

                newword = newword->children[index]; //mamy już taką literę
        }
        newword->isitend = true;
        newword->meaning = meaning;
}

string search(struct Node* root, string first)
{
        struct Node* wordstart = root;

        for (int i = 0; i < first.length(); i++)
        {
                int index = first[i] - 97; // tablica ASCII 
                if (!wordstart->children[index])
                        return "-";
                wordstart = wordstart->children[index];
        }
        if (wordstart->isitend == true) {
                return wordstart->meaning;
        }
        else {
                return "-";
        }
}

int main()
{
        char parameter;
        string first = "";
        string second = "";
        struct Node* root = newNode();
        while (cin >> parameter) {
                if (parameter == '+') {
                        cin >> first >> second;
                        add(root, first, second);
                }
                else if (parameter == '?') {
                        cin >> first;
                        second = search(root, first);
                        cout << second << endl;
                }
                else if (parameter == '*') {
                        cin >> first;
                        //secondsearch(root, first);
                }
        }
        return 0;
}
