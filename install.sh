sudo mkdir -p /var/X
sudo mkdir -p /var/Y
sudo mv server /usr/local/bin/px
sudo cp policy.apparmor /etc/apparmor.d/usr.local.bin.px
