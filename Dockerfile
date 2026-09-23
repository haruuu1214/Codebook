# Use an official TeX Live image as the base image
FROM texlive/texlive:latest

# Install necessary system packages
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    python3-venv \
    && rm -rf /var/lib/apt/lists/*

# Create and activate a virtual environment
RUN python3 -m venv /opt/venv

# Install any Python dependencies (if needed) inside the virtual environment
RUN /opt/venv/bin/pip install --no-cache-dir wheel

# Set the default shell to use the virtual environment's Python and pip
ENV PATH="/opt/venv/bin:$PATH"

# Set working directory
WORKDIR /usr/src/app

# Copy all local files into the container
COPY . .

# Set entrypoint to run the build script using virtual environment Python
ENTRYPOINT ["python3", "build.py"]