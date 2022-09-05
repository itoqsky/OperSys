date
sleep 3
mkdir root
date
sleep 3
touch root/root.txt
date
sleep 3
mkdir home
date
sleep 3
touch home/home.txt
ls -ltr / > root/root.txt
ls -ltr ~ > home/home.txt
cat root/root.txt
cat home/home.txt
ls root
ls home
