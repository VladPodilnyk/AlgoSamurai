#include <bits/stdc++.h>

using namespace std;

// My solutrion below
string twoStrings(string s1, string s2) {
    auto dictionary = set<char>{};
    for (const auto& symbol : s1) {
        dictionary.emplace(symbol);
    }

    for (const auto& symbol : s2) {
        auto search_result = dictionary.find(symbol);
        if (search_result != dictionary.end()) {
            return "YES";
        }
    }
    return "NO";
}

// Hackerrank's boilerplate code
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}