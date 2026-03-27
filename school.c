#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tree Node Structure
struct Node {
    char name[50];
    struct Node* child;
    struct Node* sibling;
};

// Create Node
struct Node* createNode(char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Add Child Node
void addChild(struct Node* parent, char name[]) {
    struct Node* newNode = createNode(name);

    if (parent->child == NULL) {
        parent->child = newNode;
    } else {
        struct Node* temp = parent->child;
        while (temp->sibling != NULL)
            temp = temp->sibling;
        temp->sibling = newNode;
    }
}

// Display Tree
void display(struct Node* root, int level) {
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        printf("  ");

    printf("- %s\n", root->name);

    display(root->child, level + 1);
    display(root->sibling, level);
}

// Search Node
struct Node* search(struct Node* root, char name[]) {
    if (root == NULL)
        return NULL;

    if (strcmp(root->name, name) == 0)
        return root;

    struct Node* found = search(root->child, name);
    if (found != NULL)
        return found;

    return search(root->sibling, name);
}

// Update Node
void update(struct Node* root) {
    char oldName[50], newName[50];
    printf("Enter name to update: ");
    scanf("%s", oldName);

    struct Node* node = search(root, oldName);

    if (node != NULL) {
        printf("Enter new name: ");
        scanf("%s", newName);
        strcpy(node->name, newName);
        printf("Updated successfully!\n");
    } else {
        printf("Node not found!\n");
    }
}

// Delete Node (simple version)
struct Node* deleteNode(struct Node* root, char name[]) {
    if (root == NULL)
        return NULL;

    if (root->child != NULL && strcmp(root->child->name, name) == 0) {
        struct Node* temp = root->child;
        root->child = temp->sibling;
        free(temp);
        return root;
    }

    struct Node* prev = root->child;
    if (prev != NULL) {
        struct Node* curr = prev->sibling;

        while (curr != NULL) {
            if (strcmp(curr->name, name) == 0) {
                prev->sibling = curr->sibling;
                free(curr);
                return root;
            }
            prev = curr;
            curr = curr->sibling;
        }
    }

    deleteNode(root->child, name);
    deleteNode(root->sibling, name);

    return root;
}

// Main Function
int main() {
    int choice;
    char parentName[50], name[50];

    struct Node* school = createNode("School");

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Node\n");
        printf("3. Update Node\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter parent name: ");
                scanf("%s", parentName);
                printf("Enter new node name: ");
                scanf("%s", name);

                struct Node* parent = search(school, parentName);
                if (parent != NULL) {
                    addChild(parent, name);
                    printf("Added successfully!\n");
                } else {
                    printf("Parent not found!\n");
                }
                break;

            case 2:
                printf("Enter node name to delete: ");
                scanf("%s", name);
                deleteNode(school, name);
                printf("Deleted (if existed)\n");
                break;

            case 3:
                update(school);
                break;

            case 4:
                printf("Enter name to search: ");
                scanf("%s", name);
                if (search(school, name))
                    printf("Found!\n");
                else
                    printf("Not found!\n");
                break;

            case 5:
                printf("\nSchool Hierarchy:\n");
                display(school, 0);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}