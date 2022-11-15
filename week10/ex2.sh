rm -f ex2.txt
touch ~/Desktop/progm/OperSys/week1/file.txt 
ln ~/Desktop/progm/OperSys/week1/file.txt _ex2.txt >> ex2.txt
i_node=$(ls -i ~/Desktop/progm/OperSys/week1/file.txt | awk '{print $1;}')
find ~/Desktop/progm/OperSys/week1/file.txt -inum $i_node >>ex2.txt
find ~/Desktop/progm/OperSys/week1/file.txt -inum $i_node -exec rm {} \; >> ex2.txt