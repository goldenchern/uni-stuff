#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 3

typedef struct _listnode{
    int key;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} HashTableNode;

typedef struct _hashTable{
   int hSize;
   int nSize;
   HashTableNode *Table;
} HashTable;

int Hash(int,int);

ListNode* HashSearch(HashTable, int);
int HashInsert(HashTable *, int);

//In Practice, we will not do it
void HashPrint(HashTable);

int main()
{
    int opt;
    int size;

    int i;
    int key;

    //Create a HashTable
    HashTable Q4Hash;
    Q4Hash.hSize = 0;
    Q4Hash.nSize = 0;
    Q4Hash.Table = NULL;

    printf("============= Hash Table ============\n");
    printf("|1. Create a hash table             |\n");
    printf("|2. Insert a key to the hash table  |\n");
    printf("|3. Search a key in the hash table  |\n");
    printf("|4. Print the hash table            |\n");
    printf("|5. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=4){
        switch(opt){
        case 1:
            printf("Enter number of data to be inserted:\n");
            scanf("%d",&size);

            Q4Hash.hSize = (int)size/ LOAD_FACTOR;
            Q4Hash.nSize = 0;

            Q4Hash.Table = (HashTableNode *) malloc(sizeof(HashTableNode)*(Q4Hash.hSize));

            for(i=0;i<Q4Hash.hSize;i++){
               Q4Hash.Table[i].head = NULL;
               Q4Hash.Table[i].size = 0;
            }
            printf("HashTable is created.\n");
            break;
        case 2: //Insertion
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);

            if(HashInsert(&Q4Hash,key))
                printf("%d is inserted.\n",key);
            else
                printf("%d is a duplicate. No key is inserted.\n",key);
            break;
        case 3: //Search
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            ListNode* node = HashSearch(Q4Hash, key);

            if(node!=NULL)
                printf("%d is found.\n",key);
            else
                printf("%d is not found.\n",key);
            break;
        case 4:
            HashPrint(Q4Hash);
            break;
        }

    printf("Enter selection: ");
    scanf("%d",&opt);
    }

    for(i=0;i<Q4Hash.hSize;i++)
    {
        while(Q4Hash.Table[i].head)
        {
            ListNode *temp;
            temp = Q4Hash.Table[i].head;
            Q4Hash.Table[i].head = Q4Hash.Table[i].head->next;
            free(temp);
        }
    }
    free(Q4Hash.Table);

    return 0;

}

int Hash(int key,int hSize)
{
    return key%hSize;
}

ListNode* HashSearch(HashTable Q4Hash, int key)
{
    int slot = Hash(key, Q4Hash.hSize);
    ListNode *temp = Q4Hash.Table[slot].head;

    while (temp != NULL) {
        if (temp->key == key) {
            break;
        }
        temp = temp->next;
    }

    return temp;
}

int HashInsert(HashTable* Q4HashPtr, int key)
{
    if (HashSearch(*Q4HashPtr, key) != NULL) {
        return 0;
    }
    
    // Create a new node using DMA
    int slot = Hash(key, Q4HashPtr->hSize);
    ListNode *newNode = malloc(sizeof(ListNode));
    newNode->key = key;
    newNode->next = Q4HashPtr->Table[slot].head;
    
    // Insert the node into the linked list
    Q4HashPtr->Table[slot].head = newNode;
    Q4HashPtr->Table[slot].size++;

    return 1;
}

void HashPrint(HashTable Q4Hash)
{
    int i;
    ListNode *temp;
    for(i=0;i<Q4Hash.hSize;i++)
    {
        temp =Q4Hash.Table[i].head;
        printf("%d:  ",i);
        while(temp !=NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}
