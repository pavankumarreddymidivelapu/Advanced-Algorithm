#include <iostream> //input and output operations
#include <vector> //vector is a library function that can be used as a dynamic array that resize itself
using namespace std; 

void printTable(const vector<vector<int> >& table) //'printTable' function takes a 2D vector of integers as an arguments.
 {
    //nested for loop->to iterate through the rows and columns of the 2D vector 
    for (size_t i = 0; i < table.size(); ++i) {
        for (size_t j = 0; j < table[i].size(); ++j) {  
            cout << table[i][j] << " ";  //print the rows and columns of the 2D vector
        }
        cout << endl;
    }
}
    //Function to find longest common substring
void longestCommonSubstring(const string& str1, const string& str2) //'str1' and 'str2' taken as a input
{
    int len = str1.length();  //length of the string1
    vector<vector<int> > dp(len + 1, vector<int>(len + 1, 0)); 
    int maxLen = 0; // To track the length of the longest common substring
    int endIndex = 0; // To track the end index of the longest common substring

        //nested for loop
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i; // Store the end index of the substring
                }
            } else {
                dp[i][j] = 0; // Reset the count for non-matching characters
            }
        }
    }

    cout << "Dynamic Programming Table:" << endl;
    printTable(dp);

    // Displaying one of the longest common substrings (in this case, the first one found)
    if (maxLen > 0) {
        cout << "\nLongest Common Substring of length " << maxLen << ": "; //print Longest Coomon Substring of length :'maxlen'
        for (int i = endIndex - maxLen; i < endIndex; ++i) {
            cout << str1[i];
        }
        cout << endl;
    } else {
        cout << "\nNo common substring found." << endl;
    }
}

int main() {
    string str1, str2;

    cout << "Enter String 1: "; //To Display 
    cin >> str1; //user input string1

    cout << "Enter String 2: "; //To Display 
    cin >> str2; //user input string2

    if (str1.length() != str2.length()) //checks the str1 and str2 length is not equal
    {
        cout << "Both strings should have equal length." << endl; //To display
        return 1;
    }
    //To Display the input strings
    cout << "Input Strings:" << endl;  
    cout << "String 1: " << str1 << endl;   //To Display str1
    cout << "String 2: " << str2 << endl;   //To Display str2

    longestCommonSubstring(str1, str2);

    return 0;
}
