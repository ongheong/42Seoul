ifconfig | grep "ether " | sed -e 's/ //g' | cut -c 7-
