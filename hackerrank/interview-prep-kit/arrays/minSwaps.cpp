/**
 * file: minSwaps.cpp
 *
 * description:
 *
 * The file contains solution for the minimum swaps problem hackerrank.
 * So, you given an unordered array of integer numbers without duplicates.
 * You are allowed to swap any two elements. You need to find minumum number
 * of swaps required to sort the array in ascending order.
 *
 * You should implement only minimumSwaps() function.
 * Hackerrank provide all boilerplate code for parsing input
 * and other additional tasks.
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// My solution below
int minimumSwaps(vector<int> arr) {
    auto result = 0;

    for (int i = arr.size() - 1; i >= 0; --i) {
        auto searchedElement = i + 1;

        if (arr[i] == searchedElement) {
            continue;
        } else {
            auto pos = find(begin(arr), end(arr), searchedElement) - begin(arr);
            arr[i] = arr[i] ^ arr[pos];
            arr[pos] = arr[i] ^ arr[pos];
            arr[i] = arr[i] ^ arr[pos];
            ++result;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);
    fout << res << "\n";
    fout.close();
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
