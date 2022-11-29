#pragma once

#include <iostream>
#include <string>

#include "grpcpp/grpcpp.h"
#include "protocpp/ping-pong.grpc.pb.h"

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

#include "ExternalDependencies/Utility/DateTime.h"
