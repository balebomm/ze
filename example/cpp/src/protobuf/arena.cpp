#include <iostream>
#include <string>

#include "google/protobuf/arena.h"

#include "proto/employee.pb.h"

int main()
{
    google::protobuf::Arena* arena = new google::protobuf::Arena();
    proto::Person* pt_person_1 = google::protobuf::Arena::CreateMessage<proto::Person>(arena);
    pt_person_1->mutable_address()->set_province("Univer");

    proto::Person* pt_person_2 = google::protobuf::Arena::CreateMessage<proto::Person>(arena);

    // before set unsafe
    std::string db_person_1 = pt_person_1->DebugString();
    std::string db_person_2 = pt_person_2->DebugString();

    std::cout << "before: debug person 1:\n" << db_person_1 << "\ndebug person 2:\n" << db_person_2 << "\n";

    pt_person_2->unsafe_arena_set_allocated_address(pt_person_1->unsafe_arena_release_address());

    // after set unsafe
    db_person_1 = pt_person_1->DebugString();
    db_person_2 = pt_person_2->DebugString();

    std::cout << "after: debug person 1:\n" << db_person_1 << "\ndebug person 2:\n" << db_person_2 << "\n";

    // swap
    pt_person_2->UnsafeArenaSwap(pt_person_1);

    db_person_1 = pt_person_1->DebugString();
    db_person_2 = pt_person_2->DebugString();

    std::cout << "swap: debug person 1:\n" << db_person_1 << "\ndebug person 2:\n" << db_person_2 << "\n";

    delete arena;
    return 0;
}
