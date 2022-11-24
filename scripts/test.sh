#!/bin/bash

echo Try to build the sample application.
echo go build -o ./simple ./simple-yara/*.go
go build -o ./simple ./simple-yara/*.go
