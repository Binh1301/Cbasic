#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char text[100];
    int count;
} Word;

int main()
{
    char line[512];
    Word tu[1000];
    int n = 0;

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        int len = strlen(line);

        for (int i = 0; i < len; i++)
        {
            if (!isalpha(line[i]))
                line[i] = ' ';
            else
                line[i] = tolower(line[i]);
        }


        char* token = strtok(line, " ");
        while (token != NULL)
        {
            int found = 0;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(tu[i].text, token) == 0)
                {
                    tu[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                strcpy(tu[n].text, token);
                tu[n].count = 1;
                n++;
            }

            token = strtok(NULL, " ");
        }
    }


    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(tu[i].text, tu[j].text) > 0)
            {
                Word tmp = tu[i];
                tu[i] = tu[j];
                tu[j] = tmp;
            }

    for (int i = 0; i < n; i++)
        printf("%s %d\n", tu[i].text, tu[i].count);

    return 0;
}
