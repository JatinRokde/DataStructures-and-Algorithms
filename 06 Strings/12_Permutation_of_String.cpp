#include <iostream>
using namespace std;

void itr_perm(char s[], int k)
{
    static int A[10] = {0};
    static char res[10];
    int i;
    if (s[k] == '\0')
    {
        res[k] = '\0';
        cout << res[k];
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[k] = s[i];
                A[i] = 1;
                itr_perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

void rec_perm(char s[], int l, int h)
{
    int i;
    if (l == h)
        cout << s << endl;
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(s[l], s[i]);
            rec_perm(s, l + h, h);
            swap(s[l], s[i]);
        }
    }
}

int main(void)
{
    char s[] = "ABC";
    rec_perm(s, 0, 2);
    return 0;
}