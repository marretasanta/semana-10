#include <stdio.h>

#define MAX_SIZE 100

void append(int array[], int *size, int value) {
    if (*size < MAX_SIZE) {
        array[*size] = value;
        (*size)++;
    } else {
        printf("Erro: array está cheio, não é possível adicionar mais elementos.\n");
    }
}

void insert(int array[], int *size, int index, int value) {
    if (index >= 0 && index <= *size && *size < MAX_SIZE) {
        for (int i = *size; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = value;
        (*size)++;
    } else {
        printf("Erro: índice inválido ou array está cheio.\n");
    }
}

int pop(int array[], int *size, int index) {
    if (index >= 0 && index < *size) {
        int value = array[index];
        for (int i = index; i < *size - 1; i++) {
            array[i] = array[i + 1];
        }
        (*size)--;
        return value;
    } else {
        printf("Erro: índice inválido.\n");
        return -1;
    }
}

void remove_element(int array[], int *size, int value) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (array[i] == value) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                array[j] = array[j + 1];
            }
            (*size)--;
            i--; // Revisitar o mesmo índice após a remoção
        }
    }
    if (!found) {
        printf("Erro: valor não encontrado no array.\n");
    }
}

int count(int array[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            count++;
        }
    }
    return count;
}

int index(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1; // Valor não encontrado
}

void reverse(int array[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

void sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[MAX_SIZE] = {5, 3, 7};
    int size = 3;

    // Testando todas as funções
    append(array, &size, 2);
    append(array, &size, 8);

    printf("Count of 3: %d\n", count(array, size, 3));
    printf("Index of 7: %d\n", index(array, size, 7));

    insert(array, &size, 2, 4);

    printf("Lista com inserção: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int popped_value = pop(array, &size, 1);
    printf("Popped element: %d\n", popped_value);

    printf("Lista com pop: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    remove_element(array, &size, 2);

    printf("Lista com remoção: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Lista com reversão: ");
    reverse(array, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Lista com ordenação: ");
    sort(array, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}