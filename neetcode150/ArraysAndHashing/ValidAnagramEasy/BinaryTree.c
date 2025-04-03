#include <stdio.h>
#include <stdlib.h>

typedef struct Count // Create a bitfiled to store the frequency of a letter in a word
{
    unsigned int value : 4;
} Count;

typedef struct LetterTreeNode LetterTreeNode;

typedef struct LetterTreeNode // Create a node to store the info of a word's letter
{
    unsigned char letter;
    LetterTreeNode* left;
    LetterTreeNode* right;
    Count* count;
} LetterTreeNode;

LetterTreeNode* createLetterTreeNode(char letter) // Create a letter tree node given a letter
{
    LetterTreeNode* letterTreeNode = (LetterTreeNode*)malloc(sizeof(LetterTreeNode));
    letterTreeNode->letter = letter;
    letterTreeNode->left = NULL;
    letterTreeNode->right = NULL;
    letterTreeNode->count = (Count*)malloc(sizeof(Count));
    letterTreeNode->count->value = 1;
    return letterTreeNode;
}

void freeLetterTreeNode(LetterTreeNode* letterTreeNode) // Free the memory allocated for a letter tree node
{
    free(letterTreeNode->count);
    free(letterTreeNode);
}

void insertLetterTreeNode(LetterTreeNode* root, char newLetter) // Insert a letter tree node for a root that will never be null
{
    if (root == NULL) // the root is null
    {
        fprintf(stderr, "ROOT IS NULL!\n"); // reject it
        return;
    }
    if (newLetter < root->letter) // the character is less than the root
    {
        if (root->left == NULL) // go to the left
        {
            root->left = createLetterTreeNode(newLetter);
        }
        else // keep on looking
        {
            insertLetterTreeNode(root->left, newLetter);
        }
    }
    else if (newLetter > root->letter) // the character is greater than the root
    {
        if (root->right == NULL) // go to the right
        {
            root->right = createLetterTreeNode(newLetter);
        }
        else // keep on looking 
        {
            insertLetterTreeNode(root->right, newLetter);
        }
       
    }
    else
    {
        root->count->value++; // the character is the same as the root's character / increment count of letter in tree
    }
}

int main(void)
{
    printf("Hello, World!\n");
    LetterTreeNode* a = createLetterTreeNode('a');
    printf("Letter: %c\n", a->letter);
    printf("Count: %d\n", a->count->value);
    freeLetterTreeNode(a);
    return 0;
}

