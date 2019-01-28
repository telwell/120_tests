#!/bin/bash
for i in {1..5}
do
    sed '3q;d' t4output1.txt | tr -dc "$i\n" #| awk '{ print length; }'
done
