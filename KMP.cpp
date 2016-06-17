int nxt[N];
void get_next(string s) {
    int i = 0, j = -1;  // j记录已匹配的个数
    nxt[0] = -1;
    while (i < s.size()) {
        if (j == -1 || s[i] == s[j]) {
            i++;
            j++;
            nxt[i] = j;
        } else j = nxt[j];
    }
} //get_next


void kmp(string s1, string s2) {
    int i = 0, j = 0;
    while (i < (int)s1.size() && j < (int)s2.size()) {
        if (j == -1 || s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            j = nxt[j];
        }
    }
}
