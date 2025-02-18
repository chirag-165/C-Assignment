#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUSES 3
#define DEST_LAT 12.9716  
#define DEST_LON 77.5946  
#define BUS_SPEED 60      

struct Bus {
    int busNumber;
    char route[100];
    float latitude;
    float longitude;
    char timestamp[20];
    float arrivalTime;
};

struct Bus buses[MAX_BUSES] = {
    {101, "Udupi to Bangalore", 13.3410, 74.8030, "2025-02-18 10:00", 0.0},
    {102, "Mumbai to Pune", 19.0760, 72.8777, "2025-02-18 08:30", 0.0},
    {103, "Delhi to Jaipur", 28.6139, 77.2090, "2025-02-18 09:15", 0.0}
};
int busCount = MAX_BUSES;

void updateBusLocation();
void displayBusStatus();
float getDistance(float lat1, float lon1, float lat2, float lon2);
float calculateArrivalTime(float distance, float speed);

int main() {
    int choice;

    while (1) {
        printf("\nBus Tracking and Location System\n");
        printf("1. Update Bus Location\n");
        printf("2. Display Bus Status\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateBusLocation();
                break;
            case 2:
                displayBusStatus();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void updateBusLocation() {
    int busNumber;
    printf("\nEnter Bus Number to update location: ");
    scanf("%d", &busNumber);

    int found = 0;
    for (int i = 0; i < busCount; i++) {
        if (buses[i].busNumber == busNumber) {
            found = 1;
            printf("\nEnter new Latitude: ");
            scanf("%f", &buses[i].latitude);
            printf("Enter new Longitude: ");
            scanf("%f", &buses[i].longitude);
            printf("Enter Timestamp (YYYY-MM-DD HH:MM): ");
            scanf("%s", buses[i].timestamp);

            float distance = getDistance(buses[i].latitude, buses[i].longitude, DEST_LAT, DEST_LON);
            buses[i].arrivalTime = calculateArrivalTime(distance, BUS_SPEED);

            printf("\nBus location updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Bus with number %d not found.\n", busNumber);
    }
}

void displayBusStatus() {
    printf("\nBus Status:\n");
    for (int i = 0; i < busCount; i++) {
        printf("\nBus Number: %d\n", buses[i].busNumber);
        printf("Route: %s\n", buses[i].route);
        printf("Current Location: Latitude %.2f, Longitude %.2f\n", buses[i].latitude, buses[i].longitude);
        printf("Timestamp: %s\n", buses[i].timestamp);
        printf("Estimated Arrival Time: %.2f minutes\n", buses[i].arrivalTime);
    }
}

float getDistance(float lat1, float lon1, float lat2, float lon2) {
    const float R = 6371.0;  
    float lat1Rad = lat1 * M_PI / 180.0;
    float lon1Rad = lon1 * M_PI / 180.0;
    float lat2Rad = lat2 * M_PI / 180.0;
    float lon2Rad = lon2 * M_PI / 180.0;

    float dLat = lat2Rad - lat1Rad;
    float dLon = lon2Rad - lon1Rad;

    float a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1Rad) * cos(lat2Rad) * sin(dLon / 2) * sin(dLon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;
}

float calculateArrivalTime(float distance, float speed) {
    return (distance / speed) * 60.0;  
}
