#!/bin/sh
#Display login, UID and path of each user entry in the /etc/passwd file.
getent passwd | cut -d ':' --fields=1,3,6
