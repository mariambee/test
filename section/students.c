#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>

typedef struct node
{
    char* name;
    struct node* next;
} node;

// (*n).name   or   n->name

void insert(char* name);
bool find(char* name);

// Create a global pointer to a linked list of students
node* students = NULL;

int main(int argc, char* argv[])
{
    
    // Insert names into a linked list.
    for (int i = 1; i < argc; i++)
    {
        insert(argv[i]);
    }
    
    // Get a name of a student to find in the list from the user
    printf("Enter a student's name: ");
    char* name = GetString();
    
    // While user hasn't pressed enter
    while (strcmp(name, "") != 0)
    {
        // Check to see if the user is in the list
        if (find(name))
        {
            printf("%s was in the linked list!\n", name);
        }
        else
        {
            printf("%s was not in the linked list.\n", name);
        }
        
        // Re-prompt user for a students name        
        printf("Enter a student's name: ");
        name = GetString();
    }
    
    return 0;
}


void insert(char* name)
{
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        return NULL;
    }
    n->name = name;
    n->next = students;
    students = n; 
    
    // Create a new node

    // Check for NULL
    
    // Initialize new node

    // Insert new node at the head
    return;
}

bool find(char* name)
{
    // Initialize starting node
    
    // Iterate until we reach end of list

        // Check if the current contains student.
        
        // Increment to the next node in the list

    // We haven't found the student in the list
    return false;
}


strcasecomp 


        if (hashtable[bucket] == NULL)
        {
            hashtable[bucket] = newword;
            newword->next = NULL;
        }
        // if bucket is not empty (collision)
        else
        {
            newword->next = hashtable[bucket];
            hashtable[bucket] = newword;
        }