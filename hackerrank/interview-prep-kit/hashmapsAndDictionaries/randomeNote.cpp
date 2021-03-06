#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// My solution below (only checkMagazine function).
void checkMagazine(vector<string> magazine, vector<string> note) {
    auto words_occurance = unordered_map<string, int>{};
    
    for (const auto& word : magazine) {
        auto search_result = words_occurance.find(word);
        if (search_result != words_occurance.end()) {
            words_occurance[word] += 1;
        } else {
            words_occurance[word] = 1;
        }
    }

    for (const auto& word : note) {
        auto search_result = words_occurance.find(word);
        if (search_result == words_occurance.end()) {
            cout << "No\n";
            return;
        } else {
            words_occurance[word] -= 1;
            if (words_occurance[word] == 0) {
                words_occurance.erase(word);
            }
        }
    }
    cout << "Yes\n";
    return;
}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
