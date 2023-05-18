#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <QTableWidget>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QVector>

class ImageProcessor
{
public:
    ImageProcessor();
    QVector<cv::Mat> get_images_from_table(QTableWidget * table);
    bool validate_image_size(QVector<cv::Mat> opencv_images);
    cv::Mat create_spritesheet(int rows, int columns, QVector<cv::Mat> opencv_images);
    void opencv_save_image(cv::Mat opencv_image, QString file_destination);
};

#endif // IMAGEPROCESSOR_H
