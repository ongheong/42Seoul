cat /etc/passwd | sed -e '/^#/d' | awk 'NR%2==0' | cut -f 1 -d':' | rev | sort -r | awk -v a=$FT_LINE1 -v b=$FT_LINE2 'NR>=a && NR<=b' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./' | tr -d '\n'
