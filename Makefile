ifndef CMAKE
	CMAKE = cmake
endif

ifndef MAKE_JOBS
	MAKE_JOBS =
endif

ifeq ($(OS),Windows_NT)
	ifndef BUILD_DIRECTORY
		BUILD_DIRECTORY = "build/windows"
	endif
else
	ifndef BUILD_DIRECTORY
		BUILD_DIRECTORY = "build/linux"
	endif
endif

CMAKE_FLAGS =	-DCMAKE_BUILD_TYPE=Release
            	
define docker_pc_run
	docker run --rm -v "$(shell pwd):/buildTmp" -w "/buildTmp" dockerbuild $(1)
endef

all: pc_docker_build pc_docker_check
            	
dockerBuild:
	docker build --network=host -t dockerbuild "."
	
pc_docker_build: dockerBuild
	$(call docker_pc_run,make pc_build)
	
pc_docker_check: dockerBuild
	$(call docker_pc_run,make check)
	
cmake_project:
	$(CMAKE) -S . -B $(BUILD_DIRECTORY) $(CMAKE_FLAGS)
	
pc_build: cmake_project
	$(CMAKE) --build $(BUILD_DIRECTORY) -j $(MAKE_JOBS)
	
check: pc_build
	$(CMAKE) --build $(BUILD_DIRECTORY) -j $(MAKE_JOBS) --target test ARGS="--output-on-failure" 
	
clang-format: dockerBuild
	$(call docker_pc_run,scripts/clang-format.sh)

clean:
	rm -rf $(BUILD_DIRECTORY)