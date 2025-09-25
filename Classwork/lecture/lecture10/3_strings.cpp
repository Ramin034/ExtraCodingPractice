#include <iostream>
#include <string>
using namespace std;

int main()
{
    // string declaration and initialization
    string first_name ="Leslie ";
    string last_name = "Knope"; // 
    string space = " "; // empty string - ""
    // string sentence = "This is an example"; // enclosed in ""
    // cout << first_name << endl;

    // concatenation
    string full_name = first_name + last_name;
   
    cout << full_name << endl;



    // length of a string
    // string_var.length();
    cout<< full_name.length()<<endl;


    // referencing individual characters in a string
    /*
        L  e  s  l  i  e     K  n  o  p  e
        0  1  2  3  4  5  6  7  8  9  10 11
        1  2  3 ...
    */
    // cout << "full_name[0] is " << full_name[0] << endl; //index 0 is 1st letter
    // cout << "full_name[1] is " << full_name[1] << endl; //index 1 is 2nd letter
    // cout << "full_name[2] is " << full_name[2] << endl; 
    // cout << "full_name[3] is " << full_name[3] << endl; 
    // cout << "full_name[4] is " << full_name[4] << endl; 
    // cout << "full_name[5] is " << full_name[5] << endl; 

    // cout << "full_name[15] is " << full_name[len-1] << endl; // len - 1 will return the last character in the string 
    // cout << "full_name[16] is " << full_name[16] << endl; // empty 

    // substring
    // string_var.substr(starting_position,num_of_characters)
    
    // cout << full_name.substr(0,3) << " is a substring of " << full_name << endl;
    // cout << full_name.substr(2,8) << " is a substring of " << full_name << endl;
    // cout << full_name.substr(7) << " is a substring of " << full_name << endl;  // Knope / K
    // cout << full_name.substr() << " is a substring of " << full_name << endl;  // full string


    // find a character or string 
    // string_var.find("string")
    // string_var.find("string",starting_position)
    // cout << full_name.find("L") << endl;    //  
    // cout << full_name.find("l") << endl;    //  
    // cout << full_name.find("e") << endl;    //  
    // cout << full_name.find("ie") << endl;   // 
    // cout << full_name.find("e", 3) << endl; // 

    // replace a character or string; http://www.cplusplus.com/reference/string/string/replace/
    // string.replace(starting_position,number_of_characters,"string")
    // cout << full_name.replace(7,7,"rocks") << endl;
    // cout << full_name.replace(0,4,"") << endl;
    // cout << full_name.replace(4,3,"") << endl;
    // cout << full_name << endl; // full_name has been updated

    return 0;
}