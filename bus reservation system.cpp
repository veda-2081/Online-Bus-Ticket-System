#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Bus { 
	int busNumber; 
	char source[50]; 
	char destination[50]; 
	int totalSeats; 
	int availableSeats; 
	float fare; 
}; 

struct Passenger { 
	char name[50]; 
	int age; 
	int seatNumber; 
	int busNumber; 
}; 

struct User { 
	char username[50]; 
	char password[50]; 
}; 

void displayMainMenu() 
{ 
	printf("\n=== Bus Reservation System ===\n"); 
	printf("1. Login\n"); 
	printf("2. Exit\n"); 
	printf("Enter your choice: "); 
} 

void displayUserMenu() 
{ 
	printf("\n=== User Menu ===\n"); 
	printf("1. Book a Ticket\n"); 
	printf("2. Cancel a Ticket\n"); 
	printf("3. Check Bus Status\n"); 
	printf("4. Logout\n"); 
	printf("Enter your choice: "); 
} 

int loginUser(struct User users[], int numUsers, 
			char username[], char password[]) 
{ 
	for (int i = 0; i < numUsers; i++) { 
		if (strcmp(users[i].username, username) == 0 
			&& strcmp(users[i].password, password) == 0) { 
			return i; 
		} 
	} 
	return -1; 
} 

void bookTicket(struct Bus buses[], int numBuses, 
				struct Passenger passengers[], 
				int* numPassengers, int userId) 
{ 
	printf("\nEnter Bus Number: "); 
	int busNumber; 
	scanf("%d", &busNumber); 

	int busIndex = -1; 
	for (int i = 0; i < numBuses; i++) { 
		if (buses[i].busNumber == busNumber) { 
			busIndex = i; 
			break; 
		} 
	} 

	if (busIndex == -1) { 
		printf("Bus with Bus Number %d not found.\n", 
			busNumber); 
	} 
	else if (buses[busIndex].availableSeats == 0) { 
		printf("Sorry, the bus is fully booked.\n"); 
	} 
	else { 
		printf("Enter Passenger Name: "); 
		scanf("%s", passengers[*numPassengers].name); 

		printf("Enter Passenger Age: "); 
		scanf("%d", &passengers[*numPassengers].age); 

		passengers[*numPassengers].seatNumber 
			= buses[busIndex].totalSeats 
			- buses[busIndex].availableSeats + 1; 

		passengers[*numPassengers].busNumber = busNumber; 

		buses[busIndex].availableSeats--; 

		printf("Ticket booked successfully!\n"); 
		(*numPassengers)++; 
	} 
} 

void cancelTicket(struct Bus buses[], int numBuses, 
				struct Passenger passengers[], 
				int* numPassengers, int userId) 
{ 
	printf("\nEnter Passenger Name: "); 
	char name[50]; 
	scanf("%s", name); 

	int found = 0; 
	for (int i = 0; i < *numPassengers; i++) { 
		if (strcmp(passengers[i].name, name) == 0 
			&& passengers[i].busNumber 
				== buses[userId].busNumber) { 
		
			int busIndex = -1; 
			for (int j = 0; j < numBuses; j++) { 
				if (buses[j].busNumber 
					== passengers[i].busNumber) { 
					busIndex = j; 
					break; 
				} 
			} 
			buses[busIndex].availableSeats++; 

	
			for (int j = i; j < (*numPassengers) - 1; j++) { 
				passengers[j] = passengers[j + 1]; 
			} 
			(*numPassengers)--; 
			found = 1; 
			printf("Ticket canceled successfully!\n"); 
			break; 
		} 
	} 
	if (!found) { 
		printf("Passenger with name %s not found on this "
			"bus.\n", 
			name); 
	} 
} 


void checkBusStatus(struct Bus buses[], int numBuses, 
					int userId) 
{ 
	printf("\nBus Number: %d\n", buses[userId].busNumber); 
	printf("Source: %s\n", buses[userId].source); 
	printf("Destination: %s\n", buses[userId].destination); 
	printf("Total Seats: %d\n", buses[userId].totalSeats); 
	printf("Available Seats: %d\n", 
		buses[userId].availableSeats); 
	printf("Fare: %.2f\n", buses[userId].fare); 
} 

int main() 
{ 
	 
	struct User users[5] = { 
		{ "user1", "password1" }, { "user2", "password2" }, 
		{ "user3", "password3" }, { "user4", "password4" }, 
		{ "user5", "password5" }, 
	}; 
	int numUsers = 5; 

	
	struct Bus buses[3] = { 
		{ 101, "City A", "City B", 50, 50, 25.0 }, 
		{ 102, "City C", "City D", 40, 40, 20.0 }, 
		{ 103, "City E", "City F", 30, 30, 15.0 }, 
	}; 
	int numBuses = 3; 

	struct Passenger 
		passengers[500]; 
	int numPassengers = 0; 

	int loggedInUserId = -1; 

	while (1) { 
		if (loggedInUserId == -1) { 
			displayMainMenu(); 
			int choice; 
			scanf("%d", &choice); 

			if (choice == 1) { 
				char username[50]; 
				char password[50]; 

				printf("Enter Username: "); 
				scanf("%s", username); 
				printf("Enter Password: "); 
				scanf("%s", password); 

				loggedInUserId = loginUser( 
					users, numUsers, username, password); 
				if (loggedInUserId == -1) { 
					printf("Login failed. Please check "
						"your username and password.\n"); 
				} 
				else { 
					printf( 
						"Login successful. Welcome, %s!\n", 
						username); 
				} 
			} 
			else if (choice == 2) { 
				printf("Exiting the program.\n"); 
				break; 
			} 
			else { 
				printf( 
					"Invalid choice. Please try again.\n"); 
			} 
		} 
		else { 
			displayUserMenu(); 
			int userChoice; 
			scanf("%d", &userChoice); 

			switch (userChoice) { 
			case 1: 
				bookTicket(buses, numBuses, passengers, 
						&numPassengers, loggedInUserId); 
				break; 
			case 2: 
				cancelTicket(buses, numBuses, passengers, 
							&numPassengers, 
							loggedInUserId); 
				break; 
			case 3: 
				checkBusStatus(buses, numBuses, 
							loggedInUserId); 
				break; 
			case 4: 
				printf("Logging out.\n"); 
				loggedInUserId = -1; 
				break; 
			default: 
				printf( 
					"Invalid choice. Please try again.\n"); 
			} 
		} 
	} 

	return 0; 
}

