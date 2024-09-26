all: generate_proto make_dir_and_build

# For building the project
make_dir_and_build:
	mkdir -p build
	cd build && cmake .. && make

# For generating the proto files updates
generate_proto:
	cd common/codec/
	protoc -I=. --cpp_out=. ./db.proto
	cd ../../

module_fetch:
	git submodule update

docker_build:
    docker build -t skdb .

image:
    docker images

container_run:
    docker run -it skdb
