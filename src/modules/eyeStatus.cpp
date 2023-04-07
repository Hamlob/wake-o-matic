#include "eyeStatus.h"

bool eyeStatus::detect(Mat image) {
    std::vector<KeyPoint> keypoints;
    detector->detect(image, keypoints);
    if (keypoints.size() > 0) {
        return true;
    }
    else {
        return false;
    }
}
