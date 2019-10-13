




#!/bin/bash

oldIFS=$IFS


IFS=$'\n'

(find . -type f) > /tmp/temp

for var in `cat /tmp/temp`

do

name=`basename "$var"`

ext=`echo $name | cut -d'.' -f2- | cut -d'.' -f2- | cut -d'.' -f2- | cut -d'.' -f2- | cut -d'.' -f2- | cut -d'.' -f2- | cut -d'.' -f2-`

mkdir -p $ext

mv "$var" $ext/ 2> /dev/null

done

IFS=$oldIFS
