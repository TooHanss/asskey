#!/bin/bash
USAGE="$(basename "$0") width \"characters\" \"http://image/link\"

-- This tool takes an image from the web and maps it's pixels to the user's input characters.
The output will be an 'ascii' version on the image.

-- args:

-width 
    Sets the new horizontal size of the image.
    When the image is downloaded it will be resized to this size.
    Values of around 20-100 work well.

-characters 
    Sets the characters that will be mapped to each pixel from darkest to brightest. 
    E.g if i input '.:TG#' the darkest pixels will be printed as '.' and the brightest as '#'
    Currently only supports 5 characters.

-\"http://image/link\"
    This is the URL of the image you want to convert.
    It MUST be wrapped in quotes when input.

E.g: asskey 50 \" .:G#\" \"http://getwallpapers.com/wallpaper/full/7/6/0/1383599-vertical-squidward-wallpaper-2199x1648-tablet.jpg\""

# Check if Python is installed
if ! command -v python3 &> /dev/null; then
    echo "Error: Python3 is not installed. Use sudo apt install python3 to install it."
    exit 1
fi

# Check if PIL (Pillow) is installed in Python
if ! python3 -c "import PIL" &> /dev/null; then
    echo "Error: PIL (Pillow) is not installed. Use sudo apt install python3-pil to install it."
    exit 1
fi

# Help command
if [[ "$1" == "--help" ]]; then
    echo "$USAGE"
    exit 0
fi

# Check if all arguments were input
if [ $# -ne 3 ]; then
    echo "Error: Missing required arguments."
    echo "Usage:  width characters \"URL\""
    echo "Alternatively, type --help for more information."
    exit 1
fi


TMP_IMG_1="/tmp/asskey_img_1.jpg"
TMP_IMG_2="/tmp/asskey_img_2.jpg"
echo $3
wget -O $TMP_IMG_1 $3 
wait
convert $TMP_IMG_1 -resize $1x -colorspace Gray $TMP_IMG_2
python3 utils.py "$TMP_IMG_2" "$2"

rm $TMP_IMG_1
rm $TMP_IMG_2
