#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int countNodes(struct node *first) {
    if (first == NULL) return 0;
    int count = 0;
    struct node *temp = first;
    do {
        count++;
        temp = temp->next;
    } while (temp != first);
    return count;
}

struct node* createCLL(int n) {
    if (n <= 0) return NULL;

    struct node *first = NULL, *last = NULL, *temp;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = value;
        temp->next = NULL;

        if (first == NULL) {
            first = last = temp;
            last->next = first;
        } else {
            last->next = temp;
            last = temp;
            last->next = first;
        }
    }
    return first;
}

void traverseListInCLL(struct node *first) {
    if (first == NULL) return;

    struct node *temp = first;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}

struct node* insertAtPositionInCLL(struct node *first, int pos, int value) {
    int n = countNodes(first);

    if (pos < 1 || pos > n + 1) {
        printf("Position not found\n");
        return first;
    }

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    if (first == NULL) {
        temp->next = temp;
        return temp;
    }

    if (pos == 1) {
        struct node *last = first;
        while (last->next != first)
            last = last->next;

        temp->next = first;
        last->next = temp;
        return temp;
    }

    struct node *current = first;
    for (int i = 1; i < pos - 1; i++)
        current = current->next;

    temp->next = current->next;
    current->next = temp;

    return first;
}

struct node* deleteAtPositionInCLL(struct node *first, int pos) {
    if (first == NULL) {
        printf("CLL is empty\n");
        return NULL;
    }

    int n = countNodes(first);

    if (pos < 1 || pos > n) {
        printf("Position not found\n");
        return first;
    }

    struct node *temp, *current = first;

    if (pos == 1) {
        if (n == 1) {
            printf("Deleted element: %d\n", first->data);
            free(first);
            return NULL;
        }

        struct node *last = first;
        while (last->next != first)
            last = last->next;

        printf("Deleted element: %d\n", first->data);
        temp = first;
        first = first->next;
        last->next = first;
        free(temp);
        return first;
    }

    for (int i = 1; i < pos - 1; i++)
        current = current->next;

    temp = current->next;
    printf("Deleted element: %d\n", temp->data);
    current->next = temp->next;
    free(temp);

    return first;
}

struct node* reverseCLL(struct node *first) {
    if (first == NULL) return NULL;

    struct node *prev = NULL, *current = first, *nextNode;
    struct node *last = first;

    while (last->next != first)
        last = last->next;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != first);

    first->next = prev;
    first = prev;

    return first;
}

struct node* concatCLL(struct node *first, struct node *second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    struct node *last1 = first;
    while (last1->next != first)
        last1 = last1->next;

    struct node *last2 = second;
    while (last2->next != second)
        last2 = last2->next;

    last1->next = second;
    last2->next = first;

    return first;
}

int main() {
    struct node *first = NULL, *second = NULL;
    int choice, n, pos, value;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("How many nodes? ");
            scanf("%d", &n);
            first = createCLL(n);
            break;

        case 2:
            printf("Position: ");
            scanf("%d", &pos);
            printf("Element: ");
            scanf("%d", &value);
            first = insertAtPositionInCLL(first, pos, value);
            break;

        case 3:
            printf("Position: ");
            scanf("%d", &pos);
            first = deleteAtPositionInCLL(first, pos);
            break;

        case 4:
            if (first == NULL)
                printf("CLL is empty\n");
            else {
                printf("Elements in CLL are: ");
                traverseListInCLL(first);
            }
            break;

        case 5:
            if (first == NULL)
                printf("CLL is empty\n");
            else {
                first = reverseCLL(first);
                printf("CLL reversed\n");
                traverseListInCLL(first);
            }
            break;

        case 6:
            printf("Creating second CLL to concatenate...\n");
            printf("How many nodes in second CLL? ");
            scanf("%d", &n);
            second = createCLL(n);
            first = concatCLL(first, second);
            printf("Concatenated CLL:\n");
            traverseListInCLL(first);
            break;

        case 7:
            exit(0);
        }
    }
}
