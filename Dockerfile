FROM ubuntu

RUN DEBIAN_FRONTEND=noninteractive TZ=Europe/Warsaw apt-get update && apt-get install -y build-essential cmake \ 
	python3 python3-pip git curl valgrind lcov clang-format \
	libboost-filesystem-dev libboost-thread-dev libboost-coroutine-dev
RUN git config --global --add safe.directory '*'