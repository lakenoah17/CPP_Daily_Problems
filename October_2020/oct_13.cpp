#include <iostream>
//This problem was asked by Snapchat.
//
//Given an array of time intervals (start,
// end) for classroom lectures (possibly
// overlapping), find the minimum number
// of rooms required.
//
//For example, given
// [(30, 75),
// (0, 50),
// (60, 150)],
// you should return 2.

struct TimePeriod{
    int startTime;
    int endTime;
};

struct Node{
    TimePeriod *timeBlock;
    Node *next;
};

struct LinkedList{
    int length;
    Node *head;
};

int findNumOfRoomsNeeded(TimePeriod *times[], int length);
bool insertTimeSpace(LinkedList *room, TimePeriod *timeBlock);


int main(){
    auto *timePeriod1 = new TimePeriod;
    timePeriod1->startTime = 30;
    timePeriod1->endTime = 75;

    auto *timePeriod2 = new TimePeriod;
    timePeriod2->startTime = 0;
    timePeriod2->endTime = 50;

    auto *timePeriod3 = new TimePeriod;
    timePeriod3->startTime = 60;
    timePeriod3->endTime = 150;

    auto *timePeriod4 = new TimePeriod;
    timePeriod4->startTime = 20;
    timePeriod4->endTime = 150;

    TimePeriod *times[4];
    times[0] = timePeriod1;
    times[1] = timePeriod2;
    times[2] = timePeriod3;
    times[3] = timePeriod4;

    std::cout<<findNumOfRoomsNeeded(times, 4);

}
int findNumOfRoomsNeeded(TimePeriod *times[], int length){
    int numOfRooms = 1;

    LinkedList *rooms[length];

    auto *room1 = new LinkedList;
    rooms[0] = room1;
    room1->length = 0;

    for (int i = 0; i < length; i++) {
        bool wasInserted = false;

        for (int j = 0; j < numOfRooms; j++) {
            if (insertTimeSpace(rooms[j], times[i])){
                wasInserted = true;
                break;
            }
        }

        if (!wasInserted){
            rooms[numOfRooms] = new LinkedList;
            rooms[numOfRooms]->length = 0;
            insertTimeSpace(rooms[numOfRooms], times[i]);
            numOfRooms++;
        }
    }

    return numOfRooms;
}

bool insertTimeSpace(LinkedList *room, TimePeriod *timeBlock){
    if (room->length == 0){
        Node *timeNode = new Node;
        timeNode->timeBlock = timeBlock;
        timeNode->next = nullptr;
        room->head = timeNode;
        room->length = room->length + 1;
        return true;
    }

    if (timeBlock->endTime <= room->head->timeBlock->startTime){
        Node *timeNode = new Node;
        timeNode->timeBlock = timeBlock;
        timeNode->next = room->head;
        room->head = timeNode;
        room->length = room->length + 1;
        return true;
    }

    Node *currNode = room->head;
    for (int i = 0; i < room->length; i++) {
        if (currNode->next == nullptr && currNode->timeBlock->endTime <= timeBlock->startTime){
            Node *timeNode = new Node;
            timeNode->timeBlock = timeBlock;
            timeNode->next = currNode->next;
            currNode->next = timeNode;
            room->length = room->length + 1;
            return true;
        }
        if (currNode->next == nullptr){
            return false;
        }


        if (currNode->timeBlock->endTime <= timeBlock->startTime && currNode->next->timeBlock->startTime >= timeBlock->endTime){
            Node *timeNode = new Node;
            timeNode->timeBlock = timeBlock;
            timeNode->next = currNode->next;
            currNode->next = timeNode;
            room->length = room->length + 1;
            return true;
        }
    }

    return false;
}



