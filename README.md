# asskey
Ascii cli tool to turn images into text.

# Description
This tool takes an image from the web and turns it into text, aka an ascii image.
For example:
```
asskey 40 " .:G#" "https://i.pinimg.com/736x/97/b2/9f/97b29f76e155081f8cfad94c84bf4c7d.jpg"
```

Outputs this:

```
################################################################################
################################::::............::##############################
############################::....................::############################
##########################::..........................GG########################
##########################..::........::::::::..........########################
########################::::::......::::::::::..........::######################
########################::::::::::::::::::::::..........::######################
######################GG::::::......::::::::::::::........######################
######################GGGG::::::........::::::::..........######################
######################GG::::............::::::::::........######################
######################::..::..............::::::::........######################
####################GG......::::..........::::::::::::::::######################
####################GG......::::........::::::::::::::::::GG####################
######################::..::::::::......::::::::::..::::..::####################
######################::..::::::::......::::::::::..::GG..GG####################
######################GG::::::..........::....::....::::::######################
######################GG..::............::......::....::GG######################
######################GG..::....::::..................::########################
######################::..::::::::::..............::::::########################
######################::..::GG::..................::::::GG######################
########################..::::........................::GG######################
########################::::::........................GGGG######################
########################GG..::....................::::::::######################
########################GG......................::::GG::::######################
########################GG..................::::::::::GG::GG####################
########################GG................::::::::::::GG::::####################
##########################::..............::::::::::::::GG::::GG################
################################GG::::....::::::::::::::::::::..::::GG##########
##################################GGGG..::::::::::::::GG::::::::::::::....::####
##################################GGGG..::::::::::::::::GG::::::......::::::::::
####################################GG::..::::::::GG::::GG::::::..............::
##################################GGGGGG..::::::::::::::GG::::::..............::
################################GGGGGG::..::::..::::::::::::::::................
############################GG::GGGGGG::::....::::::::::::::::..................
########################GG::::::::GGGG::::....::::::..........::......::::::....
######################GGGG::::::::GGGGGG....::::::....::::::........::::::::....
####################GG::::::::::::::GGGG::..::::::::::::::::..........::........
##############GG::::::::::::::::::::::::::..::GG::::..........::..::::::......::
############GG::::::..::GGGG::::::::::::::::::::::::....::::::..::::::......::::
####GG::::::::::::....::::::::::::::....::::::::::......::::::::::..........::::
```
# History
In 2025 a legend tasked another legend with downloading an image from the web and turning it into an ascii image. This is the result of that.\
Why is it called asskey? Well it sounds like ascii and its kinda funny :).

# Installation
1. Click the code dropdown and select "download ZIP".
2. Extract the downloaded zip.
3. In the extracted folder rightclick and run install.sh. It will require sudo privileges to copy the files to /usr/local/bin

# Dependencies
Requires python3, python3-pil, imagemagick, curl.\
The script doesnt work try running these in the terminal:
```
sudo apt install python3
sudo apt install python3-pil
sudo apt install imagemagick
sudo apt install curl
```

# Useage
```
asskey width "characters" "http://image/link"
```

## width 
Sets the new horizontal size of the image.\
When the image is downloaded it will be resized to this size.\
Values of around 20-100 work well.

## "Characters"
Sets the characters that will be mapped to each pixel from darkest to brightest.\
E.g if i input '.:TG#' the darkest pixels will be printed as '.' and the brightest as '#'\
Currently only supports 5 characters.\
Must be wrapped in double quotes when input.

## "URL"
This is the URL of the image you want to convert.\
It MUST be wrapped in quotes when input.

# Limitations
 - Currently only tested with .jpgs though sometimes PNGs seem to work.
 - Only allows for 5 characters to be input
 - uuuuh probs has a bunch of bugs hehee

