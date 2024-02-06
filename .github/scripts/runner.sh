#!/bin/bash

# The first argument is the path to the .js file
js_file="$1"

# Replace this with your actual testing logic
node "$js_file"

# Check the exit status of the test command and exit accordingly
# Exit with 0 for success, non-zero for failure
if [ $? -eq 0 ]; then
  echo "Test passed for $js_file"
  exit 0
else
  echo "Test failed for $js_file"
  exit 1
fi
