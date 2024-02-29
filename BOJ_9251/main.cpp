#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1;
    string s2;
    int length;
    vector<char> answer;

    cin >> s1;
    cin >> s2;
    length = s1.length();

    for (int k = 0; k < length; k++)
    {
        vector<char> tmp;

        for (int i = k; i < length; i++)
        {
            for (int j = 0; j < length;)
            {
                if (s2[j] == s1[k])
                {
                    tmp.push_back(s2[j]);
                    j += 1;
                }
                else
                    j++;
            }
        }
        if (answer.size() < tmp.size())
        {
            answer.resize(tmp.size());
            copy(tmp.begin(), tmp.end(), answer.begin());
        }
    }

    cout << answer.size() << endl;

    return 0;
}