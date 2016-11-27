
**13.2: Anonymous Letter Constructible?**

*  **Input:** text for an anonymous letter
*  **Input:** text for a magazine
*  **Return:** Boolean - can the anonymous letter be written using only magazine text

*   TRUE: if # of appearances for each char in anonymous letter <= # of appearances that char appears in the magazine
*   Hint: count the number of distinct characters appearing in the letter

---

```
bool constructible(anon_text, mag_text) {
    // ignoring base cases or error checking
    // Get Character Frequencies for each letter in each set



    // Iterate over each letter in freq listing, if !Anon_Char Count <= Mag_text Count; return false


}
```


*  use a `unodered_map<char, count>` for each text set OR  `unordered_map<char,pair<countA,countB>`


**Solution Psuedo**

*  iterate and store char frequency for the letter text in a hashtable / `map <char, count>`

*  now iterate over mag text
*  for each char c:  if c is in letter hash map, decrement count by one
*  when the hash table is empty return true
*  if end of mag text is reached and anon hash table !empty, return false


---

**13.3 Implement an ISBN Cache**


