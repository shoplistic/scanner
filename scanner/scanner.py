#!/usr/bin/env python2

# Based on https://www.pyimagesearch.com/2018/05/21/an-opencv-barcode-and-qr-code-scanner-with-zbar/

# import the necessary packages
from imutils.video import VideoStream
from pyzbar import pyzbar
import datetime
import imutils
import time
import cv2
from lib import api
from lib.switch import switch

showWindow = True

# initialize the video stream and allow the camera sensor to warm up
print("[INFO] Starting video stream...")
vs = VideoStream(usePiCamera=True, resolution=(640, 400), framerate=20).start()
time.sleep(2.0)
print("[INFO] Video stream ready")

# loop over the frames from the video stream
while True:

    # Don't bother running the CPU-intensive stuff unless the drawer is open
    if not switch.is_pressed:
        # print('closed')
        time.sleep(0.5)
        continue

    # grab the frame from the threaded video stream and resize it to
    # have a maximum width of 400 pixels

    frame = vs.read()
    frame = imutils.resize(frame, width=400)

    # find the barcodes in the frame and decode each of the barcodes
    barcodes = pyzbar.decode(frame)

    # loop over the detected barcodes
    for barcode in barcodes:
        barcodeData = barcode.data.decode("utf-8")
        barcodeType = barcode.type

        # draw the barcode data and barcode type on the image
        if showWindow:
            (x, y, w, h) = barcode.rect
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)
            text = "{} ({})".format(barcodeData, barcodeType)
            cv2.putText(frame, text, (x, y - 10),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

        # print("Barcode data: " + barcodeData)
        g = api.get(barcodeData)
        if g:
            if api.add(g):
                print(g['display_name'] + ' added')
                time.sleep(1.0)

    # show the output frame
    if showWindow:
        cv2.imshow("Barcode Scanner", frame)

    key = cv2.waitKey(1) & 0xFF

    # if the `q` key was pressed, break from the loop
    # if key == ord("q"):
    #     break


# do a bit of cleanup
print("[INFO] Cleaning up...")
cv2.destroyAllWindows()
vs.stop()
