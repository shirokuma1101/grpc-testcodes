#pragma once

#include <iostream>
#include <string>
#include <tuple>
#include <thread>
#include <mutex>
#include <Windows.h>

#include <boost/thread.hpp>
#include <boost/program_options.hpp>

#include <grpcpp/grpcpp.h>

#include <strconv.h>

using UID = UINT64;

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
