#include <stdio.h>

int check(char table[5][5], char k) {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (table[i][j] == k)
                return 0;
    return 1;
}

int main() {
    char table[5][5], key[26] = {0};
    int i, j, key_len, count = 0, l;
    char p[100], p1[200], cipher_text[200];

    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j)
            table[i][j] = '0';

    printf("Playfair Cipher\n\nEnter the length of the Key: ");
    scanf("%d", &key_len);

    printf("Enter the Key: ");
    scanf("%s", key);

    for (i = 0; i < key_len; ++i)
        if (key[i] == 'j')
            key[i] = 'i';

    int val = 97;
    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j) {
            char ch = (char) val++;
            if (ch == 'j') ch++; // Skip 'j'
            if (check(table, ch))
                table[i][j] = ch;
            else
                --j;
        }

    printf("\nThe table is as follows:\n");
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j)
            printf("%c ", table[i][j]);
        printf("\n");
    }

    printf("\nEnter the length of plain text (without spaces): ");
    scanf("%d", &l);

    printf("Enter the Plain text: ");
    scanf("%s", p);

    for (i = 0; i < l; ++i)
        if (p[i] == 'j')
            p[i] = 'i';

    int count1 = 0;
    for (i = 0; i < l; ++i) {
        p1[count1++] = p[i];
        if (p[i] == p[i + 1]) {
            p1[count1++] = (p[i] == 'x') ? 'z' : 'x';
        }
    }

    if ((l + count) % 2 != 0) {
        p1[l + count] = (p1[l + count - 1] == 'x') ? 'z' : 'x';
        p1[l + count + 1] = '\0';
    } else {
        p1[l + count] = '\0';
    }

    printf("The final text is: %s\n", p1);

    int k1 = 0;
    for (i = 0; i < l + count; i += 2) {
        int r1, c1, r2, c2;
        for (int r = 0; r < 5; ++r)
            for (int c = 0; c < 5; ++c) {
                if (table[r][c] == p1[i]) {
                    r1 = r;
                    c1 = c;
                }
                if (table[r][c] == p1[i + 1]) {
                    r2 = r;
                    c2 = c;
                }
            }

        if (r1 == r2) {
            cipher_text[k1++] = table[r1][(c1 + 1) % 5];
            cipher_text[k1++] = table[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            cipher_text[k1++] = table[(r1 + 1) % 5][c1];
            cipher_text[k1++] = table[(r2 + 1) % 5][c2];
        } else {
            cipher_text[k1++] = table[r1][c2];
            cipher_text[k1++] = table[r2][c1];
        }
    }

    cipher_text[k1] = '\0';

    printf("\nThe Cipher text is: %s\n", cipher_text);

    return 0;
}
