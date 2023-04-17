#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

/// @brief Class that detect whether the eyes are open or closed. Change the parameters in constructor to fine tune.
class EyeStatus
{
public:

    /** @brief A function that decides whether the eye is open or closed. To do so it looks for an iris (circle) in the picture provided.
     * @param image A picture of an eye. It should only contain the eye, not the whole face.
     * @return True if eye is open (iris is found), false if closed (iris not found).
    */
    bool detect(Mat image);

    /// @brief Constructor is a wrapped for SimpleBlobDetector class by openCV. It sets the paramaters and calls the detector. 
    EyeStatus() {
        // Setup SimpleBlobDetector parameters.
        SimpleBlobDetector::Params params;

        // Change thresholds
        params.minThreshold = 10;
        params.maxThreshold = 200;

        // Filter by Area.
        params.filterByArea = true;
        params.minArea = 150;

        // Filter by Circularity
        params.filterByCircularity = true;
        params.minCircularity = 0.1;

        // Filter by Convexity
        params.filterByConvexity = true;
        params.minConvexity = 0.87;

        // Filter by Inertia
        params.filterByInertia = true;
        params.minInertiaRatio = 0.01;

        #if CV_MAJOR_VERSION < 3   // If you are using OpenCV 2

        // Set up detector with params
        SimpleBlobDetector detector(params);

        // You can use the detector this way
        // detector.detect( im, keypoints);

        #else

        // Set up detector with params
        detector = SimpleBlobDetector::create(params);

        // SimpleBlobDetector::create creates a smart pointer. 
        // So you need to use arrow ( ->) instead of dot ( . )
        // detector->detect( im, keypoints);

        #endif
    }
private:
    Ptr<SimpleBlobDetector> detector;
};

