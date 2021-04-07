#!/bin/sh
cd challenge1
/usr/local/bin/docker-compose up &
cd ../challenge2
/usr/local/bin/docker-compose up &
