#!/bin/bash

wall "#Architecture : $(uname -a)
#CPU physical : $(lscpu | awk 'NR==9 {print $2}')
#vCPU : $(var=$(lscpu | awk 'NR==7 {print $4}') ; var2=$(lscpu  | awk 'NR==8 {print $4}'); ans=$((var * var2)); echo "$ans")
#Memory Usage : $(free --mega | awk 'NR==2 {printf("%d%c%d%s%s%.2f%c%c",$3,"/",$7,"MB"," (",($3 / $2)*100,"%",")")}')
#Disk Usage : $(df -h --total | awk 'NR==15 {printf "%d%c%d%s %c%d%c%c", $3*1024,"/",$4,"Gb","(",$5,"%",")"}')
#CPU load : $(vmstat 1 2 | awk 'NR==4 {printf("%c%.1f%c%c","(",100-$15,"%",")")}')
#Last boot : $(who -b | awk '{print $3 " " $4}')
#LVM use : $(lsblk | awk '{print $6}' | grep lvm | if [ $(wc -l) > 0 ]
then
        echo "yes"
else
        echo "no"
	fi)
#Connections TCP : $(netstat | grep ESTABLISHED | wc -l) ESTABLISHED
#User log: $(who | awk '{print $1}' | uniq | wc -l)
#Network: IP $(hostname -I) $(ip addr | grep link/ether | awk '{printf("%c%s%c","(",$2,")")}')
#Sudo : $(journalctl -q | grep COMMAND | wc -l) cmd
"
