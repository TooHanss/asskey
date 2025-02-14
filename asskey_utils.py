from PIL import Image
import sys


def img_to_txt(img_path, characters=" .:G#"):
    if len(characters) != 5:
        print("Error: Must input 5 characters.")
        return
    characters = characters[1:5]
    image = Image.open(img_path).convert("L")
    values = list(image.getdata())
    for i in range(image.height):
        line = ""
        for j in range(image.width):
            value = values[j + image.width * i]
            if value <= 51:
                line += characters[0]
                line += characters[0]
                continue
            if value <= 102:
                line += characters[1]
                line += characters[1]
                continue
            if value <= 153:
                line += characters[2]
                line += characters[2]
                continue
            if value <= 204:
                line += characters[3]
                line += characters[3]
                continue
            if value <= 255:
                line += characters[3]
                line += characters[3]
                continue
        print(line)
    print(characters[0])


if __name__ == "__main__":
    img_to_txt(sys.argv[1], str(sys.argv[2]))
    sys.exit(0)
