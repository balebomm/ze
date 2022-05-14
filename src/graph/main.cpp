#include <iostream>
#include <string>

#include "proto/graph.pb.h"
#include "google/protobuf/util/json_util.h"

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    proto::Location proto_location{};
    proto_location.set_type<std::string>("balebom");
    proto_location.set_lat(124);
    proto_location.set_lng(121);
    std::string jmsg;
    google::protobuf::util::MessageToJsonString(proto_location, &jmsg);

    std::cout << "Json string: " << jmsg << "\n";

    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}