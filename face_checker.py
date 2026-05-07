import sys
import cv2

if len(sys.argv) < 2:
    print("Error: No image path provided")
    sys.exit(1)

image_path = sys.argv[1]

try:
    # Load the cascade classifier
    face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

    # Read the image
    img = cv2.imread(image_path)
    if img is None:
        print("Error: Could not read image")
        sys.exit(1)

    # Convert into grayscale
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Detect faces
    faces = face_cascade.detectMultiScale(gray, 1.1, 4)

    if len(faces) > 0:
        print("true")
    else:
        print("false")
except Exception as e:
    print(f"Error: {e}")
    sys.exit(1)
