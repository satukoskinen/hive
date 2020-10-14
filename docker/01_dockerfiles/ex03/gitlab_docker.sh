#!/bin/bash

# Build the gitlab image defined by the Dockerfile and run it in detached mode with relevant ports published.
# After starting the run, follow the configuration by following the container's log (it takes a couple of minutes to set up).

docker build -t gitlab .
docker run -it -d -p 443:443 -p 2222:2222 -p 8080:80 --name gitlab-server --privileged gitlab
docker logs -f gitlab
