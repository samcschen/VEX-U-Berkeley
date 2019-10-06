#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;

const int max_value_H = 360/2;
const int max_value = 255;
const String window_capture_name = "Video Capture";
const String window_detection_name = "Object Detection";
const String settings_names = "Settings";

int low_H = 0, low_S = 0, low_V = 0;
int high_H = max_value_H, high_S = max_value, high_V = max_value;

static void on_low_H_thresh_trackbar(int, void *)
{
    low_H = min(high_H-1, low_H);
    setTrackbarPos("Low H", settings_names, low_H);
}

static void on_high_H_thresh_trackbar(int, void *)
{
    high_H = max(high_H, low_H+1);
    setTrackbarPos("High H", settings_names, high_H);
}
static void on_low_S_thresh_trackbar(int, void *)
{
    low_S = min(high_S-1, low_S);
    setTrackbarPos("Low S", settings_names, low_S);
}

static void on_high_S_thresh_trackbar(int, void *)
{
    high_S = max(high_S, low_S+1);
    setTrackbarPos("High S", settings_names, high_S);
}

static void on_low_V_thresh_trackbar(int, void *)
{
    low_V = min(high_V-1, low_V);
    setTrackbarPos("Low V", settings_names, low_V);
}

static void on_high_V_thresh_trackbar(int, void *)
{
    high_V = max(high_V, low_V+1);
    setTrackbarPos("High V", settings_names, high_V);
}

int main(int argc, char* argv[])
{
    VideoCapture cap(-1);
    namedWindow(window_capture_name);
    namedWindow(window_detection_name);
    namedWindow(settings_names);
    // Trackbars to set thresholds for HSV values
    createTrackbar("Low H", settings_names, &low_H, max_value_H, on_low_H_thresh_trackbar);
    createTrackbar("High H", settings_names, &high_H, max_value_H, on_high_H_thresh_trackbar);
    createTrackbar("Low S", settings_names, &low_S, max_value, on_low_S_thresh_trackbar);
    createTrackbar("High S", settings_names, &high_S, max_value, on_high_S_thresh_trackbar);
    createTrackbar("Low V", settings_names, &low_V, max_value, on_low_V_thresh_trackbar);
    createTrackbar("High V", settings_names, &high_V, max_value, on_high_V_thresh_trackbar);
    Mat frame, frame_HSV, frame_threshold, empty;
    while (true) {
        cap >> frame;
        if(frame.empty())
        {
            break;
        }
        // Convert from BGR to HSV colorspace
        cvtColor(frame, frame_HSV, COLOR_BGR2HSV);
        // Detect the object based on HSV Range Values
        inRange(frame_HSV, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), frame_threshold);
        // Show the frames
        imshow(window_capture_name, frame);
        imshow(window_detection_name, frame_threshold);
        char key = (char) waitKey(30);
        if (key == 'q' || key == 27)
        {
            break;
        }
    }
    return 0;
}
