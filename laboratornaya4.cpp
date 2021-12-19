#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
void eraseSymbols (string& s, char c, int n)
{
    int N = s.size(), count = 0;
    for (int i=0; i<N-1; i++){
        if (s[i]==c) count ++;
        if (s[i-1]==c && s[i]!=c) {s.erase(i-count, count-n); count = 0;}
    }
}
int seek_substring_KMP (char s[], char p[])
{
    int i, j, N, M;
    N = strlen(s);
    M = strlen(p);
    int *d = (int*)malloc(M * sizeof(int));
    d[0] = 0;
    for(i = 1, j = 0; i < M; i++)
    {
        while(j > 0 && p[j] != p[i])
            j = d[j-1];
        if(p[j] == p[i])
            j++;
        d[i] = j;
    }
    for(i = 0, j = 0; i < N; i++)
    {
        while(j > 0 && p[j] != s[i])
            j = d[j - 1];
        if(p[j] == s[i])
            j++;
        if(j == M)
        {
            free(d);
            return i - j + 1;
        }
    }
    free(d);
    return -1;
}
int main()
{
    string str;
    getline(cin,str);
    eraseSymbols (str, ' ', 1);
    eraseSymbols (str, '!', 1);
    eraseSymbols (str, ',', 1);
    eraseSymbols (str, '-', 1);
    eraseSymbols (str, '.', 3);
    eraseSymbols (str, '?', 1);
    eraseSymbols (str, ':', 1);
    eraseSymbols (str, ';', 1);
    for (int j=1; j<str.size(); j++)
        if ((65 <= str[j] && str[j] <= 122))
            if (str[j] <= 90 && str[j-1]!=' ') str[j] = str[j]+32;
    cout << str << endl;
    eraseSymbols (str, '!', 0);
    eraseSymbols (str, ',', 0);
    eraseSymbols (str, '-', 0);
    eraseSymbols (str, '.', 0);
    eraseSymbols (str, '?', 0);
    eraseSymbols (str, ':', 0);
    eraseSymbols (str, ';', 0);
    str.erase(str.size()-1);
    string strKMP = str;
    int k = 0;
    string str2[50];
    while (str.size() > 0)
    {
        int n = str.find(' ');
        if (n != string::npos) {str2[k]=str.substr(0, n); k++; str.erase(0, n+1);}
        else {str2[k]=str.substr(0); str.clear();}
    }
    int N = k+1;
    string text[N];
    for (int i=0; i<N; i++)
        text[i] = str2[i];
    // вариант 1
    cout << "Paragraph 3.1" << endl;
    for (int i=N-1; i>=0; i--)
        cout << text[i] << ' ';
    cout << endl;
    // вариант 2
    cout << "Paragraph 3.2" << endl;
    for (int i=0; i<N; i++)
    for (int j=0; j<text[i].size(); j++)
        if ((65 <= text[i][j] && text[i][j] <= 122))
            if (text[i][j] <= 90) text[i][j] = text[i][j]+32;
    for (int i=0; i<N-1; i++)
    {
        bool flag = true;
        for (int j=0; j<N-1-i; j++) {
            if (text[j] > text[j + 1]) {
                std::swap(text[j], text[j + 1]);
                flag = false;
            }
        }
        if (flag) break;
    }
    for (int i=0; i<N; i++)
        cout << text[i] << ' ';
    cout << endl;
    // вариант 3
    cout << "Paragraph 3.3" << endl;
    for (int i=0; i<N; i++) {
        bool digit = false;
        for (int j = 0; j < text[i].size(); j++)
            if (text[i][j] > 47 && text[i][j] < 58) {
                digit = true;
                break;
            }
        if (!digit) cout << text[i] << ' ';
    }
    cout << endl;
    // вариант 4
    cout << "Paragraph 3.4" << endl;
    for (int i=0; i<N; i++) {
        bool twice = false;
        for (int j = 0; j < text[i].size(); j++)
            if (text[i].find(text[i][j]) != text[i].rfind(text[i][j])) {
                twice = true;
                break;
            }
        if (twice) cout << text[i] << ' ';
    }
    cout << endl;
    // вариант 5
    cout << "Paragraph 3.5" << endl;
    for (int i=0; i<N; i++) {
        if (text[i].find(text[i][0]) != text[i].rfind(text[i][0])) {
            cout << text[i] << ' ';
            break;
        }
    }
    cout << endl;
    char charKMP[strKMP.size()], p[strKMP.size()];
    for (int i=0; i<strKMP.size(); i++)
        charKMP[i] = strKMP[i];
    cin.getline (p, strKMP.size());
    cout << seek_substring_KMP (charKMP, p);
    return 0;
}