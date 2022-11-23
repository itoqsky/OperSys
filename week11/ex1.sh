sudo fallocate -l 120M lofs.img
DLOOP=$(sudo losetup -f)
sudo losetup ${DLOOP} lofs.img
sudo mkfs.ext4 lofs.img 
sudo mkdir lofsdisk
sudo mount ${DLOOP} lofsdisk