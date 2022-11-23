lofs=$HOME/lofsdisk
sudo mkdir -p $lofs
echo "Ikram" > $lofs/file1
echo "Kamat" > $lofs/file2
sudo chmod 777 $lofs
sudo mkdir -p -v $lofs/{bin,usr/{lib,lib64},lib}
sudo cp -v /bin/{bash,cat,echo,ls} $lofs/bin

cmnds=("bash" "cat" "echo" "ls")
for i in $cmnds;
do
	libs="$(ldd /bin/"$i" | grep -Eo '/lib.*\.[0-9]')"
	for j in $libs; 
	do 
		sudo cp -v "$j" "${lofs}${j}"; 
		sudo cp -v "/usr$j" "${lofs}/usr${j}";
	done
done

sudo gcc ex2.c -o ex2.out
sudo cp -v ./ex2.out $lofs/
sudo chroot $lofs ./ex2.out > ex2.txt
./ex2.out >> ex2.txt