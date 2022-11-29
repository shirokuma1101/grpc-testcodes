set proto_name=
set protocpp_path=common\protocpp
set protoc_path=%CPP_LIB%\grpc\grpc-1.48.0\bin\Release
set protoc_plugin_path=%CPP_LIB%\grpc\grpc-1.48.0\bin\Release

pushd %~dp0

set path=%cd%\..
set output_protocpp_path=%path%\%protocpp_path%

%protoc_path%\protoc.exe %proto_name%.proto --grpc_out=%output_protocpp_path% --plugin=protoc-gen-grpc=%protoc_plugin_path%\grpc_cpp_plugin.exe --proto_path=.\
%protoc_path%\protoc.exe %proto_name%.proto --cpp_out=%output_protocpp_path% --proto_path=.\

popd
