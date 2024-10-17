# Use Debian 12 (Bookworm) as the base image
FROM --platform=linux/amd64 debian:bookworm

RUN echo "Acquire::http::Pipeline-Depth 0;" > /etc/apt/apt.conf.d/99custom && \
    echo "Acquire::http::No-Cache true;" >> /etc/apt/apt.conf.d/99custom && \
    echo "Acquire::BrokenProxy    true;" >> /etc/apt/apt.conf.d/99custom
RUN rm -rf /var/lib/apt/lists/*
RUN apt-get clean
RUN apt-get update -o Acquire::CompressionTypes::Order::=gz
RUN apt-get upgrade -y

# Install dependencies for building and using GCC
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    gcc-12 \
    g++-12 \
    curl \
    vim \
    wget \
    gcc-multilib \
    flex \
    bison \
    zip 

# Set GCC 12 as the default compiler
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 100 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 100

# Verify GCC version
RUN gcc --version

# Set the working directory
WORKDIR /app

# Copy any C source files into the container
COPY . .
