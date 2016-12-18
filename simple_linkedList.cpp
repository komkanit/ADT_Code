#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct test_struct
{
    int val;
    struct test_struct *next;
} TYPE_NODE;

TYPE_NODE *head = NULL;
TYPE_NODE *curr = NULL;

TYPE_NODE* create_list(int val)
{
    printf("\n creating list with headnode as [%d]\n",val);
    TYPE_NODE *ptr = (TYPE_NODE*)malloc(sizeof(TYPE_NODE));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

TYPE_NODE* add_to_list(int val, bool add_to_end)
{
    if(NULL == head)
    {
        return (create_list(val));
    }

    if(add_to_end)
        printf("\n Adding node to end of list with value [%d]\n",val);
    else
        printf("\n Adding node to beginning of list with value [%d]\n",val);

    TYPE_NODE *ptr = (TYPE_NODE*)malloc(sizeof(TYPE_NODE));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    if(add_to_end)
    {
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}

TYPE_NODE* search_in_list(int val, TYPE_NODE **prev)
{
    TYPE_NODE *ptr = head;
    TYPE_NODE *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n",val);

    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

int delete_from_list(int val)
{
    TYPE_NODE *prev = NULL;
    TYPE_NODE *del = NULL;

    printf("\n Deleting value [%d] from list\n",val);

    del = search_in_list(val,&prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}

void print_list(void)
{
    TYPE_NODE *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("\n [%d] \n",ptr->val);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}

int main(void)
{
    int i = 0, ret = 0;
    TYPE_NODE *ptr = NULL;
    char input[100];
    int data;
    
    print_list();
    while(1){
      printf("command: ");
      scanf("%s",input);
      if(strcmp(input,"add") == 0) {
        printf("input: ");
        scanf("%d",&data);
        add_to_list(data,true);
      }
      else if(strcmp(input,"print") == 0) {
        print_list();
      }
      else if(strcmp(input,"delete") == 0) {
        printf("input: ");
        scanf("%d",&data);
        delete_from_list(data);
      }
    }

    return 0;
}