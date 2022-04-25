#include <iostream>
#include <string>

#include "proto/employee.pb.h"
#include "google/protobuf/util/json_util.h"

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    std::string jmsg = R"({"name":"balebom olala","id":5,"email":"balebom@gmail.com"})";
    proto::Person pt_person;

    google::protobuf::util::JsonStringToMessage(jmsg, &pt_person);

    std::string db_person = pt_person.DebugString();

    std::cout << "Debug string person:\n" << db_person << "\n";

    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
