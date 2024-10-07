#include <stdlib.h>
#include <string.h>
#include "get_input.c"
#include <ctype.h>

typedef struct person
{
    string name;
    struct person *next;

} person;

typedef struct hash_tabale
{
    person *item;
} hash_tabale;

int to_hash(string value);
void de_allocate(hash_tabale *table);
int main()
{
    // initialize hash_table
    hash_tabale hash1[26];
    for (int i = 0; i <= 26; i++)
    {
        hash_tabale h1;
        hash1[i] = h1;
    }
    // print information for useing
    printf("for_add_: 1 __ for_delete_: 2 __ for_show_: 3 __ for_exit_: 0 __\n\n");

    // get user intput
    while (1)
    {
        int code = get_int("enter_code : ");
        if (code == 0)
        {
            // if input = 0 break the loop

            break;
        }
        else if (code == 1)
        {
            // if input = 1 go to add value to hash_table0

            string input = get_string("name : ");
            int index = to_hash(input);
            if (hash1[index].item == NULL)
            {
                person *p = malloc(sizeof(person));
                p->name = input;
                p->next = NULL;
                hash1[index].item = p;
            }
            else
            {
                person *p = malloc(sizeof(person));
                p->name = input;
                p->next = hash1[index].item;
                hash1[index].item = p;
            }
        }
        else if (code == 2)
        {
            string name = get_string("name : ");
            int index = to_hash(name);
            if (hash1[index].item == NULL)
            {
                printf("not_exist...\n");
            }
            else
            {

                person *p = hash1[index].item;
                person *pb = NULL;
                person *pa = hash1[index].item->next;
                while (1)
                {
                    if (p->next == NULL && strcmp(p->name, name) == 0)
                    {

                        free(p->name);
                        free(p->next);
                        free(p);
                        printf("deleted...\n");
                        free(name);
                        hash1[index].item = NULL;
                        break;
                    }
                    else if (pb == NULL && strcmp(p->name, name) == 0)
                    {
                        hash1[index].item = p->next;
                        free(p->name);
                        free(p);
                        printf("deleted...\n");
                        break;
                    }
                    else if (p->next == NULL && strcmp(p->name, name) != 0)
                    {
                        free(name);
                        printf("not_exist...\n");
                        break;
                    }
                    else if (strcmp(name, p->name) == 0)
                    {

                        pb->next = pa;
                        free(p->name);
                        free(p);
                        printf("deleted...\n");
                        free(name);
                        break;
                    }
                    else
                    {

                        pb = p;
                        p = p->next;
                        pa = p->next;
                    }
                }
            }
        }
        else if (code == 3)
        {
            for (int i = 0; i <= 26; i++)
            {
                if (hash1[i].item == NULL)
                {
                    printf("[%i]:\n", i);
                }
                else
                {
                    printf("[%i]:", i);
                    person *p = hash1[i].item;
                    while (1)
                    {
                        if (p->next == NULL)
                        {
                            printf("--->[%s]\n", p->name);
                            break;
                        }
                        else
                        {
                            printf("--->[%s]", p->name);
                            p = p->next;
                        }
                    }
                }
            }
        }
    }
    de_allocate(&hash1);
}

int to_hash(string value)
{
    return toupper(value[0]) - 'A';
}
void de_allocate(hash_tabale *table)
{
    int a = 0;
    for (int i = 0; i <= 26; i++)
    {
        a++;
        if (table[i].item == NULL)
        {
        }
        else
        {
            int b = 0;
            person *p = table[i].item;
            while (1)
            {
                b++;
                if (p->next == NULL)
                {
                    free(p->name);
                    free(p->next);
                    free(p);
                    break;
                }
                else
                {
                    person *pfree = p;
                    p = p->next;
                    free(pfree->name);
                    free(pfree);
                }
            }
            printf("%i\n", b);
        }
    }
    printf("%i\n", a);
}