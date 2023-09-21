#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'longestCommonSubsequence' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int rows = a.size();
    int columns = b.size();
    
    int** mat = new int*[rows];
    for(int i = 0; i < rows; i++){
        mat[i] = new int[columns];
    }
    
    int up, left;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(a[i] == b[j]){
                if(i>0 && j>0)
                    mat[i][j] = mat[i-1][j-1] + 1;
                else
                    mat[i][j] = 1;
            }
            else{
                if(i>0)
                    up = mat[i-1][j];
                else
                    up = 0;
                if(j>0)
                    left = mat[i][j-1];
                else
                    left = 0;
                if(up > left)
                    mat[i][j] = up;
                else
                    mat[i][j] = left;
            }
                
        }   
    }
    
    int length = mat[rows-1][columns-1];
    vector<int> result(length);
    bool finish = false;

    for(int i = rows-1; i >= 0; i--)
    {
        for(int j = columns-1; j >= 0; j--)
        {
            if(i>0)
                up = mat[i-1][j];
            else
                up = 0;
            if(j>0)
                left = mat[i][j-1];
            else
                left = 0;
            if(mat[i][j] == up){
                if(i>0){
                    i--;
                    j++;
                }
                else{
                    finish = true;
                    break;
                }
            }
            else if(mat[i][j] == left)
                continue;
            else{
                result[--length] = a[i];
                if(i>0){
                    i--; 
                }   
                else{
                    finish = true;
                    break;
                }        
            }
        }
        if(finish)
            break;
    }
    return result; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split(rtrim(b_temp_temp));

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
