#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<strings.h>

typedef struct hashTable
{
    char key[101];
    int count;
    int capacity;
    char **strings;
    struct hashTable* next;
    
}hashTable;

// Comparison function for qsort to sort characters
int compare_chars(const void* a, const void* b) 
{
    return *(const char*)a - *(const char*)b;
}

/*
function names -
1. Hash_add  ✔️
2. Hash_iterate ✔️
3. Hash_find  ✔️
4. Hash_delete ✔️
*/

//3. Hash_find
hashTable* Hash_find (struct hashTable* anagramGroup, char* sortedKey)
{
    struct hashTable* p = anagramGroup;
    while (p != NULL) // Iterate through the list until the end
    {
        if (strcmp(p->key, sortedKey) == 0) // Use strcmp for string comparison
        {
            return p; // Return the node if key is found
        }
        p = p->next; // Move to the next node
    }
    return NULL; // Return NULL if key is not found after checking all nodes
}

//1. Hash_addNewGroup
hashTable* Hash_addNewGroup(struct hashTable* anagramGroup, char* sortedKey)
{
    //new node will be added so memory needs to be allocated
    hashTable* newNode=(struct hashTable*)malloc(sizeof(struct hashTable));
    //copying the sorted string in the key of the new node;4
    strcpy(newNode->key, sortedKey);
    newNode->capacity=1;//for now, max capacity is 1...will be increased manually later on if count==capacity
    newNode->count=0; //indexing starting from 0
    newNode->strings=(char**)malloc(newNode->capacity*sizeof(char*));
    //array for storing original strings to respective groups is initialized
    newNode->next=NULL;
    
    //if no groups are added in the list and this is the first group
    if(anagramGroup==NULL)
	{
		anagramGroup=newNode;
		return anagramGroup;
	}
    //need to traverse to the last node of the current list
    struct hashTable* p=anagramGroup;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newNode;
    return newNode;

}

//2. Hash_Iter
int Hash_count(struct hashTable* anagramGroup)
{
    hashTable* p=anagramGroup;
    int n=0;
    while(p!=NULL)
    {
        p=p->next;
        n++;   
    }
    return n;
   
}

//4. Hash_delete
void Hash_del(hashTable** anagramGroup, hashTable* currGroup) 
{
    if (anagramGroup == NULL || *anagramGroup == NULL || currGroup == NULL) 
    {
        return; // Nothing to do
    }

    // Case 1: The item to be deleted is the head of the hash table
    if (*anagramGroup == currGroup) {
        *anagramGroup = currGroup->next;
        // You also need to free the memory for the strings array and the item itself
        if (currGroup->strings != NULL) {
            for (int i = 0; i < currGroup->count; i++) {
                free(currGroup->strings[i]);
            }
            free(currGroup->strings);
        }
        free(currGroup);
        return;
    }

    // Case 2: Find the item and remove it from the list
    hashTable* current = *anagramGroup;
    while (current->next != NULL && current->next != currGroup) {
        current = current->next;
    }

    // If item was found
    if (current->next == currGroup) {
        current->next = currGroup->next;
        // Free the memory for the strings array and the item itself
        if (currGroup->strings != NULL) {
            for (int i = 0; i < currGroup->count; i++) {
                free(currGroup->strings[i]);
            }
            free(currGroup->strings);
        }
        free(currGroup);
    }
}


char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    struct hashTable* anagramGroup =NULL, *item; //initializing the 'head' of the hashtable
    //taking another empty node to run operations
    //first pass : build the hashtable by sorting strings and grouping
    for(int i=0; i<strsSize; i++)
    {
        char* original_str=strs[i];
        char sortedkey[101];
        strcpy(sortedkey, original_str);
        qsort(sortedkey, strlen(original_str), sizeof(char), compare_chars);
        item=Hash_find(anagramGroup, sortedkey);
        
        /*means either their is no group is anagramGroup (empty hashtable)
        OR the particular group is no present*/ 

        if(item == NULL)
        {
            item = Hash_addNewGroup(anagramGroup, sortedkey);
            //copying of ssorted string done in the function
            //capacity, count all are updated in the function
        }

        //now, either the newly created group node will be pointed by the 'item' variable or a preexisting group will be pointed by item...
        //now to manage the capacity of the 'strings' array before push the original strings to their respective sorted groups

        if(item->count==item->capacity)
        {
            item->capacity*2;
            item->strings=(char**)realloc(item->strings,item->capacity*sizeof(char*));

        }
        
        item->strings[item->count]=original_str;
    }
    //for loop is now completed 
    //hashtable is updated and all strings are correctly grouped
    int numGroups = Hash_count(anagramGroup);
    *returnSize = numGroups;
    char ***result = (char ***)malloc(numGroups * sizeof(char **));
    *returnColumnSizes = (int *)malloc(numGroups * sizeof(int));

    // Step 1: Populate the results array in a separate loop
    struct hashTable *currGroup = anagramGroup;
    int groupIndex = 0;
    while (currGroup != NULL)
    {
        result[groupIndex] = currGroup->strings;
        (*returnColumnSizes)[groupIndex] = currGroup->count;
        groupIndex++;
        currGroup = currGroup->next;
    }

    // Step 2: Free the hash table memory in another loop
    // This is necessary because you are returning pointers to the 'strings' arrays,
    // so you must not free them yet. You just need to free the nodes.
    currGroup = anagramGroup;
    while (currGroup != NULL)
    {
        struct hashTable *temp = currGroup;
        currGroup = currGroup->next;
        free(temp); // Free the node, but not the strings array
    }

    return result;
}