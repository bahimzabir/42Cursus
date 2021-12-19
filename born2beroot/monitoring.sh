#!/bin/bash

wall $'	#Architecture: '$(uname -a) \
$'\n	#CPU physical :'$(nproc) \
$'\n	#vCPU :' $(nproc) \
$'\n	'$(free -m | grep Mem | awk '{printf "#Memory Usage: " $3"/"$2"MB" " (%.2f%%)\n", $2/$3}') \
$'\n	'$(df -h | grep root | awk '{printf "#Disk Usage: %d/%dGB (%s)\n", $3,$2,$5}') \
$'\n	'$(mpstat | grep all | awk '{ printf "#CPU load: " $5"%%\n"}') \
$'\n	'$(who -b | awk '{printf "#Last boot: "$3" "$4"\n"}') \
$'\n	'$(lsblk | grep lvm | awk '{printf "#LVM use: "; if ($1) {printf "yes\n";exit;} else printf "no\n"}') \
$'\n	#Connexions TCP : '$(ss -t | grep :4242 | wc -l)' ESTABLISHED' \
$'\n	#User log:' $(who | wc -l) \
$'\n	#Network:' IP $(hostname -I) $(ip link | grep ether | awk '{printf "("$2")\n" }') \
$'\n	#Sudo :' $(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l) "cmd" \
