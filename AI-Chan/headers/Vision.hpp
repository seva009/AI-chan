//experemental
#include <opencv2/opencv.hpp>
#ifndef VISION_H
#define VISION_H

using namespace cv;
using namespace std;

VideoCapture capture(0);
Mat frame;

void chvn()
{
    Mat resized_img;
    string cascade_path = "/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml";
    while (true) {
        capture >> frame;

        // Обработка кадра

        imshow("Video", frame);

        if (waitKey(1) == 27) // Нажатие Esc
        {
            break;
        }
    }
    CascadeClassifier face_cascade;
    face_cascade.load(cascade_path);

    vector<Rect> faces;
    face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
    for (size_t i = 0; i < faces.size(); i++) {
        rectangle(frame, faces[i], Scalar(255, 0, 255), 4);
    }
    resize(frame, resized_img, Size(), 0.5, 0.5);
    imshow("BEBRA228", resized_img);
    waitKey(0);
}

#endif // VISION_H
