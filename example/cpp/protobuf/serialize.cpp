#include <iostream>
#include <string>

#include "proto/employee.pb.h"
#include "google/protobuf/util/json_util.h"

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    proto::Person proto_person;
    proto_person.set_name("balebom olala"); 
    proto_person.set_id(5);
    proto_person.set_email("balebom@gmail.com");

    std::string jmsg;
    google::protobuf::util::MessageToJsonString(proto_person, &jmsg);

    std::cout << "Json string: " << jmsg << "\n";

    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
