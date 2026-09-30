#include <stdio.h>

int loop;

void printValues(float values[], int size) {
    printf("Values: ");
    for (loop = 0; loop < size; loop++) {
        if (loop > 0) {
            printf(", ");
        }
        printf("%.3f", values[loop]);
    }
    printf("\n");
}

int findLastIndexOfValue(float values[], int size, float v) {
    
    int latestIndex = 0;
    int foundBoolean = 0;
    
    for (loop = 0; loop < size; loop++) {
        if (values[loop] == v) {
            latestIndex = loop;
            foundBoolean = 1;
        }
    }
    if (foundBoolean == 0) {
        printf("Value not found in array!\n");
        return -1;
    }
    printf("Value found at index %i in array.\n", latestIndex);
    return 1;
}

float maxElement(float values[], int size) {

    float largestValue = 0;

    for (loop = 0; loop < size; loop++) {
        if (largestValue < values[loop]) {
            largestValue = values[loop];
        }
    }
    return largestValue;
}

void replaceElement(float values[], int i, float v) {
    values[i] = v;
}

void sortOnValue(float values[], int size) {

    float tempValue;
    int sortedBoolean = 0;
    int loop = 0;
    int iterationsSinceLastAction = 0;
    int iterationTookPlace = 0;

    while (sortedBoolean == 0) {
        if (loop == 9 && sortedBoolean == 0) {
            loop = 0;
            continue;
        }
        else if (values[loop] > values[loop+1]) {
            tempValue = values[loop];
            values[loop] = values[loop+1];
            values[loop+1] = tempValue;
            loop++;
            iterationsSinceLastAction = 0;
            iterationTookPlace = 1;
        }
        else {
            iterationTookPlace = 0;
        }
        if (iterationTookPlace == 0) {
            loop++;
            iterationsSinceLastAction++;
            iterationTookPlace = 0;
        }
        if (iterationsSinceLastAction == 9) {
            sortedBoolean = 1;
        }
    }
}

int main() {
    int i;
    float v;
    char command[20];
    float values[10] = {1.5, 2.2, 7.3, 9.2, 7.4, 7.5, -8.0, 1.5, 12};

    while (1){
        printf("Command? ");
        scanf("%19s", command);

        switch(command[0]) {
            case 'q':
                return 0;
            case 'p':
                printValues(values, 10);
                break;
            case 'f':
                printf("Find value: ");
                scanf("%f", &v);
                findLastIndexOfValue(values, 10, v) == -1;
                break;
            case 'm':
                printf("Max: %.3f\n", maxElement(values, 10));
                break;
            case 'r':
                while (1) {
                    printf("Replace (index): ");
                    scanf("%i", &i);
                    if (i > 9 || i < 0) {
                        printf("Error: index exceeds bound of array.\n");
                    }
                    else {
                        break;
                    }
                }
                printf("Replace (value): ");
                scanf("%f", &v);
                replaceElement(values, i, v);
                break;
            case 's':
                sortOnValue(values, 10);
        }
    }
}
