#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 100

struct Passenger {
    char name[50];
    int age;
    char contactNumber[15];
    char travelDate[12];
    char busType[20];
    float ticketPrice;
    char paymentMethod[20];
    char transactionID[20];
    int ticketNumber;
};

struct Passenger passengers[MAX_TICKETS];

void bookTicket();
void processPayment(int ticketIndex);
void cancelTicket();
void displayReceipt(int ticketIndex);
void calculateTicketPrice(int ticketIndex);
void displayBookingDetails(int ticketIndex);

int main() {
    int choice;

    while (1) {
        printf("\nTicket Booking and Payment System\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void bookTicket() {
    struct Passenger p;
    printf("\nEnter Passenger Details\n");
    printf("Name: ");
    scanf(" %[^\n]", p.name);
    printf("Age: ");
    scanf("%d", &p.age);
    printf("Contact Number: ");
    scanf("%s", p.contactNumber);
    printf("Travel Date (YYYY-MM-DD): ");
    scanf("%s", p.travelDate);
    printf("Bus Type (Luxury/Regular): ");
    scanf("%s", p.busType);

    p.ticketNumber = rand() % 1000 + 1; // Random ticket number for simplicity
    calculateTicketPrice(rand() % 1000);

    printf("\nTicket booking successful. Your ticket number is %d.\n", p.ticketNumber);
    displayBookingDetails(rand() % 1000);

    passengers[p.ticketNumber - 1] = p;

    processPayment(p.ticketNumber - 1);
}

void calculateTicketPrice(int ticketIndex) {
    float basePrice = 1000.0;  
    if (strcmp(passengers[ticketIndex].busType, "Luxury") == 0) {
        basePrice += 500;
    }

    if (strstr(passengers[ticketIndex].travelDate, "Sat") || strstr(passengers[ticketIndex].travelDate, "Sun")) {
        basePrice += 200;
    }

    passengers[ticketIndex].ticketPrice = basePrice;
}

void processPayment(int ticketIndex) {
    char paymentMethod[20];
    char transactionID[20];
    float amount;

    printf("\nEnter Payment Details\n");
    printf("Payment Method (Credit/Debit/UPI): ");
    scanf("%s", paymentMethod);
    printf("Transaction ID: ");
    scanf("%s", transactionID);
    printf("Amount: ");
    scanf("%f", &amount);

    strcpy(passengers[ticketIndex].paymentMethod, paymentMethod);
    strcpy(passengers[ticketIndex].transactionID, transactionID);

    printf("\nPayment Successful. Thank you for booking!\n");
    displayReceipt(ticketIndex);
}

void displayBookingDetails(int ticketIndex) {
    printf("\nBooking Details\n");
    printf("Name: %s\n", passengers[ticketIndex].name);
    printf("Age: %d\n", passengers[ticketIndex].age);
    printf("Contact: %s\n", passengers[ticketIndex].contactNumber);
    printf("Travel Date: %s\n", passengers[ticketIndex].travelDate);
    printf("Bus Type: %s\n", passengers[ticketIndex].busType);
    printf("Ticket Price: %.2f\n", passengers[ticketIndex].ticketPrice);
}

void displayReceipt(int ticketIndex) {
    printf("\nReceipt\n");
    printf("Ticket Number: %d\n", passengers[ticketIndex].ticketNumber);
    printf("Amount Paid: %.2f\n", passengers[ticketIndex].ticketPrice);
    printf("Payment Method: %s\n", passengers[ticketIndex].paymentMethod);
    printf("Transaction ID: %s\n", passengers[ticketIndex].transactionID);
}

void cancelTicket() {
    int ticketNumber;
    printf("\nEnter the ticket number to cancel: ");
    scanf("%d", &ticketNumber);

    if (ticketNumber < 1 || ticketNumber > 1000) {
        printf("Invalid ticket number.\n");
        return;
    }

    printf("Canceling ticket for %s...\n", passengers[ticketNumber - 1].name);
    printf("Refunding amount: %.2f\n", passengers[ticketNumber - 1].ticketPrice);

    passengers[ticketNumber - 1].ticketNumber = 0; // Mark the ticket as canceled
    printf("Ticket canceled successfully.\n");
}
