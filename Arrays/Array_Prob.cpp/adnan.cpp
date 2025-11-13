#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Convert string to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Split a string into words
vector<string> splitWords(const string& text) {
    vector<string> words;
    string word;
    for (char ch : text) {
        if (isalnum(ch)) {
            word += tolower(ch);
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}

int main() {
    int n;
    cout << "Enter number of documents: ";
    cin >> n;
    cin.ignore();

    vector<string> documents(n);
    map<string, set<int>> wordDocMatrix;

    cout << "\nEnter each document (one per line):\n";
    for (int i = 0; i < n; ++i) {
        getline(cin, documents[i]);
        vector<string> words = splitWords(documents[i]);
        for (const string& word : words) {
            wordDocMatrix[word].insert(i);
        }
    }

    string query;
    cout << "\nEnter search query: ";
    getline(cin, query);
    vector<string> queryWords = splitWords(query);

    vector<int> matchCount(n, 0);
    for (const string& word : queryWords) {
        if (wordDocMatrix.count(word)) {
            for (int idx : wordDocMatrix[word]) {
                matchCount[idx]++;
            }
        }
    }

    vector<pair<int, int>> rankedDocs;
    for (int i = 0; i < n; ++i) {
        if (matchCount[i] > 0) {
            rankedDocs.push_back(make_pair(matchCount[i], i));
        }
    }

    sort(rankedDocs.rbegin(), rankedDocs.rend()); // sort descending by count

    cout << "\nSearch Results:\n";
    if (rankedDocs.empty()) {
        cout << "No matching documents found.\n";
    } else {
        for (const auto& pair : rankedDocs) {
            int count = pair.first;
            int idx = pair.second;
            cout << "Document " << (idx + 1) << " (matches: " << count << "): " << documents[idx] << "\n";
        }
    }

    return 0;
}
