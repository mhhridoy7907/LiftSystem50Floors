#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_REQ 20
#define MAX_FLOOR 50

int currentFloor = 0;
int goingUp = 1;
int requests[MAX_REQ];
int count = 0;

// add request
void addRequest(int floor) {
    if (floor >= 0 && floor <= MAX_FLOOR) {
        requests[count++] = floor;
    } else {
        printf("Invalid floor: %d\n", floor);
    }
}

// sort array (simple bubble sort)
void sortRequests() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
}

// find next index depending on direction
int findNextUp(int from) {
    for (int i = 0; i < count; i++) {
        if (requests[i] >= from) return i;
    }
    return -1;
}

int findNextDown(int from) {
    for (int i = count - 1; i >= 0; i--) {
        if (requests[i] <= from) return i;
    }
    return -1;
}

// move lift
void moveTo(int index) {
    int floor = requests[index];

    printf("Moving from %d to %d\n", currentFloor, floor);
    currentFloor = floor;

    printf("Stopped at floor %d\n", floor);

    // remove request
    for (int i = index; i < count - 1; i++) {
        requests[i] = requests[i + 1];
    }
    count--;
}

// run lift
void runLift() {
    sortRequests();

    while (count > 0) {
        int idx;

        if (goingUp) {
            idx = findNextUp(currentFloor);

            if (idx != -1) {
                moveTo(idx);
            } else {
                goingUp = 0;
            }
        } else {
            idx = findNextDown(currentFloor);

            if (idx != -1) {
                moveTo(idx);
            } else {
                goingUp = 1;
            }
        }
    }

    printf("All requests completed. Lift is idle at floor %d\n", currentFloor);
}

int main() {
    srand(time(NULL));

    // generate random requests
    for (int i = 0; i < MAX_REQ; i++) {
        int floor = rand() % 51;
        addRequest(floor);
    }

    printf("Lift requests loaded:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", requests[i]);
    }

    printf("\n\n");

    runLift();

    return 0;
}
