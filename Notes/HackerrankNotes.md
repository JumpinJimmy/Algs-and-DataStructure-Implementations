## Ransom Note ##

**For character counts only**
```
bool ransom_note(vector<string> magazine, vector<string> ransom) {
    //if (magazine.empty()) return false;
    if (ransom.empty()) return true;
    
    std::unordered_map<char, int> note_char_freq;
    for (string &s : ransom) {
        for (char &c : s) {
            if (!isspace(c)) {
                ++note_char_freq[c];
            }
        }  
    }
    for (string &s : magazine) {
        for (char &c : s) {
            auto char_iter = note_char_freq.find(c);
            if (char_iter != note_char_freq.cend()) {
                --char_iter->second;
                if (char_iter->second == 0) {
                    note_char_freq.erase(char_iter);
                    if (note_char_freq.empty()) {
                        break;
                    }
                }
            }
        }
    }
    return note_char_freq.empty();
}
```

**For Full Strings counts only**

```
bool ransom_note(vector<string> magazine, vector<string> ransom) {
    if (magazine.empty()) return false;
    if (ransom.empty()) return true;
    
    std::unordered_map<string, int> note_char_freq;
    for (string &s : ransom) {
        ++note_char_freq[s];
    }
    for (string &s : magazine) {
            auto char_iter = note_char_freq.find(s);
            if (char_iter != note_char_freq.cend()) {
                --char_iter->second;
                if (char_iter->second == 0) {
                    note_char_freq.erase(char_iter);
                    if (note_char_freq.empty()) {
                        break;
                    }
                }
            }
        
    }
    return note_char_freq.empty();
}
}