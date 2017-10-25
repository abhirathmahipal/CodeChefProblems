#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int dict_count, phrase_count;
        vector <string> dictionary;
        cin >> dict_count >> phrase_count;

        for (int j = 0; j < dict_count; j++) {
            string temp;
            cin >> temp;
            dictionary.push_back(temp);
        }
        vector <bool> word_occurence(false, dict_count);
        for (int k = 0; k < phrase_count; k++) {
            int length;
            cin >> length;
            for (int l = 0; l < length; l++) {
                string word_of_phrase;
                cin >> word_of_phrase;
                vector <string>::iterator iter_position = find(dictionary.begin(), dictionary.end(), word_of_phrase);
                word_occurence[distance(dictionary.begin(), iter_position)] = true;
            }
        }

        for (int a = 0; a < dict_count; a++) {
            if(word_occurence[a]) cout << "YES";
            else cout << "NO";

            if (a != dict_count - 1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}