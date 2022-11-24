#!/bin/bash

echo Try to build the sample application for windows.
echo CC=x86_64-w64-mingw32-gcc GOOS=windows GOARCH=amd64 CGO_ENABLED=1 go build -o ./simple.exe ./simple-yara/*.go
CC=x86_64-w64-mingw32-gcc GOOS=windows GOARCH=amd64 CGO_ENABLED=1 go build -o ./simple.exe ./simple-yara/*.go
