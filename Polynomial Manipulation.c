#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAX_LEN 100

typedef struct polynomial {
    int coefficient;
    int exponent;
} polynomial;

typedef struct poly_node {
    polynomial poly;
    struct poly_node* next;
} poly_node;

typedef struct poly_id {
    int id;
    poly_node* polynomial;
    struct poly_id* next;
} poly_id;

poly_id* create_poly_id(poly_id* head, int poly_id_val) {
    if (head == NULL) {
        poly_id* new_poly_id = (poly_id*)malloc(sizeof(poly_id));
        new_poly_id->id = poly_id_val;
        new_poly_id->polynomial = NULL;
        new_poly_id->next = NULL;
        return new_poly_id;
    }

    poly_id* tmp = head;
    while (tmp != NULL) {
        if (tmp->id == poly_id_val) {
            return head;
        }
        tmp = tmp->next;
    }

    poly_id* new_poly_id = (poly_id*)malloc(sizeof(poly_id));
    new_poly_id->id = poly_id_val;
    new_poly_id->polynomial = NULL;
    new_poly_id->next = NULL;

    tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_poly_id;

    return head;
}

poly_node* create_poly_node(int coefficient, int exponent) {
    poly_node* new_poly_node = (poly_node*)malloc(sizeof(poly_node));
    new_poly_node->poly.coefficient = coefficient;
    new_poly_node->poly.exponent = exponent;
    new_poly_node->next = NULL;
    return new_poly_node;
}

poly_node* insert_term(poly_node* head, int coefficient, int exponent) {
    poly_node* new_term = create_poly_node(coefficient, exponent);

    if (head == NULL || exponent > head->poly.exponent) {
        new_term->next = head;
        return new_term;
    }

    poly_node* tmp = head;
    poly_node* prev = NULL;
    while (tmp != NULL && tmp->poly.exponent > exponent) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp != NULL && tmp->poly.exponent == exponent) {
        tmp->poly.coefficient += coefficient;
        free(new_term);
    } else {
        if (prev == NULL) {
            new_term->next = head;
            head = new_term;
        } else {
            new_term->next = prev->next;
            prev->next = new_term;
        }
    }

    return head;
}

void add_term(poly_id* head, int poly_id_val, int coefficient, int exponent) {
    poly_id* tmp = head;
    while (tmp != NULL) {
        if (tmp->id == poly_id_val) {
            tmp->polynomial = insert_term(tmp->polynomial, coefficient, exponent);
            break;
        }
        tmp = tmp->next;
    }
}

void print_poly(poly_id* head, int poly_id_val) {
    poly_id* tmp = head;
    while (tmp != NULL) {
        if (tmp->id == poly_id_val) {
            poly_node* poly = tmp->polynomial;
            while (poly != NULL) {
                printf("%d %d ", poly->poly.coefficient, poly->poly.exponent);
                poly = poly->next;
            }
            printf("\n");
            break;
        }
        tmp = tmp->next;
    }
}

int evaluate_poly(poly_id* head, int poly_id_val, int val) {
    poly_id* tmp = head;
    while (tmp != NULL) {
        if (tmp->id == poly_id_val) {
            poly_node* poly = tmp->polynomial;
            int result = 0;
            while (poly != NULL) {
                result += poly->poly.coefficient * pow(val, poly->poly.exponent);
                poly = poly->next;
            }
            return result;
        }
        tmp = tmp->next;
    }
    return 0;
}

poly_id* add_poly(poly_id** head, int poly_id_val_1, int poly_id_val_2, int result_poly_id) {
    poly_id* tmp = *head;
    poly_id* poly_id_val1 = NULL;
    poly_id* poly_id_val2 = NULL;
    poly_id* poly_id_val3 = NULL;

    while (tmp != NULL) {
        if (tmp->id == poly_id_val_1) {
            poly_id_val1 = tmp;
        }
        if (tmp->id == poly_id_val_2) {
            poly_id_val2 = tmp;
        }
        if (tmp->id == result_poly_id) {
            poly_id_val3 = tmp;
        }

        tmp = tmp->next;
    }
    if (poly_id_val1 == NULL || poly_id_val2 == NULL) {
        return *head;
    }
    if(poly_id_val3==NULL){
        *head = create_poly_id(*head, result_poly_id);
        tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        poly_id_val3 = tmp;
    } else {
        // Free the old polynomial before assigning the new one
        free(poly_id_val3->polynomial);
    }

    poly_node* poly1 = poly_id_val1->polynomial;
    poly_node* poly2 = poly_id_val2->polynomial;

    while (poly1 != NULL) {
        poly_id_val3->polynomial = insert_term(poly_id_val3->polynomial, poly1->poly.coefficient, poly1->poly.exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        poly_id_val3->polynomial = insert_term(poly_id_val3->polynomial, poly2->poly.coefficient, poly2->poly.exponent);
        poly2 = poly2->next;
    }

    return *head;
}

void destroy_poly_id(poly_id** head, int poly_id_val) {
    poly_id* curr = *head;
    poly_id* prev = NULL;

    while (curr != NULL) {
        if (curr->id == poly_id_val) {
            poly_node* current_node = curr->polynomial;
            while (current_node != NULL) {
                poly_node* next = current_node->next;
                free(current_node);
                current_node = next;
            }

            if (prev == NULL) {
                *head = curr->next;
                free(curr);
            } else {
                prev->next = curr->next;
                free(curr);
            }

            break;
        }

        prev = curr;
        curr = curr->next;
    }
}

int main() {
    poly_id* head = NULL;
    char string[MAX_LEN];
    int poly_id_val, coefficient, exponent;

    while (1) {
        scanf("%s", string);

        if (strcmp(string, "AddTerm") == 0) {
            scanf("%d%d%d", &poly_id_val, &coefficient, &exponent);
            head = create_poly_id(head, poly_id_val);
            add_term(head, poly_id_val, coefficient, exponent);
        } else if (strcmp(string, "EvaluatePoly") == 0) {
            int val;
            scanf("%d%d", &poly_id_val, &val);
            printf("%d\n", evaluate_poly(head, poly_id_val, val));
        } else if (strcmp(string, "AddPoly") == 0) {
            int poly_id_val_1, poly_id_val_2, result_poly_id;
            scanf("%d%d%d", &poly_id_val_1, &poly_id_val_2, &result_poly_id);
            head=add_poly(&head, poly_id_val_1, poly_id_val_2, result_poly_id);
        } else if (strcmp(string, "PrintPoly") == 0) {
            scanf("%d", &poly_id_val);
            print_poly(head, poly_id_val);
        } else if (strcmp(string, "Destroy") == 0) {
            scanf("%d", &poly_id_val);
            destroy_poly_id(&head, poly_id_val);
        } else if (strcmp(string, "*") == 0) {
            break;
        }
    }

    return 0;
}
