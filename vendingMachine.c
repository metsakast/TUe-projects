#include <stdio.h>

int main() {
    
    char answer[10];
    int integer;
    int total = 0;
    
    puts("My first vending machine.");
    
    while(1) {
    printf("Coffee or Tea? (c/t/q) ");
    scanf(" %c", answer);
    
    if (answer[0] == 'q') {
        printf("You entered: '%c'\n", answer[0]);
        puts("Bye!");
        break;
        
    } else if (answer[0] == 'c') {
        printf("You entered: '%c'\n", answer[0]);
        puts("Coffee it is.");
        printf("With sugar? (y/n) ");
        scanf(" %c", answer);
        printf("You entered: '%c'\n", answer[0]);
        
        if (answer[0] == 'y') {
            
            printf("Pay 2 euro with cash.\n");
            
            while (total < 2) {
                printf("Coin inserted? (1/2) ");
                scanf(" %d", &integer);
                printf("You entered: '%d'\n", integer);
                if (integer == 1) {
                    total += integer;
                    if (total < 2) {
                        printf("One more please.\n");
                    }
                } else if (integer == 2) {
                    total += integer;
                }
            }
            puts("Dispense coffee with sugar.");
            total = 0;
            
        } else if (answer[0] == 'n') {
            while(1) {
                printf("Pay with card ");
                printf("Payment successful? (y/n) ");
                scanf(" %c", answer);
                
                if (answer[0] == 'n') {
                    printf("You entered: '%c'\n", answer[0]);
                    continue;
                    
                } else if (answer[0] == 'y') {
                    printf("You entered: '%c'\n", answer[0]);
                    printf("Dispense coffee without sugar.\n");
                    break;
                }
            }
         }
        
    } else if (answer[0] == 't') {
        printf("You entered: '%c'\n", answer[0]);
        puts("Dispense tea.");
    }
    }
}
