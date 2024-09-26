# For building the project
make_dir_and_build:
	mkdir -p build
	cd build && cmake .. && make -j4

# For generating the proto files updates
generate_proto:
	cd common/codec/ && \
	protoc -I=. --cpp_out=. ./db.proto
	cd ../../

# Fetch git submodules
module_fetch:
	git submodule update

# Build the Docker image
docker_build:
	docker build -t skdb .

# List Docker images
image:
	docker images

# Run the Docker container interactively
container_run:
	docker run -it skdb
