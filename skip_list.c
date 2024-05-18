#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 6

struct Node
{
    int key;
    struct Node *next[MAX_LEVEL];
};

struct SkipList
{
    int level;
    struct Node *head;
};

struct Node *createNode(int key, int level)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->key = key;
    for (int i = 0; i < level; i++)
    {
        newNode->next[i] = NULL;
    }
    return newNode;
}

struct SkipList *createSkipList()
{
    struct SkipList *list = malloc(sizeof(struct SkipList));
    list->level = 1;
    list->head = createNode(-1, MAX_LEVEL);
    return list;
}

void insert(struct SkipList *list, int key)
{
    struct Node *current = list->head;
    struct Node *update[MAX_LEVEL];
    for (int i = list->level - 1; i >= 0; i--)
    {
        while (current->next[i] != NULL && current->next[i]->key < key)
        {
            current = current->next[i];
        }
        update[i] = current;
    }
    current = current->next[0];

    if (current == NULL || current->key != key)
    {
        int newLevel = rand() % MAX_LEVEL + 1;
        if (newLevel > list->level)
        {
            for (int i = list->level; i < newLevel; i++)
            {
                update[i] = list->head;
            }
            list->level = newLevel;
        }
        struct Node *newNode = createNode(key, newLevel);
        for (int i = 0; i < newLevel; i++)
        {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }
}

void delete(struct SkipList *list, int key)
{
    struct Node *current = list->head;
    struct Node *update[MAX_LEVEL];
    for (int i = list->level - 1; i >= 0; i--)
    {
        while (current->next[i] != NULL && current->next[i]->key < key)
        {
            current = current->next[i];
        }
        update[i] = current;
    }
    current = current->next[0];

    if (current != NULL && current->key == key)
    {
        for (int i = 0; i < list->level; i++)
        {
            if (update[i]->next[i] != current)
            {
                break;
            }
            update[i]->next[i] = current->next[i];
        }
        free(current);
        while (list->level > 1 && list->head->next[list->level - 1] == NULL)
        {
            list->level--;
        }
    }
}

int search(struct SkipList *list, int key)
{
    struct Node *current = list->head;
    for (int i = list->level - 1; i >= 0; i--)
    {
        while (current->next[i] != NULL && current->next[i]->key < key)
        {
            current = current->next[i];
        }
    }
    current = current->next[0];
    if (current != NULL && current->key == key)
    {
        return 1;
    }
    return 0;
}

void printSkipList(struct SkipList *list)
{
    struct Node *current = list->head;
    while (current->next[0] != NULL)
    {
        printf("%d ", current->next[0]->key);
        current = current->next[0];
    }
    printf("\n");
}

int main()
{
    struct SkipList *list = createSkipList();

    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 4);
    insert(list, 5);
    insert(list, 6);

    printSkipList(list);

    delete (list, 3);

    printSkipList(list);

    printf("%d\n", search(list, 4));
    printf("%d\n", search(list, 3));

}