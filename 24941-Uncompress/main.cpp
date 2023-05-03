#include <iostream>
#include <cctype>

using namespace std;

struct Node
{
    string word;
    Node *next;
};

int main()
{
    char ch;
    Node *head = NULL;

    ch = getchar();
    while (true)
    {
        if (isdigit(ch))
        {
            if (ch == '0')
                break;

            int num = 0;
            while (isdigit(ch))
            {
                num = num * 10 + (ch - '0');
                ch = getchar();
            }

            Node *prev = NULL;
            Node *now = head;
            for (int i = 1; i < num; i++)
            {
                prev = now;
                now = now->next;
            }
            cout << now->word;

            if (now != head)
            {
                prev->next = now->next;
                now->next = head;
                head = now;
            }
        }
        else if (isalpha(ch))
        {
            string word;
            while (isalpha(ch))
            {
                word += ch;
                ch = getchar();
            }

            cout << word;
            Node *tmp = new Node;
            tmp->word = word;
            tmp->next = head;
            head = tmp;
        }
        else
        {
            putchar(ch);
            ch = getchar();
        }
    }

    return 0;
}