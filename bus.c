#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SEATS 60

struct Bus {
    char busNumber[10];
    char route[50];
    char departureTime[10];
    int totalSeats;
    int availableSeats;
};

struct Passenger {
    char name[50];
    int age;
    char contactNumber[15];
    int seatNumber;
};

struct Bus buses[3] = {
    {"122", "Udupi --> Bangalore", "10:00PM", 60, 60},
    {"123", "Udupi --> Mumbai", "11:00PM", 60, 60},
    {"122", "Mumbai --> Bangalore", "9:00AM", 75, 75}
};

struct Passenger passengers[MAX_SEATS];
int pcount = 0;
int s = -1;

void search();
void detail();
void allocateSeats();
void cancelBooking();
void displayAllocatedSeats();

void main() {
    search();
}

void search() {
    int busChoice;
    char continueChoice[2];

    printf("Press 0 to Start Searching Your Journey \n");
    scanf("%d", &busChoice);

    if (busChoice == 0) {
        printf("\tBUS LIST\n");
        printf("SRNo\tBusNo  Bus Route   \t Timing\tSeats Available\n");
        for (int i = 0; i < 3; i++) {
            printf("%d\t%s\t%s\t%s\t%d\n", i + 1, buses[i].busNumber, buses[i].route, buses[i].departureTime, buses[i].availableSeats);
        }

        printf("\nEnter the Bus SRNo You want to travel: ");
        scanf("%d", &s);

        s--;
        printf("\nSelected Bus: \n");
        printf("%s\t%s\t%s\n", buses[s].busNumber, buses[s].route, buses[s].departureTime);

        printf("Press Y/N to move further: ");
        scanf("%s", continueChoice);

        if (strcmp(continueChoice, "y") == 0 || strcmp(continueChoice, "Y") == 0) {
            detail();
        } else {
            printf("Exiting the program.\n");
            exit(0);
        }
    }
}

void detail() {
    if (buses[s].availableSeats == 0) {
        printf("Sorry, no seats are available on this bus.\n");
        return;
    }

    printf("Enter passenger details\n");
    printf("Name: ");
    scanf(" %[^\n]", passengers[pcount].name);
    printf("Age: ");
    scanf("%d", &passengers[pcount].age);
    printf("Contact Number: ");
    scanf("%s", passengers[pcount].contactNumber);

    allocateSeats();
}

void allocateSeats() {
    if (buses[s].availableSeats == 0) {
        printf("No seats available.\n");
        return;
    }

    passengers[pcount].seatNumber = buses[s].totalSeats - buses[s].availableSeats + 1;
    buses[s].availableSeats--;
    pcount++;

    printf("Seat successfully allocated: %d\n", passengers[pcount - 1].seatNumber);
    printf("Passenger details:\n");
    printf("Name: %s\n", passengers[pcount - 1].name);
    printf("Age: %d\n", passengers[pcount - 1].age);
    printf("Contact: %s\n", passengers[pcount - 1].contactNumber);

    int choice;
    printf("Press 1 to Cancel Booking or 2 to View Allocated Seats: ");
    scanf("%d", &choice);

    if (choice == 1) {
        cancelBooking();
    } else if (choice == 2) {
        displayAllocatedSeats();
    }
}

void cancelBooking() {
    int seatToCancel;
    printf("Enter the seat number to cancel: ");
    scanf("%d", &seatToCancel);

    int found = 0;
    for (int i = 0; i < pcount; i++) {
        if (passengers[i].seatNumber == seatToCancel) {
            found = 1;
            for (int j = i; j < pcount - 1; j++) {
                passengers[j] = passengers[j + 1];
            }
            pcount--;
            buses[s].availableSeats++;
            printf("Booking for seat %d has been cancelled.\n", seatToCancel);
            break;
        }
    }

    if (found == 0) {
        printf("Seat number %d not found.\n", seatToCancel);
    }

    displayAllocatedSeats();
}

void displayAllocatedSeats() {
    printf("\nAllocated Seats:\n");
    for (int i = 0; i < pcount; i++) {
        printf("Seat %d: %s, Age: %d, Contact: %s\n", passengers[i].seatNumber, passengers[i].name, passengers[i].age, passengers[i].contactNumber);
    }
}
