#!/bin/bash

# strict error handling
set -o pipefail  # trace ERR through pipes
set -o errtrace  # trace ERR through 'time command' and other functions
set -o nounset   # set -u : exit the script if you try to use an uninitialised variable
set -o errexit   # set -e : exit the script if any statement returns a non-true return value

echo "Building Java XML processing examples."

rm -rf bin
mkdir bin
cd src
rm -f *.class
javac *.java
mv *.class ../bin

echo "Finished building Java XML processing examples."