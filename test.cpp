#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main()
{
    string str;
    vector<char> duplicates;


    while(getline(cin, str))
    {


        // create c string
        char* cstr = new char[str.length() + 1];
        std::strcpy(cstr, str.c_str());


        int iter = 0;
        while(cstr[iter] != 0)
        {
            int i = (iter + 1);
            while(cstr[i] != 0 && cstr[iter] != cstr[i])
                i++;
            
            char a = cstr[iter];
            char b = cstr[i];


            // if there is a duplicate
            if(a == b)
            {
                if(duplicates.empty())
                    duplicates.push_back(cstr[iter]);
                else 
                {
                    int j = 0;
                    while(duplicates[j] != duplicates.back() && cstr[iter] != duplicates[j])
                        j++;
                    if(duplicates[j] != cstr[iter])
                        duplicates.push_back(cstr[iter]);
                }
            }


            iter++;
        }


        // if there are duplicates after searching
        if(!duplicates.empty())
        {
            int a = 0;
            while(!duplicates.empty())
            {
                char ch = duplicates[a];
                duplicates.pop_back();
                a++;
                cout << "There is more than one '" << ch << "' in string." << endl;
            }
        }
        else if(duplicates.empty())
            cout << "There are no duplicates in this string." << endl;
        duplicates.clear();
    }


    return 0;
}
