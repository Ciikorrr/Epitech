#!/bin/bash
cut -d":" -f l | sed -n 2~2p | rev | sort -r | head -n $MY_LINE2 | tail -n +$MY_LINE1 | sed ':x ; N ;ss/\n/, /g ; bx' | sed 'a \.' | sed 'N; s/\n//'   
