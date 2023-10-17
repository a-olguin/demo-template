# Use an official GCC runtime as a parent image
FROM gcc:13.2

# Set the working directory in the container
WORKDIR /usr/src/

# Copy the current directory contents into the container at /usr/src/
COPY . /usr/src/

ENV DEBIAN_FRONTEND=non-interactive

# Install essential tools and libraries for building CMake and CppUTest
RUN apt-get update && \
    apt-get install -y wget make libssl-dev openssl zlib1g-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Build CMake from source
RUN mkdir /opt/cmake && \
    cd /opt/cmake && \
    wget https://github.com/Kitware/CMake/releases/download/v3.22.0/cmake-3.22.0.tar.gz && \
    tar -zxvf cmake-3.22.0.tar.gz && \
    cd cmake-3.22.0 && \
    ./bootstrap && \
    make && \
    make install && \
    cd .. && \
    rm -rf cmake-3.22.0 cmake-3.22.0.tar.gz

# sudo sh -c 'echo PATH="/pt/cmake/bin:\$PATH"' > /etc/profile.d/cmake.sh
# Install CppUTest
RUN cd /opt && \
    git clone https://github.com/cpputest/cpputest.git && \
    cd cpputest && \
    git checkout v4.0 && \
    cd build && \
    cmake .. && \
    make && \
    make install

# put gdb into the thing because apparently it wasnt there?^M
RUN apt-get update && apt-get install -y gdb^M

# Move entry point script into container
COPY ./entrypoint.sh /entrypoint.sh

# Define command to run your application
ENTRYPOINT ["bash", "-i", "/entrypoint.sh"]
