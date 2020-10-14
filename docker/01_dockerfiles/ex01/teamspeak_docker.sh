#!/bin/bash

# Script for building and running a container for a Teamspeak server.
# After the configuration has finished, the server can be connected to
# via the Teamspeak 3 client, using the docker-machine VM's ip and the port that was mapped to 9987.

docker build --tag teamspeak .
docker run -P -d --name teamspeak-server teamspeak

