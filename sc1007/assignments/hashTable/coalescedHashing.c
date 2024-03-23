#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED};

typedef struct _slot{
    int key;
    enum Marker indicator;
    int next;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashFind(int key, HashSlot hashTable[]);

int hash(int key)
{
    return (key % TABLESIZE);
}

int main()
{
    int opt;
    int i;
    int key;
    int index;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].next = -1;
        hashTable[i].key = 0;
        hashTable[i].indicator = EMPTY;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Search a key in the hash table  |\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
        case 1:
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            index = HashInsert(key,hashTable);
            if(index <0)
                printf("Duplicate key\n");
            else if(index < TABLESIZE)
                printf("Insert %d at index %d\n",key, index);
            else
                printf("Table is full.\n");
            break;
        case 2:
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            index = HashFind(key, hashTable);

            if(index!=-1)
                printf("%d is found at index %d.\n",key,index);
            else
                printf("%d is not found.\n",key);
            break;

        case 3:
            printf("index:\t key \t next\n");
            for(i=0;i<TABLESIZE;i++) printf("%d\t%d\t%d\n",i, hashTable[i].key,hashTable[i].next);
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int HashInsert(int key, HashSlot hashTable[])
{
    int count = 0, curIndex = hash(key), linkIndex = -1;

    while (1) {
        // Check if table is full
        if (count++ == TABLESIZE) {
            return TABLESIZE;
        } 

        // Check for duplicate (indicator check redundant?)
        if (hashTable[curIndex].indicator == USED && hashTable[curIndex].key == key) {
            return -1;
        }
        
        // If slot empty, insert key and update link if necessary
        if (hashTable[curIndex].indicator == EMPTY) {
            hashTable[curIndex].key = key;
            hashTable[curIndex].indicator = USED;
            if (linkIndex != -1) {
                hashTable[linkIndex].next = curIndex;
            }
            return curIndex;
        }

        // Slot must be occupied; move to next slot if specified
        if (hashTable[curIndex].next != -1 && linkIndex == -1) {
            curIndex = hashTable[curIndex].next;
            continue;
        }
        
        // Keep track of original slot index
        if (linkIndex == -1) {
            linkIndex = curIndex;
        }

        // Linear probing
        curIndex = (curIndex + 1) % TABLESIZE;
    }
}

int HashFind(int key, HashSlot hashTable[])
{
    int count = 0, curIndex = hash(key);

    while (1) {
        // Table is full or key not found
        if (count++ == TABLESIZE || hashTable[curIndex].indicator == EMPTY || curIndex == -1) {
            return -1;
        }

        // Compare keys (indicator check redundant?)
        if (hashTable[curIndex].indicator == USED && hashTable[curIndex].key == key) {
            return curIndex;
        }

        // Move to next slot
        curIndex = hashTable[curIndex].next;
    }
}