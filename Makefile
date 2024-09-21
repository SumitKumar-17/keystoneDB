all: generate_proto make_dir_and_build

make_dir_and_build:
	mkdir -p build
	cd build && cmake .. && make

generate_proto:
	cd common/codec/
	protoc -I=. --cpp_out=. ./db.proto
	cd ../../