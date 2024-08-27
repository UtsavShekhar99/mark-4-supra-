// implementation of doubly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    struct node *prev;
    int data;
    struct node *next;
}NODE;
typedef struct dlist
{
    NODE *head;
}DLIST;
void init_list(DLIST *);
void insert_head(DLIST *, int);
void display(DLIST *);
void insert_tail(DLIST *, int);
void delete_first(DLIST *);
void delete_last(DLIST *);
void delete_node(DLIST *, int);
void delete_pos(DLIST *, int);
void insert_pos(DLIST *, int, int);
void insert_after(DLIST *, int, int);
void insert_before(DLIST *, int, int);

int main()
{
    int ch, data, pos, value;
    DLIST l;
    init_list(&l);

    while (1)
    {
        display(&l);
        printf("\n1..insert_head");
        printf("\n2..insert_tail");
        printf("\n3..Display");
        printf("\n4.delete first node");
        printf("\n5. Delete Last Node..");
       // printf("\n6 .Delete a node given value");
       // printf("\n7.Delete at a position");
        printf("\n8.Insert at a Given Position");
       // printf("\n9. Insert after given value..\n");
       // printf("\n10. Insert before given value..\n");
        printf("\n11.Exit");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data...");
            scanf("%d", &data);
            insert_head(&l, data);
            break;
        case 2:
            printf("\nEnter the data...");
            scanf("%d", &data);
            insert_tail(&l, data);
            break;
        case 3:
            display(&l);
            break;
        case 4:
            delete_first(&l);
            break;
        case 5:
            delete_last(&l);
            break;
        /*case 6:
            printf("\nEnter the data...");
            scanf("%d", &data);
            delete_node(&l, data);
            break;
        case 7:
            printf("\nEnter the position");
            scanf("%d", &pos);
            delete_pos(&l, pos);
            break;*/
        case 8:
            printf("\nEnter the data and position");
            scanf("%d %d", &data, &pos);
            insert_pos(&l, data, pos);
            break;
        /*case 9:printf("\nEnter the value and data");
                     scanf("%d %d" ,&value,&data);
                    insert_after(&l,value,data);
                    break;
        case 10:printf("\nEnter the value and data");
                     scanf("%d %d" ,&value,&data);
                   insert_before(&l,value,data);
                   break;	*/
        case 11:
            exit(0);
        }
    }
}

void init_list(DLIST *ptr_list)
{
    ptr_list->head = NULL;
}

void insert_head(DLIST *ptr_list, int data)
{

    // create node
    NODE *temp;

    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = temp->prev = NULL;

    // if first node ?
    if (ptr_list->head == NULL)
        ptr_list->head = temp;

    else
    {
        temp->next = ptr_list->head;
        ptr_list->head->prev = temp;
        ptr_list->head = temp;
    }
}

void display(DLIST *ptr_list)
{
    NODE *pres;
    pres = ptr_list->head;

    if (pres == NULL)
        printf("\nEmpty List..\n");
    else
    {
        while (pres != NULL)
        {
            printf("%d<->", pres->data);
            pres = pres->next;
        }
    }
    printf("\n");
}
void delete_first(DLIST *ptr_list)
{
    NODE *pres;

    pres = ptr_list->head;

    if (pres->next == NULL) // only one node
        ptr_list->head = NULL;
    else
    {
        pres->next->prev = NULL;
        ptr_list->head = pres->next;
    }
    free(pres);
}
void insert_tail(DLIST *ptr_list, int data){
    NODE *temp = (NODE *)malloc(sizeof(NODE)); 
    temp-> data = data;
    // temp-> next = temp-> prev = NULL;
    temp -> next = NULL;
    temp -> prev = NULL;

    if(ptr_list == NULL )
    ptr_list-> head = temp;
    else{
        NODE *p = ptr_list-> head;
        while (p-> next!=NULL)
        {
            p = p-> next;
            p-> next = temp;
            temp-> prev = p;
        }
        
    }
}
void delete_last(DLIST *ptr_list){
    NODE *p = ptr_list -> head;
    if(p-> next = NULL){
        ptr_list-> head = NULL;

    }   
    else{
        while (p->next != NULL)
        {
            p = p-> next;
            p-> prev-> next = NULL;

        }        
    }
    free(p);
}

