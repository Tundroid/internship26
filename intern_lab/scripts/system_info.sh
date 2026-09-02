#!/bin/bash

echo "================================"
echo "       SYSTEM INFORMATION       "
echo "================================"
echo

echo "Username: $(whoami)"
echo "Hostname: $(hostname)"
echo "Current Directory: $(pwd)"
echo "Date/Time: $(date)"
echo "Linux Distribution: $(. /etc/os-release && echo "$PRETTY_NAME")"
echo "Kernel Version: $(uname -r)"
echo "CPU Count: $(nproc)"
echo "Memory: $(free -h | awk '/^Mem:/ {print $3 " used / " $2 " total"}')"
echo "Disk Usage: $(df -h / | awk 'NR==2 {print $3 " used / " $2 " total (" $5 ")"}')"

