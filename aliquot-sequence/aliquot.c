#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned long long sum_of_divisors(unsigned long long n) { //unsigned long long so that it can handle larger sequences 

unsigned long long sum=1;
if (n==1) return 0;
    for (unsigned long long i=2; i*i<=n ; i++) {

        if (n % i == 0) {
        sum += i;
            if (i !=n/i) sum +=n/i;
        }
    }   return sum;
}


int main (void) {

unsigned long long n;
int length;
char mode;
unsigned long long current;
int stage = 0; //Σε τι φάση/βημα της διαδικασίας βρισκεται το πρόγραμμα
unsigned long long next; 

printf("\nGive a number to begin the aliquot sequence\n");
if (scanf("%llu",&n) !=1) {
    printf("Invalid input\n");
    return 1;
}
    if (n ==0) {
         printf("\nPlease type a positive number within the range\n");
         return 1; 
    }


   

printf("\nPlease the max aliquot length to look for (0 for unlimited): ");

if (scanf("%d",&length) !=1 || length <0) {
    printf("\nInvalid length\n");
    return 1;
}


if (n == 6) {            //(Ειδική Περίπτωση) Για τον αριθμό 6 η ακολουθία επαναλαμβάνεται 7 φορες
    length = 7; 
}

    if (length < 0) {
         printf("\nERROR :/\n");
         return 1; 
    }



printf("\nDo you want to print the full sequence (f) or just the length (l)?\n");
scanf(" %c", &mode);  // Έβαλα το κενό γιατί αλλιώς το πρόγραμμα διάβαζε το enter αντί για το γράμμα

 if (mode >= 'A' && mode <= 'Z') { //Ετσι ωστε να γινονται ολα τα γραμματα πεζά (πηρα την ιδεα απο ενα μαθημα στο εργαστήριο)
        mode = mode + ('a' - 'A');
 }
        if (mode != 'f' && mode != 'l') { //Σε περίπτωση που ο χρήστης προσπαθησει να χρησιμοποιήση διαφορετικά γραμματα απο αυτα που επιτρεπονται
        printf("Invalid mode. Use 'f' or 'l'.\n");
        return 1;
        }
 current = n; //ετσι ωστε να υπάρχει μεγαλύτερη ευελιξία με την αλλαγή τιμών


 /*while(1) για να συνεχίσει να επαναλαμβάνει το block μεχρι να συμβει κατι*/
    while (1) {
        if (mode == 'f') {

            printf("%llu\n", current);
        }
    
            if (current > 1000000000000000ULL) //το ULL στο τέλος ειναι για να αποφύγουμε τυχόν warnings
             {
            printf("\nSystem cannot withstand such number... Shutting down.\n");
            return 1;
            }
    
 next = sum_of_divisors(current);
    stage++;

//αν φτάσει το 0 θα τελειώσει
if (next == 0) {
    if (mode == 'f') {
        printf("%llu\n",next); //θα τυπώσει και το 0
    }
break;
}


if (length > 0 && stage>=length) 
    break;

current = next;
}
if (mode == 'l') {

printf("\nThe length of the sequence is: %d\n" , stage);

}
    
 
return 0;
}
