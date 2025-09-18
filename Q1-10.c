#include<stdio.h>
#include<ctype.h>

int main(){
    int size, num, crust, time, deliveryOpt;
    char cheese, studentID;
    double total = 0.0;
    double discountAmount = 0.0;

    //Q1:
    printf("Choose a pizza size:\n1. Small\n2. Medium\n3. Large\n");
    scanf("%d", &size);

    if (size == 1){
        printf("You chose Small size.\n");
    } else if (size == 2){
        printf("You chose Medium size.\n");
    } else if (size == 3){
        printf("You chose Large size.\n");
    } else{
        printf("Invalid size.\n");
    }

    //Q2 & Q3:
    printf("\nA small pizza costs $8.\nHow many pizzas do you want (1, 2, or 3)? ");
    scanf("%d", &num);

    if (num > 1){
        printf("Check our multi-pizza deals.\n"); 
    } else if (num == 1){
        printf("Your total is $8 (base price for 1 pizza).\n");
    } else{
        printf("Invalid number of pizzas.\n");
        return 0;
    }

    if (num == 1) total = 8.0;
    else if (num == 2) total = 15.0;
    else if (num == 3) total = 21.0;
    else{
        printf("Invalid number of pizzas for pricing (allowed 1-3).\n");
        return 0;
    }

    printf("Subtotal (base) = $%.2f\n", total);

    //Q4:
    printf("\nChoose crust type:\n1. Regular ($0)\n2. Thin ($1)\n3. Stuffed ($2)\n");
    scanf("%d", &crust);

    if (crust == 1){
        printf("Regular crust selected.\n");
        total += 0.0;
    } else if (crust == 2){
        printf("Thin crust selected.\n");
        total += 1.0;
    } else if (crust == 3){
        printf("Stuffed crust selected.\n");
        total += 2.0;
    } else{
        printf("Invalid crust type. Defaulting to Regular.\n");
        crust = 1;
    }

    printf("Total after crust = $%.2f\n", total);

    //Q5: 
    printf("\nDo you want extra cheese? (Y/N): ");
    scanf(" %c", &cheese);
    cheese = toupper(cheese);

    if (cheese == 'Y'){
        total += 1.50;
        printf("Extra cheese added: $1.50\n");
    } else{
        printf("No extra cheese.\n");
    }
    printf("Total after cheese = $%.2f\n", total);

    //Q6:
    printf("\nEnter current hour (0-23): ");
    scanf("%d", &time);

    if (time >= 11 && time <= 14){
        discountAmount = total * 0.10;
        total -= discountAmount;
        printf("10%% lunch discount applied: -$%.2f\n", discountAmount);
    } else{
        printf("No time-based discount.\n");
    }
    printf("Total after time discount = $%.2f\n", total);

    //Q7:
    printf("\nDo you have a student ID? (Y/N): ");
    scanf(" %c", &studentID);
    studentID = toupper(studentID);

    if (studentID == 'Y'){
        total -= 2.0;
        if (total < 0) total = 0.0;
        printf("Student discount applied: -$2.00\n");
    } else{
        printf("No student discount.\n");
    }
    printf("Total after student discount = $%.2f\n", total);

    //Q8:
    if (num == 3 && crust == 3){
        printf("\nYou get free garlic bread!\n");
    }

    //Q9:
    printf("\nDelivery option:\n1. Pickup\n2. Delivery ($3)\nChoose (1 or 2): ");
    scanf("%d", &deliveryOpt);

    if (deliveryOpt == 2){
        total += 3.0;
        printf("Delivery selected. +$3.00 added.\n");
    } else if (deliveryOpt == 1){
        printf("Pickup selected. No delivery fee.\n");
    } else{
        printf("Invalid option. Assuming Pickup.\n");
        deliveryOpt = 1;
    }

    //Q10
    printf("\n---------------- RECEIPT ----------------\n");

    printf("Size: ");
    if (size == 1) printf("Small\n");
    else if (size == 2) printf("Medium\n");
    else if (size == 3) printf("Large\n");
    else printf("Invalid\n");

    printf("Number of pizzas: %d\n", num);
    printf("Crust: ");
    if (crust == 1) printf("Regular\n");
    else if (crust == 2) printf("Thin\n");
    else if (crust == 3) printf("Stuffed\n");

    printf("Extra cheese: %c\n", cheese);
    printf("Student ID: %c\n", studentID);
    printf("Time (hour entered): %d\n", time);
    printf("Delivery option: %s\n", (deliveryOpt == 2) ? "Delivery" : "Pickup");

    if (discountAmount > 0.0)
        printf("Lunch discount: -$%.2f\n", discountAmount);

    printf("FINAL TOTAL: $%.2f\n", total);
    if (num == 3 && crust == 3)
        printf("** You get free garlic bread! **\n");

    return 0;
}

