#!/bin/bash

echo "Copying files to /usr/local/bin..."
sudo cp asskey.sh /usr/local/bin/asskey
sudo cp asskey_utils.py /usr/local/bin/asskey_utils.py
read -n 1 -s -r -p "Finished installing asskey. Press any key to close the terminal."
