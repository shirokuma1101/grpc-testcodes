set proto_name=ping-pong
set client_path=client\Src\Proto
set server_path=server\Src\Proto
set protoc_path=%CPP_LIB%\grpc\grpc-1.48.0\bin\Release
set protoc_plugin_path=%CPP_LIB%\grpc\grpc-1.48.0\bin\Release

pushd %~dp0

set path=%cd%\..
set output_client_path=%path%\%client_path%
set output_server_path=%path%\%server_path%

%protoc_path%\protoc.exe %proto_name%.proto --grpc_out=%output_server_path% --plugin=protoc-gen-grpc=%protoc_plugin_path%\grpc_cpp_plugin.exe --proto_path=.\
%protoc_path%\protoc.exe %proto_name%.proto --cpp_out=%output_server_path% --proto_path=.\

%protoc_path%\protoc.exe %proto_name%.proto --grpc_out=%output_client_path% --plugin=protoc-gen-grpc=%protoc_plugin_path%\grpc_cpp_plugin.exe --proto_path=.\
%protoc_path%\protoc.exe %proto_name%.proto --cpp_out=%output_client_path% --proto_path=.\

popd
