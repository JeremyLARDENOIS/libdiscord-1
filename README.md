### libdiscord
A Discord library written in C.

The goal(s) of this library currently is/are:
* be easy to use

## Building
Currently only tested to work with Ubuntu 17.10.

See `install.sh` for the commands you will have to run

Dependencies: 
* libwebsockets (tested to work with v2.4.1, compiled from source)
* jansson-dev

## Example Bots
### example-ayylmao
Currently this is the only example bot under development. This will be the first working bot using libdiscord, and 
is currently under development.

Responds to every "ayy" with "lmao" in the same channel the "ayy" was sent in.

### example-ping
Under consideration. Will try to roughly measure latencies and response times of various API endpoints, which may include:
* Response time of various REST API endpoints (GET /gateway, DELETE [message], etc)
* Response time of gateway heartbeats
* Response time of REST-gateway event pairs (POST [message] | recieved gateway dispatch for message event, etc)
* Response time to (user defined) third party servers (like a CLI ping tool)

