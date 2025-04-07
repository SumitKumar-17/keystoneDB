FROM ubuntu:22.04

RUN apt-get update && \
    apt-get -y install libgflags-dev libzstd-dev libsnappy-dev zlib1g-dev libbz2-dev liblz4-dev && \
    apt-get -y install libprotobuf-dev protobuf-compiler \
    apt-get -y install gcc cmake git \ 
    apt-get install liburing

RUN mkdir -p build && \
    cd build && \
    cmake .. && \ make -j4

COPY ./build/keystoneDB /

ENTRYPOINT ["/bin/bash"]