#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure d'un élément de la liste chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour afficher la liste
void display(Node* head) {
    Node* current = head;
    printf("Liste : ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Fonction pour ajouter un élément à la fin de la liste
void append(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Fonction pour réinitialiser la liste
void reset(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

// Fonction principale
int main() {
    Node* head = NULL;
    char operation[10];
    int data;

    while (1) {
        printf("Opération ? ");
        scanf("%s", operation);

        if (strcmp(operation, "-d") == 0 || strcmp(operation, "--display") == 0) {
            display(head);
        } else if (strcmp(operation, "-A") == 0) {
            printf("Entrez la valeur à ajouter : ");
            scanf("%d", &data);
            append(&head, data);
        } else if (strcmp(operation, "-i") == 0) {
            reset(&head);
            printf("Liste réinitialisée.\n");
        } else if (strcmp(operation, "-q") == 0) {
            break;
        } else {
            printf("Opération non reconnue.\n");
        }
    }

    // Libération de la mémoire allouée pour la liste chaînée
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
