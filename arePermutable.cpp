#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <map>


using std::cin;
using std::cout;
using std::endl;
using std::strcpy;
using std::map;
using std::string;


int main()
{
    string str1;
    string str2;


    cin >> str1;
    cin >> str2;


    if(str1.length() != str2.length())
        cout << "The strings are not permutable." << endl;
    else if(str1.length() == 1 && str1 == str2)
        cout << "The strings are permutable." << endl;
    else
    {
        // create cstring arrays
        char* cstr1 = new char[str1.length() + 1];
        char* cstr2 = new char[str2.length() + 1];


        strcpy(cstr1, str1.c_str());
        strcpy(cstr2, str2.c_str());    


        int i = 0;
        int counter;


        // put chars in map1
        map<char, int> map1;
        while(cstr1[i] != 0)
        {
            counter = 1;
            int inc = i + 1;
            while(cstr1[inc] != 0)
            {
                if(cstr1[i] == cstr1[inc])
                {
                    counter++;
                }
                inc++;
            }
            
            map1[cstr1[i]] = counter;
            counter = 1;
            i++;
        }


        // put chars in map2
        i = 0;
        map<char, int> map2;
        while(cstr1[i] != 0)
        {
            counter = 1;
            int inc = i + 1;
            while(cstr2[inc] != 0)
            {
                if(cstr2[i] == cstr2[inc])
                {
                    counter++;
                }
                inc++;
            }
            
            map2[cstr2[i]] = counter;
            counter = 1;
            i++;
        }


        if(map1 == map2)
            cout << "The strings are permutable." << endl;
        else
            cout << "The strings are not permutable." << endl;
    }


    return 0;
}
