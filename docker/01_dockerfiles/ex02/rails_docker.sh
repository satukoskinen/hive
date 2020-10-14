#!/bin/bash

# Script for building and running the example rails blog app.
# The project description asked to set up the rails app in two stages, hence the two Dockerfiles.
# The app can be accessed on the port 3000 of the docker-machine VM.

docker build -f Dockerfile --tag ft-rails:on-build blog
docker build -f Dockerfile_2 --tag rails-test .
docker run --publish 3000:3000 --detach --name rails-server rails-test
