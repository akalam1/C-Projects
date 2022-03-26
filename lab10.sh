#!/bin/bash


#seeting screen to clear
printf "\033c"

#zeroingout files/making
$(> forloop.results)
$(> while.results)

#first cheking number, if its a vaild well move a

#checking whether there is any number provided
if [[ $1 == $null ]];then
   printf "Enter atleast two numbers\n"
    exit 0
fi 

#for assigning values to array b and finding highest number given 

count=$#
k=1
a=$1

b=$2

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







            #finding lcm
           for (( i=$a; i>=$a; i++ ));do
                if (( $(($i % ${b[1]})) == 0 && $(($i % ${b[2]})) == 0 && $(($i % ${b[3]})) == 0 && $(($i % ${b[4]})) == 0 && $(($i % ${b[5]})) == 0 && $(($i % ${b[6]})) == 0 && $(($i % ${b[7]})) == 0 && $(($i % ${b[8]})) == 0 && $(($i % ${b[9]})) == 0 ));then
                    
                   # echo -e "l.c.m = \e[1;34m$i\e[0m"


                    lcm=$i
                    
                    #exit 0 
                    break          
               fi
            done


            printf " L.C.M is: $lcm\n"

            #sending to the files and also creating 

           printf " $lcm " >> forloop.results
         printf " $lcm "  >> while.results










#setting up value for a while loo
# and also running it 1000 times

forloop=1


# recording the start time

starttime_F=$(date "+%s%N")


for forloop in {1..1000}

 

do


       # $1 $2

      

        if [ "$(( $a % $forloop ))" -eq 0 ] 
            then

            printf " $forloop Montclair\n" >> forloop.results
              printf " $forloop Montclair\n"

        elif [ "$(( $b % $forloop ))" -eq 0 ]

        then


            printf " $forloop State\n" >> forloop.results
             printf " $forloop State\n"

        elif [ "$(( $lcm % $forloop ))" -eq 0 ]

        then

            printf " $forloop Montclair state\n" >> forloop.results
            printf " $forloop Montclair state\n"

        else
            printf " $forloop NONE\n" >> forloop.results

            fi

done 

# its recording the end time 

endtime_F=$(date "+%s%N")

# also total time 

totalTime_F="$(( $endtime_F - $starttime_F)) "


printf "$starttime_F" >> forloop.results
 printf "$endtime_F" >> forloop.results

printf " $totalTime_F" >> forloop.results

printf " The total time For loop took was: $totalTime_F\n"






# setting up while loop
#while loop


#printf "while loop\n\n"

counter_W=1


#start time
starttime_W=$(date "+%s%N")

while [[ $counter_W -le 1000 ]]; 
do

 # $1 $2

        if [ "$(( $a % $counter_W ))" -eq 0 ]
            then

            printf " $counter_W Montclair\n" >> while.results
             printf "  $counter_W Montclair\n"

        elif [ "$(( $b % $counter_W ))" -eq 0 ]

        then


            printf " $counter_W State\n" >> while.results
             printf " $counter_W State\n"

        elif [ "$(( $lcm % $counter_W ))" -eq 0 ]

        then

            printf " $counter_W Montclair state\n" >> while.results

             printf " $counter_W Montclair state\n"

        else
            printf " $counter_W NONE\n" >> while.results
fi

(( counter_W+= 1))

done

#end time
endtime_W=$(date "+%s%N")

totalTime_W="$(($endtime_W - $starttime_W))"

#sending data to the files
printf "$starttime_W\n" >> while.results

 printf "$endtime_W\n" >> while.results

printf " $totalTime_W\n" >> while.results

printf "The total time while loop took was: $totalTime_W\n" 




#in this we are finding which one took more time displaying message

if [ $totalTime_F -gt $totalTime_W ]
then
printf " while loop was faster\n"

difference="$(($totalTime_F - $totalTime_W))"

printf " Time Differed: $difference\n"

else 

printf  "For loop was faster\n"

difference="$(($totalTime_W - $totalTime_F))"
printf " Time Differed: $difference\n"

fi


#this  message for the user

printf "Files can veiw here\n"

#this greping files for the user

echo `ls | grep results`




