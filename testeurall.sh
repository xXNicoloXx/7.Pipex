#!/bin/bash
while true
do
    ./pipex Makefile "rm -rf outfile" ls outfile && cat outfile | wc -l >> test && sleep 0.2
done