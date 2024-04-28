#!/bin/bash

spin() {
	printf "\033[1;38;2;255;255;192m"
    local spin="/-\|"
    while :; do
        for i in $(seq 0 3); do
            printf "\r  ${spin:$i:1} Compiling..."
            sleep 0.1
        done
    done
}

spin &
spin_pid=$!
sleep 1
kill $spin_pid 2>/dev/null

printf	"\033[0m"