void strcpyHomemade(char* dest, const char* source) {
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }

    dest[i] = source[i];
}

int isStringEqual(const char* s1, const char* s2) {
    int i = 0;
    while(s1[i] != '\0' || s2[i] != '\0') {
        if(s1[i] != s2[i]) return 0;
        ++i;
    }
    return 1;
}
