#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displaySeats(int *seats, int totalSeats);
void bookSeat(int *seats, int totalSeats);
void cancelSeat(int *seats, int totalSeats);
void menu();

int main() {
    int totalSeats = 10; // Total number of seats
    int seats[10] = {0}; // Array to store seat status (0 = free, 1 = booked)
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats, totalSeats);
                break;
            case 2:
                bookSeat(seats, totalSeats);
                break;
            case 3:
                cancelSeat(seats, totalSeats);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display seat status
void displaySeats(int *seats, int totalSeats) {
    printf("\nSeat Status:\n");
    for (int i = 0; i < totalSeats; i++) {
        printf("Seat %d: %s\n", i + 1, seats[i] == 0 ? "Available" : "Booked");
    }
    printf("\n");
}

// Function to book a seat
void bookSeat(int *seats, int totalSeats) {
    int seatNumber;
    printf("Enter seat number to book (1-%d): ", totalSeats);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > totalSeats) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (seats[seatNumber - 1] == 0) {
        seats[seatNumber - 1] = 1;
        printf("Seat %d booked successfully!\n", seatNumber);
    } else {
        printf("Seat %d is already booked.\n", seatNumber);
    }
}

// Function to cancel a seat booking
void cancelSeat(int *seats, int totalSeats) {
    int seatNumber;
    printf("Enter seat number to cancel (1-%d): ", totalSeats);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > totalSeats) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (seats[seatNumber - 1] == 1) {
        seats[seatNumber - 1] = 0;
        printf("Seat %d cancellation successful!\n", seatNumber);
    } else {
        printf("Seat %d is not booked yet.\n", seatNumber);
    }
}

// Function to display the menu
void menu() {
    printf("\n=== Seat Reservation System ===\n");
    printf("1. View Seats\n");
    printf("2. Book a Seat\n");
    printf("3. Cancel a Seat\n");
    printf("4. Exit\n");
    printf("================================\n");
}
