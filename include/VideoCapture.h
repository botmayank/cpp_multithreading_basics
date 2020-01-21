#ifndef V4L2_CAP_H
#define V4L2_CAP_H

#include <string>
#include <linux/videodev2.h>

class VideoCapture {
    public:

    private:
        std::string device_path;
        int fd;
        size_t width, height;

        struct v4l2_format format;
        struct v4l2_requestbuffers creqbuf;
        struct v4l2_buffer cfilledbuffer;


};


#endif //V4L2_CAP_H