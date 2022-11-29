#pragma once

#include <iostream>
#include <mutex>
#include <string>
#include <string_view>
#include <thread>

#include "boost/thread.hpp"
#include "boost/program_options.hpp"

#include "grpcpp/grpcpp.h"
#include "protocpp/asset-hotreload.grpc.pb.h"

#ifdef _DEBUG
#pragma comment(lib, "libprotobuf-lited.lib")
#pragma comment(lib, "libprotobufd.lib")
#pragma comment(lib, "libprotocd.lib")
#pragma comment(lib, "zlibd.lib")
#pragma comment(lib, "zlibstaticd.lib")
#else
#pragma comment(lib, "libprotobuf-lite.lib")
#pragma comment(lib, "libprotobuf.lib")
#pragma comment(lib, "libprotoc.lib")
#pragma comment(lib, "zlib.lib")
#pragma comment(lib, "zlibstatic.lib")
#endif

namespace common {
    inline auto GetCmdLine() {
        boost::program_options::options_description desc("options");
        desc.add_options()
            ("host,h", boost::program_options::value<std::string>()->default_value("localhost"), "host")
            ("port,p", boost::program_options::value<std::string>()->default_value("8080"), "port")
            ;
        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(__argc, __argv, desc), vm);
        boost::program_options::notify(vm);

        return vm;
    }
}
