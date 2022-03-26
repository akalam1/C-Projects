#!/bin/bash

#first cheking number, if its a vvaild well move ag

#checking whether there is any number provided
if [[ $1 == $null ]];then
    echo -e "\e[1;31 Two numbers needed!!\e[0m"
    exit 0
fi 

#for assigning values to array b and finding highest number given 





count=$#
k=1
a=$1
while [[ $# -gt 0 ]];do
    if [[ $1 > $2 ]];then
         a=$1
    fi
b[$k]=$1
k=$k+1
shift
done

#putting values to other positional parameters 
lcm=0
for (( c=9; c>$count; c-- ));do
    b[$c]=1
done 




#divisible
count=2;

if [ $(($count % 2)) == 0 ]; then
    printf "even number";
else
    printf "odd number";
fi




#echo $1 $2
# Initialize the counter
n=1
# Iterate the loop for 5 times
while [ $n -le 1000 ]
do


            #finding lcm
           for (( i=$a; i>=$a; i++ ));do
                if (( $(($i % ${b[1]})) == 0 && $(($i % ${b[2]})) == 0 && $(($i % ${b[3]})) == 0 && $(($i % ${b[4]})) == 0 && $(($i % ${b[5]})) == 0 && $(($i % ${b[6]})) == 0 && $(($i % ${b[7]})) == 0 && $(($i % ${b[8]})) == 0 && $(($i % ${b[9]})) == 0 ));then
                    
                    echo -e "l.c.m = \e[1;34m$i\e[0m"
                    exit 0 
                    break          
               fi
            done

echo "Running $n time"
    # Increment the value of n by 1
    (( n++ ))
done
