gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

ttab -w -d "$HOME/Desktop/progm/OperSys/week5/" ./publisher $1 &

for i in $(seq 1 $1)
do
    ttab -w -d "$HOME/Desktop/progm/OperSys/week5/" ./subscriber &
done
